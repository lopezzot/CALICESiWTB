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

//Includers from Geant4
//
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
CaliceRunAction::CaliceRunAction(G4String listname) {
    fPhysList = listname;
}

//Deconstructor definition
//
CaliceRunAction::~CaliceRunAction() {}

//BeginOfRunAction definition
//
void CaliceRunAction::BeginOfRunAction(const G4Run* aRun) {
    
    //G4int id = aRun->GetRunID();
    G4cout << "-->CALICESiWTB::CaliceRunAction: Run starts now !" << G4endl; //tell me you alive
    
    //Get CaliceAnalysisManager (the one and only)
    //Set root output file name, book tree and set beam energy in CaliceAnalysisManager
    //
    (CaliceAnalysisManager::GetPointer())->BeginOfRun(fPhysList);

}

//EndOfRunAction definition
//
void CaliceRunAction::EndOfRunAction(const G4Run*) {
  
    G4cout << "-->CALICESiWTB::CaliceRunAction Run ends now !" << G4endl; //tell me you alive again
    //Get CaliceAnalysisManager (the one and only)
    //Write root output file and close it
    //
    CaliceAnalysisManager::GetPointer()->EndOfRun();

}

//**************************************************
