import os

#physListNames = ['FTFP_BERT','FTFP_BERT_HP','QGSP_BERT','QBBC']
physListNames = ['FTFP_BERT']
beamEnergies=[2,4,6,8,10]

for iName in physListNames:
  for iEnergy in beamEnergies:
      cmd="./CALICESiWTB run_pi-_%iGeV.mac %s"%(iEnergy,iName)
      os.system(cmd)

