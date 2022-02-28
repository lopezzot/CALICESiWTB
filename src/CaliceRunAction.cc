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
#include "CaliceAnalysisManager.hh"
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
    auto analysisManager = G4AnalysisManager::Instance(); //using ROOT
    analysisManager->SetVerboseLevel( 1 );
    analysisManager->SetNtupleMerging( 1 );    

    analysisManager->CreateNtuple("CALICESiWTBout", "tree");
    analysisManager->CreateNtupleIColumn("isInteraction");
    analysisManager->CreateNtupleIColumn("firstInteractionLayer");
    analysisManager->CreateNtupleIColumn("nhits");
    analysisManager->CreateNtupleDColumn("elayer", fEventAction->Getelayer() );
    analysisManager->CreateNtupleDColumn("hitslayer", fEventAction->Gethitslayer() );
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
void CaliceRunAction::BeginOfRunAction(const G4Run* aRun) {
    
    //G4int id = aRun->GetRunID();
    G4cout << "-->CALICESiWTB::CaliceRunAction: Run starts now !" << G4endl; //tell me you alive
    
    //Get CaliceAnalysisManager (the one and only)
    //Set root output file name, book tree and set beam energy in CaliceAnalysisManager
    //
    (CaliceAnalysisManager::GetPointer())->BeginOfRun(fPhysList);

    //Inform G4AnalysisManager out outputfile
    //
    auto analysisManager = G4AnalysisManager::Instance();
    //std::string runnumber = std::to_string( aRun->GetRunID() );
    //G4String outputfile = "CALICESiWTBout_Run"+runnumber;
    G4String outputfile = "CALICESiWTBout";
    //G4String outputfile = fPhysList; 
    analysisManager->OpenFile( outputfile );

}

//EndOfRunAction definition
//
void CaliceRunAction::EndOfRunAction(const G4Run*) {
  
    G4cout << "-->CALICESiWTB::CaliceRunAction Run ends now !" << G4endl; //tell me you alive again
    //Get CaliceAnalysisManager (the one and only)
    //Write root output file and close it
    //
    CaliceAnalysisManager::GetPointer()->EndOfRun();

    //Inform G4AnalysisManager its time to end
    //
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();

}

//**************************************************
