//**************************************************
// \file  CaliceEcalSD.cc
// \brief: Implementation of 
//         CaliceEcalSD class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 18 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceEcalSD.hh"
//#include "CaliceAnalysisManager.hh"
//#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4TouchableHandle.hh"
#include "G4SystemOfUnits.hh"
#include "G4SDManager.hh"
//#include <TH3D.h>
#include <math.h>
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4PrimaryVertex.hh"
#include "G4PrimaryParticle.hh"

//Define constructor
//
CaliceEcalSD::CaliceEcalSD(const G4String& name, const G4String& hitsCollectionName)
    :G4VSensitiveDetector(name)/*,fHitsCollection(0)*/,MeV2MIP(0.155),
    fNofReadoutLayers(30),fNofCells(9720) {
    
    //theCaliceAnalysis = CaliceAnalysisManager::GetPointer(); //the one and only
    //collectionName.insert(hitsCollectionName);

}

//Define deconstructor
//
CaliceEcalSD::~CaliceEcalSD() {}

//Define Initialize() method
//
void CaliceEcalSD::Initialize(G4HCofThisEvent* hce) {
    
    //fHitsCollection = new CaliceHitsCollection( SensitiveDetectorName, collectionName[0] );
  
    // Add this collection in hce
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    //hce->AddHitsCollection( hcID, fHitsCollection );
    totE = 0.;  
 
}

//Define CaliceEcalSD()
//
G4bool CaliceEcalSD::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
    G4cout<<"HEREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<G4endl;
    /*
    G4float edep = (aStep->GetTotalEnergyDeposit()/MeV)/MeV2MIP; //get energy deposition in units of MIP = 0.155 MeV 
    G4double stepLength = 0.;
    stepLength = aStep->GetStepLength()/mm;
 
    auto touchable = (aStep->GetPreStepPoint()->GetTouchable());

    //Get calorimeter cell id 
    //
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    G4TouchableHandle theHandle = preStepPoint->GetTouchableHandle();
    int layerNumber = -1;
    layerNumber = floor(touchable->GetReplicaNumber(3)/9); //wafer number divded by 9;
    CaliceCalorimeterHit* hit = new CaliceCalorimeterHit();
    
    // Add values
    //
    if ( aStep->GetTrack()->GetParentID() == 0 && aStep->GetSecondaryInCurrentStep() != NULL ) {
        theCaliceAnalysis->MClayer = layerNumber;
        theCaliceAnalysis->firstInteractionLayer = layerNumber;
        theCaliceAnalysis->isInteraction = true;
    }
    hit->Add(edep, stepLength);
    hit->SetPos(aStep->GetPreStepPoint()->GetPosition());
    hit->SetLayerID(layerNumber);

    int trackID = aStep->GetTrack()->GetTrackID();
    hit->SetTrackID(trackID);
    fHitsCollection->insert( hit ); 

    //Filling output tree and histograms
    //
    x = aStep->GetPreStepPoint()->GetPosition().x()/mm;
    y = aStep->GetPreStepPoint()->GetPosition().y()/mm;
    z = aStep->GetPreStepPoint()->GetPosition().z()/mm;

    theCaliceAnalysis->h_xProfile->Fill(x);
    theCaliceAnalysis->h_yProfile->Fill(y);
    theCaliceAnalysis->h_zProfile->Fill(z);
    theCaliceAnalysis->h_energyPerHit->Fill(edep);
  
    return true;
    */
}

//Define EndOfEvent method
//
void CaliceEcalSD::EndOfEvent(G4HCofThisEvent*) {
    /* 
    //Storing the hits in ROOT file
    //
    G4int NbHits = fHitsCollection->entries();
    theCaliceAnalysis->nhits = NbHits;
    for (G4int i=0;i<NbHits;i++) {
        theCaliceAnalysis->posx[i] = 0; 
        theCaliceAnalysis->posy[i] = 0;
        theCaliceAnalysis->posz[i] = 0;
        theCaliceAnalysis->energy[i] = 0;
        theCaliceAnalysis->layer[i] = -1;
    }
           
    //float samplingFraction = 0;
    float samplingFraction = 1.0;
    for (G4int i=0;i<NbHits;i++) {
        theCaliceAnalysis->posx[i] = (*fHitsCollection)[i]->GetPos().x()/mm;
        theCaliceAnalysis->posy[i] = (*fHitsCollection)[i]->GetPos().y()/mm;
        theCaliceAnalysis->posz[i] = (*fHitsCollection)[i]->GetPos().z()/mm;
        int layerNumber = (*fHitsCollection)[i]->GetLayerID();
        // to account for different amount of dead material preceding even and odd layers + different sampling fraction in the modules
        if ( layerNumber < 10 ) {
            if ( layerNumber%2==0 ) samplingFraction = 1;
            else samplingFraction = 1.072;
        } else if ( layerNumber > 9 && layerNumber < 20 ) {
            //if ( layerNumber%2==0 ) samplingFraction = 2;
            if ( layerNumber%2==0 ) samplingFraction = 1;
            //else samplingFraction = 2.047;
            else samplingFraction = 1.047;
        }
        else {
            //if ( layerNumber%2==0 ) samplingFraction = 3;
            if ( layerNumber%2==0 ) samplingFraction = 1;
            //else samplingFraction = 3.047;
            else samplingFraction = 1.047;
        }
        if ( samplingFraction*(*fHitsCollection)[i]->GetEdep() < 0.6 ) continue;
        theCaliceAnalysis->energy[i] = samplingFraction*(*fHitsCollection)[i]->GetEdep(); // in MIP
        theCaliceAnalysis->layer[i] = layerNumber; //(*fHitsCollection)[i]->GetLayerID();
        theCaliceAnalysis->h_energyPerHit->Fill(samplingFraction*(*fHitsCollection)[i]->GetEdep());
        theCaliceAnalysis->elayer[layerNumber] += samplingFraction*(*fHitsCollection)[i]->GetEdep();
        theCaliceAnalysis->hitslayer[layerNumber]++;
        theCaliceAnalysis->totEdep += samplingFraction*(*fHitsCollection)[i]->GetEdep();
    }
    theCaliceAnalysis->totEdep = totE;
    totE = 0;
    */
}

void CaliceEcalSD::clear() {}

void CaliceEcalSD::PrintAll() {}

//**************************************************
