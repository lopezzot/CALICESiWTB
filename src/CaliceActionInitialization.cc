//**************************************************
// \file CaliceActionInitialization.cc
// \brief: implementation of
// CaliceActionInitialization class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 7 April 2022
//**************************************************

//Includers from project files
//
#include "CaliceActionInitialization.hh"
#include "CaliceRunAction.hh"
#include "CalicePrimaryGeneratorAction.hh"
#include "CaliceEventAction.hh"
#include "CaliceTrackingAction.hh"
#include "CaliceSteppingAction.hh"

//Define constructor
//
CaliceActionInitialization::CaliceActionInitialization( G4String outputname )
    : G4VUserActionInitialization(),
    foutputname( outputname ) {}

//Define de-constructor
CaliceActionInitialization::~CaliceActionInitialization() {}

//Define BuildForMaster method
//
void CaliceActionInitialization::BuildForMaster() const {
    auto evtaction = new CaliceEventAction;
    SetUserAction( new CaliceRunAction(foutputname, evtaction)  );
}

//Define Build method
//
void CaliceActionInitialization::Build() const {
    SetUserAction( new CalicePrimaryGeneratorAction );     
    auto evtaction = new CaliceEventAction;
    SetUserAction( new CaliceRunAction(foutputname, evtaction)  );
    SetUserAction( evtaction );
    //SetUserAction( new CaliceTrackingAction );
    SetUserAction( new CaliceSteppingAction() );
}

//**************************************************
