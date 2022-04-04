//**************************************************
// \file  CaliceRunAction.cc
// \brief: Implementation of 
//         CaliceRunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 20 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceRunAction.hh"
#include "CaliceEventAction.hh"

//Includers from Geant4
//
#include "g4root.hh"
#include "G4UImanager.hh"
#include "G4VVisManager.hh"
#include "G4NistManager.hh"
#include "G4Element.hh"
#include "G4EmCalculator.hh"
#include "G4UnitsTable.hh"
#include "G4NistManager.hh"
#include "G4ParticleDefinition.hh"

//Constructor definition
//
CaliceRunAction::CaliceRunAction(G4String listname, CaliceEventAction* evtaction )
    : fEventAction(evtaction) {
    fPhysList = listname;

    //Instantiate analysis manager
    //
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance(); //using ROOT
    analysisManager->SetVerboseLevel( 1 );
    //analysisManager->SetNtupleMerging( 1 );    

    analysisManager->CreateNtuple("tree", "tree");
    analysisManager->CreateNtupleIColumn("isInteraction");
    analysisManager->CreateNtupleIColumn("firstInteractionLayer");
    analysisManager->CreateNtupleIColumn("nhits");
    analysisManager->CreateNtupleIColumn("MCfirstInteractionLayer");
    //analysisManager->CreateNtupleDColumn("elayer", fEventAction->Getelayer() );
    //analysisManager->CreateNtupleIColumn("hitslayer", fEventAction->Gethitslayer() );

    analysisManager->CreateNtupleDColumn("elayer0");
    analysisManager->CreateNtupleDColumn("elayer1");
    analysisManager->CreateNtupleDColumn("elayer2");
    analysisManager->CreateNtupleDColumn("elayer3");
    analysisManager->CreateNtupleDColumn("elayer4");
    analysisManager->CreateNtupleDColumn("elayer5");
    analysisManager->CreateNtupleDColumn("elayer6");
    analysisManager->CreateNtupleDColumn("elayer7");
    analysisManager->CreateNtupleDColumn("elayer8");
    analysisManager->CreateNtupleDColumn("elayer9");
    analysisManager->CreateNtupleDColumn("elayer10");
    analysisManager->CreateNtupleDColumn("elayer11");
    analysisManager->CreateNtupleDColumn("elayer12");
    analysisManager->CreateNtupleDColumn("elayer13");
    analysisManager->CreateNtupleDColumn("elayer14");
    analysisManager->CreateNtupleDColumn("elayer15");
    analysisManager->CreateNtupleDColumn("elayer16");
    analysisManager->CreateNtupleDColumn("elayer17");
    analysisManager->CreateNtupleDColumn("elayer18");
    analysisManager->CreateNtupleDColumn("elayer19");
    analysisManager->CreateNtupleDColumn("elayer20");
    analysisManager->CreateNtupleDColumn("elayer21");
    analysisManager->CreateNtupleDColumn("elayer22");
    analysisManager->CreateNtupleDColumn("elayer23");
    analysisManager->CreateNtupleDColumn("elayer24");
    analysisManager->CreateNtupleDColumn("elayer25");
    analysisManager->CreateNtupleDColumn("elayer26");
    analysisManager->CreateNtupleDColumn("elayer27");
    analysisManager->CreateNtupleDColumn("elayer28");
    analysisManager->CreateNtupleDColumn("elayer29");
    
    analysisManager->CreateNtupleIColumn("hitslayer");
    analysisManager->FinishNtuple();

}

//Deconstructor definition
//
CaliceRunAction::~CaliceRunAction() {
    
    //Delete G4AnalysisManager
    //
    delete G4AnalysisManager::Instance();

}

//BeginOfRunAction definition
//
void CaliceRunAction::BeginOfRunAction(const G4Run* /*aRun*/) {
    
    //G4int id = aRun->GetRunID();
    //G4cout << "-->CALICESiWTB::CaliceRunAction: Run starts now !" << G4endl; //tell me you alive
    
    //Inform G4AnalysisManager out outputfile
    //
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    //std::string runnumber = std::to_string( aRun->GetRunID() );
    //G4String outputfile = "CALICESiWTBout_Run"+runnumber;
    G4String outputfile = fPhysList; 
    analysisManager->OpenFile( outputfile );

}

//EndOfRunAction definition
//
void CaliceRunAction::EndOfRunAction(const G4Run*) {
  
    //G4cout << "-->CALICESiWTB::CaliceRunAction Run ends now !" << G4endl; //tell me you alive again

    //Inform G4AnalysisManager its time to end
    //
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();

}

//**************************************************
