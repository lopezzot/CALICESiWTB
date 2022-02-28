//**************************************************
// \file  CaliceRunAction.hh
// \brief: Definition of 
//         CaliceRunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 20 February 2022
//**************************************************

//Prevent including headers multiple times
//
#ifndef CaliceRunAction_h
#define CaliceRunAction_h

//Includers from Geant
//
#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"

//Includers from project files
//
class CaliceEventAction;

class CaliceRunAction : public G4UserRunAction {
    
    public:
        //Constructor and deconstructor
        //
        CaliceRunAction(G4String listname, CaliceEventAction* evtaction);
        ~CaliceRunAction();

    public:
        void BeginOfRunAction(const G4Run*);

        void EndOfRunAction(const G4Run*);

    private:
        G4String fPhysList;
        CaliceEventAction* fEventAction;

};

#endif

//**************************************************

