//**************************************************
// \file  CaliceDetectorConstruction.cc
// \brief: Implementation of 
//         CaliceDetectorConstruction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceDetectorConstruction.hh"
#include "CaliceAnalysisManager.hh"
#include "CalicePrimaryGeneratorAction.hh"

//Includers from Geant4
//
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4Neutron.hh"
#include "G4Proton.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"
#include "G4Gamma.hh"
#include "G4Track.hh"
//#include "G4TransportationManager.hh"
//#include "G4Box.hh"
#include "G4RunManager.hh"

//Includers from ROOT
//
#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TH2D.h>

//Includers from C++
//
#include <string>

CaliceAnalysisManager* CaliceAnalysisManager::fManager = 0;      //the one and only!

CaliceAnalysisManager* CaliceAnalysisManager::GetPointer() {     //how to get the one and only!
    
    if(!fManager) fManager = new CaliceAnalysisManager;
    return fManager;

}

CaliceAnalysisManager::CaliceAnalysisManager() {                 //the one and only creates itself!
  //TSystem ts;
  //gSystem->Load("libCaliceClassesDict");

  verbose = 0;
  n_evt   = -1;
  primaryParticleId = 0;
  beamEnergy = 0.;
  nLayers = numberOfLayers;
  totEdep = 0.;
}

CaliceAnalysisManager::~CaliceAnalysisManager() {                //but anyone can kill it!
    
    if ( fOutputFile ) delete fOutputFile;

}

//bookAnalysisTree definition
//
void CaliceAnalysisManager::bookAnalysisTree() { 

    if ( !fOutputFile ) fOutputFile = NULL;
    fOutputFile = new TFile(filename.c_str(),"RECREATE");

    tree = new TTree( "tree", "SiWCalo Tree" );
    //  tree->SetMaxTreeSize( Long64_t(2e+12) );
    tree->Branch( "particleID",       &primaryParticleId,     "particleID/I" );
    tree->Branch( "beamEnergy", &beamEnergy,         "beamEnergy/D" );
    tree->Branch( "nLayers",  &nLayers, "nLayers/I" );
    tree->Branch( "numberOfMCparticles", &numberOfMCparticles, "numberOfMCparticles/I" );
    tree->Branch( "firstInteractionLayer", &firstInteractionLayer, "firstInteractionLayer/I" );
    tree->Branch( "MClayer", &MClayer, "MClayer/I" );
    tree->Branch( "isInteraction", &isInteraction, "isInteraction/O" );
 
    //Information on individual hits
    //
    tree->Branch( "nhits", &nhits, "nhits/I" );
    tree->Branch( "posx", &posx, "posx[nhits]/F" );
    tree->Branch( "posy", &posy, "posy[nhits]/F" );
    tree->Branch( "posz", &posz, "posz[nhits]/F" );
    tree->Branch( "hitslayer", &hitslayer, "hitslayer[nLayers]/I" );
    tree->Branch( "elayer", &elayer, "elayer[nLayers]/F" );
    tree->Branch( "totEdep", &totEdep, "totEdep/F" );
    tree->Branch( "energy", &energy, "energy[nhits]/F" );
    tree->Branch( "layer", &layer, "layer[nhits]/I" );
    //  tree->Branch( "hitPadX", &hitPadX );
    //  tree->Branch( "hitPadY", &hitPadY );

    //Histograms definition
    //
    h_xProfile = new TH1D("h_xProfile","Shower profile vs X",100,-100,100);
    h_yProfile = new TH1D("h_yProfile","Shower profile vs Y",100,-100,100);
    h_zProfile = new TH1D("h_zProfile","Shower profile vs Z",100,1300,1500);
    h_longitudinalHits = new TH1I("h_longitudinalHits","longitudinal hit distribution",30,0,30);
    h_longitudinalE = new TH1F("h_longitudinalE","longitudinal hit distribution",30,0,30);
    h_energyPerHit = new TH1D("h_energyPerHit","energy per hit",100,0,20);
    h_energyPerEvent = new TH1D("h_energyPerEvent","energy per event",100,0,50);
    //h_EoverR = new TH2D("h_EoverR","deposited Energy [MIP] over distance from shower center",50,0,100,22,0,22);

}

//BeginOfRun definition
//
void CaliceAnalysisManager::BeginOfRun(G4String filename) {

    SetOutputFile(filename);

    //numberOfMCparticles = G4RunManager::GetRunManager()->GetNumberOfEventsToBeProcessed();
 
    n_evt   = 0;

    bookAnalysisTree();
    SetBeamEnergy(fParticleEnergy);
    //  if(verbose > 0) 
    G4cout << "-->CALCIESiWTB::CaliceAnalysisManager: Output file created"<<G4endl;

}

//EndOfRun definition
//
void CaliceAnalysisManager::EndOfRun() {

  fOutputFile->Write();
  fOutputFile->Close();
  G4cout << "-->CALICESiWTB::CaliceAnalysisManager: Output file written and closed" << G4endl;

}

//BeginOfEvent definition
//
void CaliceAnalysisManager::BeginOfEvent() {
    
    /* hitPadX->clear();
    hitPadY->clear();*/
    firstInteractionLayer = -1;
    MClayer = -1;
    isInteraction = false;
    totEdep = 0;
    for (int iLayer=0; iLayer<nLayers; iLayer++) {
        elayer[iLayer] = 0;
        hitslayer[iLayer] = 0;
    }

}

//EndOfEvent definition
//
void CaliceAnalysisManager::EndOfEvent() {

    n_evt++;
    tree->Fill();

}

//SetOutputFile definition
//
void CaliceAnalysisManager::SetOutputFile(G4String name) {filename = name;}

//SetPhysList definition
//
void CaliceAnalysisManager::SetPhysList(G4String listname) {fPhysListName = listname;}
/*
//Write definition
//
void CaliceAnalysisManager::Write(std::vector<CaliceCalorimeterHit*>* hcont) {
    
    //fNevents++;
    n_evt++;

    std::ostringstream os;
    os << n_evt;
    std::string stevt = "Event_" + os.str();
    const char* chevt = stevt.c_str();

    fOutputFile->WriteObject(hcont, chevt);

}
*/
//SetBeamEnergy definition
//
void CaliceAnalysisManager::SetBeamEnergy(G4double val) {beamEnergy = val;}

//SetVerbose definition
//
void CaliceAnalysisManager::SetVerbose(G4int val) {verbose = val;}

//GetVerbose definition
//
G4int CaliceAnalysisManager::GetVerbose() const {return verbose;}

//**************************************************

