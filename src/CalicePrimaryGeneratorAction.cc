//**************************************************
// \file  CalicePrimaryGeneratorAction.cc
// \brief: Implementation of 
//         CalicePrimaryGeneratorAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2022
//**************************************************

//Includers from project files 
//
#include "CalicePrimaryGeneratorAction.hh"
//#include "CaliceAnalysisManager.hh"

//Includers from Geant4
//
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4Version.hh"
//#include "CalicePrimaryGeneratorActionMessenger.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

//Instantiate singleton
//
CalicePrimaryGeneratorAction* CalicePrimaryGeneratorAction::fInstance = 0;

//Constructor definition
CalicePrimaryGeneratorAction::CalicePrimaryGeneratorAction() : 
    particleEnergy(10*GeV), particleGun(0) {
    
        particleGun = new G4ParticleGun(1);

}

//Deconstructor definition
//
CalicePrimaryGeneratorAction::~CalicePrimaryGeneratorAction() {

    if(!particleGun)    delete particleGun;

}

//GeneratePrimaries() method definition
//
void CalicePrimaryGeneratorAction::GeneratePrimaries( G4Event* anEvent ) {

    //G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    //particleGun->SetParticleDefinition( particleTable->FindParticle( "pi-" ) );
    //particleGun->SetParticleEnergy(10*GeV);
    G4double xySize = 12.5*mm;
    G4double y = 0.0;
    G4double x = 0.0;
    x = xySize*(2.0*G4UniformRand() - 1.0); //->to be understood id needed in SetParticlePosition
    y = xySize*(2.0*G4UniformRand() - 1.0);
    particleGun->SetParticlePosition( G4ThreeVector( x, y, -2*m ) );
    //x = 0.0*mm + G4UniformRand()*0.5;
    //y = 0.0*mm + G4UniformRand()*0.5;
    //particleGun->SetParticlePosition( G4ThreeVector( 0.*mm, 0.*mm, -2*m ) );
    //particleGun->SetParticlePosition( G4ThreeVector( 12.5*mm, 12.5*mm, -2*m ) );
    //particleGun->SetParticlePosition( G4ThreeVector( 2.0*cm, 0.0*cm, -2*m ) );
    //particleGun->SetParticlePosition( G4ThreeVector( 26.0*mm, 1.0*mm, 0.0*mm ) );
    //particleGun->SetParticlePosition( G4ThreeVector( (10.0*G4UniformRand())*mm, (1.0*G4UniformRand())*mm, 0.0*mm ) );
    //particleGun->SetParticlePosition( G4ThreeVector( 10.0*mm, 1.0*mm, 0.0*mm  ) );
    //particleGun->SetParticlePosition( G4ThreeVector( -0.003*m, y, -0.5*m ) ); // particle gun not in center to avoid shooting at inter-cell gaps due to staggering of layers
    particleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1) );

    particleGun->GeneratePrimaryVertex(anEvent);
    
}

//getInstance() method definition
//
CalicePrimaryGeneratorAction* CalicePrimaryGeneratorAction::getInstance(){
    
    if(!fInstance) fInstance = new CalicePrimaryGeneratorAction;
    return fInstance;

}

//**************************************************
