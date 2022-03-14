//**************************************************
// \file CaliceSteppingAction.hh
// \brief: Definition of CaliceSteppingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 March 2022
//**************************************************

//Prevent including header multiple times
//
#ifndef CaliceSteppingAction_h
#define CaliceSteppingAction_h

//Includers from Geant4
//
#include "G4UserSteppingAction.hh"

class CaliceSteppingAction : public G4UserSteppingAction {
    
    public:
        //Constructor and de-constructor
        //
        CaliceSteppingAction( );
        virtual ~CaliceSteppingAction();

        virtual void UserSteppingAction( const G4Step* aStep );

};

#endif

//**************************************************
