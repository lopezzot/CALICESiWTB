//**************************************************
// \file  CalicePrimaryGeneratorAction.hh
// \brief: Definition of 
//         CalicePrimaryGeneratorAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2022
//**************************************************

//Prevent including files multiple times
//
#ifndef CalicePrimaryGeneratorAction_h
#define CalicePrimaryGeneratorAction_h

//Includers from Geant4
//
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4String.hh"
#include "G4ParticleGun.hh"

class G4ParticleGun;
class G4Event;
//class G4VPrimaryGenerator;

class CalicePrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {

    public:
        //Constructor and Deconstructor
        //
        CalicePrimaryGeneratorAction();
        ~CalicePrimaryGeneratorAction();
        static CalicePrimaryGeneratorAction* getInstance();

    public:
        void GeneratePrimaries( G4Event* anEvent );
        G4double particleEnergy;
        G4ParticleGun* particleGun;

    private:
        //G4VPrimaryGenerator* generator;
        static CalicePrimaryGeneratorAction* fInstance;

};

#endif

//**************************************************
