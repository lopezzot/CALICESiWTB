//**************************************************
// \file CaliceSteppingAction.cc
// \brief: Implementation of CaliceSteppingAction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 March 2022
//**************************************************

//Includers from project files
//
#include "CaliceSteppingAction.hh"

//Includers from Geant4
//
#include "G4Step.hh"

//Definition of constructor
//
CaliceSteppingAction::CaliceSteppingAction( ) : G4UserSteppingAction() {

}

//Definition of deconstructor
//
CaliceSteppingAction::~CaliceSteppingAction(){}

//Definition of UserSteppingAction() method
//
void CaliceSteppingAction::UserSteppingAction( const G4Step* aStep ){
    
    if ( aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName() == "TerminatingAbsorber0" ){
       
        aStep->GetTrack()->SetTrackStatus( fStopAndKill );
        G4cout<<"killed"<<G4endl;

    }

}

//**************************************************
