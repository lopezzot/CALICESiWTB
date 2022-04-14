##**************************************************
## \file parser.py
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

from gts.utils import getJSON
from gts.BaseParser import BaseParser, mergeROOT, mktempdir

def GetObservables(filename):
    with open(filename) as f:
	line = f.readline()
    listline = line.split()
    listfloat = [float(x) for x in listline]
    return listfloat

def GetDataObservables(filename):
    with open(filename) as f:
	line = f.readlines()
    listline = line[0].split()
    listfloat = [float(x) for x in listline]
    listlineerror = line[1].split()
    listfloaterror = [float(x) for x in listlineerror]
    return listfloat, listfloaterror

class Test(BaseParser):
    TEST = "CALICESiWTB"
    IGNOREKEYS = ["ENERGY"] 
    

    def parse(self, jobs):
	ordenergies = [2,4,6,8,10]
	
	common_data = []
	common_json = []

	xpseudolayer_values = [x for x in range(0,53)]    
        xlayer_values = [x for x in range(0,23)]    
	ystaterrorMC_pseudolayer = [0. for x in range(0,53)]
	ystaterrorMC_layer = [0. for x in range(0,23)]
	
	#Prepare jobs for analysis
	#
	energies = [float(x["ENERGY"]) for x in jobs]
	files = [os.path.join(x["path"],"CALICESiWTBout.root") for x in jobs]
	print "Found "+ str(len(jobs)) + " jobs with energies (GeV): " + str(energies) + " ,physlist: " + str(set([x["PHYSLIST"] for x in jobs]))
	#longitudinal profiles analysis
	#
	print "Running longitudinal profiles analysis"
	for counter,energy in enumerate(ordenergies):
	    #Find job with corresponding energy
	    job = [x for x in jobs if int(x["ENERGY"])==energy][0]
	    path = job["path"]
	    #infile = TFile.Open(os.path.join(job["path"],"CALICESiWTBout.root"))
	    root_command = "cd " + job["path"] + ";root -l 'MyLongitudinalPlots.C(" + str(counter) + "," + "\"CALICESiWTBout.root\")'"
	    #print root_command
	    #os.system(root_command)
	    yenergy_values = GetObservables(path+"/"+str(energy)+"GeVenergy.txt")
	    yhit_values = GetObservables(path+"/"+str(energy)+"GeVhit.txt")
	    print "--->energy values: " + str(yenergy_values) + " ,physlist: " + str(set([x["PHYSLIST"] for x in jobs]))
	    print "--->hit values: " + str(yhit_values) + " ,physlist: " + str(set([x["PHYSLIST"] for x in jobs]))
            
	    #Create JSON output files for energy (graph)
	    #
	    yield getJSON(jobs[0], "chart",
		                  mctool_name="GEANT4",
		                  mctool_model=jobs[0]["PHYSLIST"],
			          observableName="energy per layer",
			          #secondaryParticle="e-",
				  beamParticle=job["PARTICLE"],
				  targetName="CALICE-SiW",
				  beamEnergies=energy,
                                  title="Energy per layer (pi-)",
                                  xAxisName="Shower depth [pseudolayer]",
                                  yAxisName="Erec/pseudolayer [MIP]",
                                  xValues=xpseudolayer_values,
                                  yValues=yenergy_values,
	                          yStatErrorsMinus=ystaterrorMC_pseudolayer,
				  yStatErrorsPlus=ystaterrorMC_pseudolayer
                                  )
	    #Create JSON output files for hit (graph)
	    #
	    yield getJSON(jobs[0], "chart",
		                  mctool_name="GEANT4",
		                  mctool_model=jobs[0]["PHYSLIST"],
			          observableName="hit per layer",
			          #secondaryParticle="e-",
				  beamParticle=job["PARTICLE"],
				  targetName="CALICE-SiW",
				  beamEnergies=energy,
                                  title="Hit per layer (pi-)",
                                  xAxisName="Shower depth [layer]",
                                  yAxisName="Entries (normalised to unity)",
                                  xValues=xlayer_values,
                                  yValues=yhit_values,
	                          yStatErrorsMinus=ystaterrorMC_layer,
				  yStatErrorsPlus=ystaterrorMC_layer
                                  )
           
	    #Part for data json creation (extract FTFP_BERT phys list jobs)
	    '''
	    if str(jobs[0]["PHYSLIST"])=="FTFP_BERT":
		y_energy_data, y_energy_data_error = GetDataObservables(path+"/"+str(energy)+"GeVenergydata.txt")
		y_hit_data, y_hit_data_error = GetDataObservables(path+"/"+str(energy)+"GeVhitdata.txt")
		
		#Create JSON output files for energy (graph)
		#
		yield getJSON(jobs[0], "chart",
		                      mctool_name="experiment",
			              mctool_model="experiment",
				      mctool_version="experiment",
				      testName="experiment",
			              observableName="energy per layer",
				      #secondaryParticle="e-",
				      beamParticle="pi-",
				      targetName="CALICE-SiW",
			    	      beamEnergies=energy,
                                      title="Energy per layer (pi-)",
                                      xAxisName="Shower depth [pseudolayer]",
                                      yAxisName="Erec/pseudolayer [MIP]",
                                      xValues=xpseudolayer_values,
                                      yValues=y_energy_data,
	                              yStatErrorsMinus=y_energy_data_error,
				      yStatErrorsPlus=y_energy_data_error
                                      )
		#Create JSON output files for hit (graph)
		#
		yield getJSON(jobs[0], "chart",
		                      mctool_name="experiment",
			              mctool_model="experiment",
				      mctool_version="experiment",
				      testName="experiment",
			              observableName="hit per layer",
				      #secondaryParticle="e-",
				      beamParticle="pi-",
				      targetName="CALICE-SiW",
				      beamEnergies=energy,
                                      title="Hit per layer (pi-)",
                                      xAxisName="Shower depth [layer]",
                                      yAxisName="Entries (normalised to unity)",
                                      xValues=xlayer_values,
                                      yValues=y_hit_data,
	                              yStatErrorsMinus=y_hit_data_error,
				      yStatErrorsPlus=y_hit_data_error
                                      )
	    ''' 
##**************************************************
