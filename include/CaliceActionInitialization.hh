//**************************************************
// \file CaliceActionInitialization.hh
// \brief: definition of CaliceActionInitialization
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 7 April 2022
//**************************************************

#ifndef CaliceActionInitialization_h
#define CaliceActionInitialization_h

//Includers from Geant4
//
#include "G4VUserActionInitialization.hh"
#include "G4String.hh"

class CaliceActionInitialization : public G4VUserActionInitialization {

    public:
        CaliceActionInitialization( G4String outputname );
        virtual ~CaliceActionInitialization();

        virtual void BuildForMaster() const;
        virtual void Build() const;

    private:
        G4String foutputname;

};

#endif //CaliceActionInitialization_h

//**************************************************
