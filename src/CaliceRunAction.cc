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
//#include "CaliceAnalysisManager.hh"

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
    G4cout << "-->CALICESiWTB: Run starts now !" << G4endl;
    //(CaliceAnalysisManager::GetPointer())->BeginOfRun(fPhysList);

}

//EndOfRunAction definition
//
void CaliceRunAction::EndOfRunAction(const G4Run*) {
  
    G4cout << "-->CALICESiWTB: Run ends now !" << G4endl;
    //CaliceAnalysisManager::GetPointer()->EndOfRun();

}

//**************************************************
