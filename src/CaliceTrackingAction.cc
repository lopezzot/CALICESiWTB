//**************************************************
// \file CaliceTrackingAction.cc
// \brief: Implementation of 
//         CaliceTrackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 21 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceTrackingAction.hh"

//Includers from Geant4
//
#include "G4ParticleDefinition.hh"
#include "G4DynamicParticle.hh"
#include "G4Track.hh"
#include "G4ThreeVector.hh"
#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4EventManager.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

//Constructor definition
//
CaliceTrackingAction::CaliceTrackingAction() : G4UserTrackingAction()
{}

//Decontructor definition
//
CaliceTrackingAction::~CaliceTrackingAction() {}

//PreUserTrackingAction definition
//
void CaliceTrackingAction::PreUserTrackingAction(const G4Track* aTrack) {
    
}

//PostUserTrackingAction definition
//
void CaliceTrackingAction::PostUserTrackingAction(const G4Track* aTrack) {
    
    if(0 == aTrack->GetParentID()) {               //vertex track
        const G4Step* step = aTrack->GetStep();
        const G4StepPoint* poststep = step->GetPostStepPoint();
        G4int n_neut = 0; 
        G4int n_char = 0; 
        //G4double z = poststep->GetPosition().z();
        //G4cout << "### end of track " <<  poststep->GetProcessDefinedStep()->GetProcessSubType()<< G4endl;
        if(poststep->GetProcessDefinedStep()->GetProcessSubType() == 121) { //HadInElastic process
            const std::vector<const G4Track*>* tracks = step->GetSecondaryInCurrentStep(); //Get secondaries from HadInElastic
            G4int nn = tracks->size(); //how many secondaries
            const G4double elim = 100*MeV;
            for(G4int i=0; i<nn; ++i) {//loop over secondaries
	        /*
                G4cout << i << ". E(GeV)= " << (*tracks)[i]->GetKineticEnergy()/GeV 
	        << "  id= " << (*tracks)[i]->GetDefinition()->GetPDGEncoding()
	        << " " << (*tracks)[i]->GetDefinition()->GetParticleName() << G4endl;
	        */
                if((*tracks)[i]->GetKineticEnergy() > elim) {//Secondaries > 100 MeV
                    G4int id = (*tracks)[i]->GetDefinition()->GetPDGEncoding();
                    if(id == 22) { ++n_neut; } //Increase neutral particles (neutron)
                    else if(id == 111) { n_neut += 2; } //Increase neutral particles (pi0)
                    else if(0.0 != (*tracks)[i]->GetDefinition()->GetPDGCharge()) {++n_char;} //Increase charged (any)
	        }       
            }
        }
        //G4cout << "  Nchar= " << n_char << " n_neut= " << n_neut << G4endl;
    }
        
}

//**************************************************
