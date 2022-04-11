##**************************************************
## \file  parser.py
## \brief: Implementation of CALICESiWTB parser
##         for geant-val usage
## \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
##          @lopezzot
## \start date: 11 April 2021
##**************************************************

#!/usr/bin/env python

import os
import sys
import json
import numpy as np

from ROOT import gROOT, TFile, TTree, TCanvas, gStyle
from ROOT import TH1F, TF1
from gts.utils import getJSON
from gts.BaseParser import BaseParser, mergeROOT, mktempdir

class Test(BaseParser):
    TEST = "CALICESiWTB"
    IGNOREKEYS = ["ENERGY"] 
    
    def parse(self, jobs):
	penergies = [2.,4.,6.,8.,10]
	
	common_data = []
	common_json = []

	#Prepare jobs for analysis
	#
	pijobs = [x for x in jobs if x["PARTICLE"]=="pi-"]
	pienergies = [float(x["ENERGY"]) for x in pijobs]
	pifiles = [os.path.join(x["path"],"ATLHECTBout_Run0.root") for x in ectrjobs]
	print "Found "+str(len(jobs))+" runs in jobs:"
	print "--->"+ str(len(ectrjobs)) + " jobs with e-, energies (GeV): " + str(ectrenergies) + " ,physlist: " + str(set([x["PHYSLIST"] for x in ectrjobs]))
	#print "------> files: ", ectrfiles
	print "--->"+ str(len(pijobs)) + " jobs with pi-, energies (GeV): " + str(pienergies) + " ,physlist: " + str(set([x["PHYSLIST"] for x in pijobs]))
	#print "------> files: ", pifiles

	#e- analysis
	#
	print "Running e- analysis"
	sampfractions = []
	ersampfractions = []
	resolutions = []
	erresolutions = []
	for energy in eenergies:
	    #Find e- job with corresponding energy
	    job = [x for x in ectrjobs if float(x["ENERGY"])==energy][0]
	    infile = TFile.Open(os.path.join(job["path"],"ATLHECTBout_Run0.root"))
	    tree = infile.Get("ATLHECTBout")
	    H1sampfraction = TH1F("e-","e-",1000,0.,100.)
	    for evt in tree:
		H1sampfraction.Fill(evt.elAr/(energy*1000)*100) #percent value
	    sampfractions.append(H1sampfraction.GetMean())
	    ersampfractions.append(H1sampfraction.GetMeanError())
	print "--->e- sampling fraction: " + str(sampfractions) + " ,physlist: " + str(set([x["PHYSLIST"] for x in ectrjobs]))
	print "--->e- avg sampling fraction: " + str(np.mean(sampfractions)) + "%" + " ,physlist: " + str(set([x["PHYSLIST"] for x in ectrjobs]))
	outfile = TFile.Open("OUTe-.root","RECREATE")
	for energy in eenergies:
	    #Find e- job with corresponding energy
	    job = [x for x in ectrjobs if float(x["ENERGY"])==energy][0]
	    infile = TFile.Open(os.path.join(job["path"],"ATLHECTBout_Run0.root"))
	    tree = infile.Get("ATLHECTBout")
	    recenergy = TH1F("e-"+str(energy), "e-"+str(energy), 2000, 0., 200.)
	    for evt in tree:
		addchannel = 0
		addchannel += evt.M2L1BirkeLayer[2]
		addchannel += evt.M2L1BirkeLayer[3]
		addchannel += evt.M2L1BirkeLayer[5]
		addchannel += evt.M2L2BirkeLayer[3]
		addchannel += evt.M2L2BirkeLayer[5]
		addchannel += evt.M3L1BirkeLayer[3]
		addchannel += evt.M3L2BirkeLayer[5]
		recenergy.Fill(addchannel/(10.*np.mean(sampfractions)))
	    xfitmin = recenergy.GetXaxis().GetBinCenter(recenergy.GetMaximumBin())-1.0*recenergy.GetStdDev();
	    xfitmax = recenergy.GetXaxis().GetBinCenter(recenergy.GetMaximumBin())+1.0*recenergy.GetStdDev();
	    F1recenergy = TF1("gaus","gaus(0)",xfitmin,xfitmax)
	    recenergy.Fit( F1recenergy ,"QR")
	    res =(recenergy.GetFunction("gaus").GetParameter(2)/energy)*(energy**(0.5))*100. #percent
	    resolutions.append(res)
	    erres = (recenergy.GetFunction("gaus").GetParError(2)/
		     recenergy.GetFunction("gaus").GetParameter(2))*res
	    erresolutions.append(erres)
	    outfile.cd()
	    recenergy.Write()
	print "--->e- sampling terms in resolution: " + str(resolutions) + " %GeV^{1/2}" + " ,physlist: " + str(set([x["PHYSLIST"] for x in ectrjobs]))
	print "--->e- avg sampling term in resolution: " + str(np.mean(resolutions)) + " %GeV^{1/2}" + " ,physlist: " + str(set([x["PHYSLIST"] for x in ectrjobs]))

        #Create JSON output files for e- energy resolution (graph)
        #
	yield getJSON(jobs[0], "chart",
                              mctool_name="GEANT4",
                              mctool_model=jobs[0]["PHYSLIST"],
                              observableName="energy resolution",
			      #secondaryParticle="e-",
                              beamParticle=job["PARTICLE"],
			      targetName="ATLAS-HEC",
                              beamEnergies=eenergies,
                              title="energyresolution(e-)",
                              xAxisName="<E_{Beam}> [GeV]",
                              yAxisName="#sigma_{0}/E_{0} #sqrt{E_{Beam}} [% #sqrt{GeV}]",
                              xValues=eenergies,
                              yValues=resolutions,
	                      yStatErrorsMinus=erresolutions,
			      yStatErrorsPlus=erresolutions
                              )

        #Create JSON output files for e- sampling fraction (graph)
        #
	yield getJSON(jobs[0], "chart",
                              mctool_name="GEANT4",
                              mctool_model=jobs[0]["PHYSLIST"],
                              observableName="sampling fraction",
			      #secondaryParticle="e-",
                              beamParticle=job["PARTICLE"],
			      targetName="ATLAS-HEC",
                              beamEnergies=eenergies,
                              title="samplingfraction(e-)",
                              xAxisName="<E_{Beam}> [GeV]",
                              yAxisName="[%]",
                              xValues=eenergies,
                              yValues=sampfractions,
	                      yStatErrorsMinus=ersampfractions,
			      yStatErrorsPlus=ersampfractions
                              )
        
##**************************************************
