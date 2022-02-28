//**************************************************
// \file   CaliceEcalSD.cc
// \brief: Implementation of 
//         CaliceEcalSD class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 18 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceEcalSD.hh"
#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "g4root.hh"
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
    : G4VSensitiveDetector(name),
      //fHitsCollection(0),
      MeV2MIP(0.155),
      //fNofReadoutLayers(30),
      //fNofCells(9720),
      fisInteraction(false),
      fFirstInteractionLayer(-1) {
    
    collectionName.insert(hitsCollectionName);

}

//Define deconstructor
//
CaliceEcalSD::~CaliceEcalSD() {}

//Define Initialize() method
//
void CaliceEcalSD::Initialize(G4HCofThisEvent* hce) {
    
    fHitsCollection = new CaliceHitsCollection( SensitiveDetectorName, collectionName[0] );
  
    // Add this collection in hce
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection( hcID, fHitsCollection );
    totE = 0.;  
 
}

//Define CaliceEcalSD()
//
G4bool CaliceEcalSD::ProcessHits(G4Step* aStep, G4TouchableHistory*) {

    //Print out some info step-by-step
    //
    /*G4cout<<"Track #: "<< aStep->GetTrack()->GetTrackID()<< " " <<
            "Step #: " << aStep->GetTrack()->GetCurrentStepNumber()<< " "<<
            "Volume: " << aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()<< " " <<
            "Particle "<< aStep->GetTrack()->GetParticleDefinition()->GetParticleName()<< " " <<
            "Dep(MeV) "<< aStep->GetTotalEnergyDeposit()<<G4endl; */
    
    //Get info from step
    //
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
    int trackID = aStep->GetTrack()->GetTrackID();

    //Create a new CaliceCalorimeterHit
    //
    CaliceCalorimeterHit* hit = new CaliceCalorimeterHit();
    hit->Add(edep, stepLength);
    hit->SetPos(aStep->GetPreStepPoint()->GetPosition());
    hit->SetTrackID(trackID);
    hit->SetLayerID(layerNumber);
    fHitsCollection->insert( hit ); 
    
    //Add values for G4Analysis
    //
    if ( aStep->GetTrack()->GetParentID() == 0 && aStep->GetSecondaryInCurrentStep() != NULL ) {
        fisInteraction = true;
        fFirstInteractionLayer = layerNumber;
    }

    //Filling output tree and histograms
    //
    x = aStep->GetPreStepPoint()->GetPosition().x()/mm;
    y = aStep->GetPreStepPoint()->GetPosition().y()/mm;
    z = aStep->GetPreStepPoint()->GetPosition().z()/mm;
    
    return true;
    
}

//Define EndOfEvent method
//
void CaliceEcalSD::EndOfEvent(G4HCofThisEvent*) {
     
    // G4Analysis Manager part
    //
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleIColumn(0, fisInteraction);
    analysisManager->FillNtupleIColumn(1, fFirstInteractionLayer); 
    //analysisManager->AddNtupleRow(); //done later on in EventAction

    fisInteraction = false;
    fFirstInteractionLayer = -1; 
}

void CaliceEcalSD::clear() {}

void CaliceEcalSD::PrintAll() {}

//**************************************************
