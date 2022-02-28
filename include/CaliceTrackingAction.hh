//**************************************************
// \file  CaliceTrackingAction.hh
// \brief: Definition of 
//         CaliceTrackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 21 February 2022
//**************************************************

//Prevent including headers multiple times
//
#ifndef CaliceTrackingAction_h
#define CaliceTrackingAction_h

//Includers from Geant4
//
#include "G4UserTrackingAction.hh"

class CaliceTrackingAction : public G4UserTrackingAction {

    public:
        //Constructor and decostructor
        //
        CaliceTrackingAction();
        virtual ~CaliceTrackingAction();

        virtual void PreUserTrackingAction(const G4Track*);
        virtual void PostUserTrackingAction(const G4Track*);

    private:

        CaliceTrackingAction & operator=(const CaliceTrackingAction &right);
        CaliceTrackingAction(const CaliceTrackingAction&);

};

#endif

//**************************************************
