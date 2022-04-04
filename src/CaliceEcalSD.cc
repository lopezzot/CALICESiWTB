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
      fHitsCollection(0),
      MeV2MIP(0.155),
      //fNofReadoutLayers(30),
      //fNofCells(9720),
      fisInteraction(false),
      fMCFirstInteractionLayer(-1) {
    
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
            "Mother: " << aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(1)->GetName()<< " " <<
            "GranMother: " << aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(2)->GetName()<< " " <<
            "GGMother: " << aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume(3)->GetName()<< " " <<
            "No: " << aStep->GetPreStepPoint()->GetTouchable()->GetReplicaNumber(3)<<G4endl;
    G4cout<<"x: "<< aStep->GetPreStepPoint()->GetPosition().x() <<
            "y: "<< aStep->GetPreStepPoint()->GetPosition().y() <<
            "z: "<< aStep->GetPreStepPoint()->GetPosition().z() <<G4endl;
            //"Particle "<< aStep->GetTrack()->GetParticleDefinition()->GetParticleName()<< " " <<
            //"Dep(MeV) "<< aStep->GetTotalEnergyDeposit()<<G4endl;*/ 
    
    //Get info from step
    //
    G4double edep = (aStep->GetTotalEnergyDeposit()/MeV)/MeV2MIP; //get energy deposition in units of MIP = 0.155 MeV 
    G4double stepLength = 0.;
    stepLength = aStep->GetStepLength()/mm;
 
    const G4VTouchable* touchable = (aStep->GetPreStepPoint()->GetTouchable());

    const G4TouchableHistory* touchable2 = (G4TouchableHistory*)(aStep->GetPreStepPoint()->GetTouchable());

    //Get calorimeter cell id 
    //
    G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
    G4TouchableHandle theHandle = preStepPoint->GetTouchableHandle();
    const G4VPhysicalVolume* volume = theHandle->GetVolume(3);
    int layerNumber = -1;
    //layerNumber = floor(touchable->GetReplicaNumber(3)/9); //wafer number divded by 9;
    G4cout<<touchable->GetCopyNumber()<<" "<<touchable->GetReplicaNumber()<<G4endl;
    G4cout<<touchable2->GetCopyNumber()<<" "<<touchable2->GetReplicaNumber()<<G4endl;
    G4cout<<volume->GetCopyNo()<<" "<<volume->GetName()<<G4endl;
    G4cout<<theHandle->GetCopyNumber()<<" "<<theHandle->GetReplicaNumber()<<G4endl;
    G4cout<<"------"<<G4endl;
    layerNumber = ComputeLayer( touchable->GetCopyNumber(3) );
    //G4cout<<layerNumber<<" "<<ComputeLayer( touchable->GetReplicaNumber(3) )<<" "<<touchable->GetReplicaNumber(3)<<G4endl; 
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
        fMCFirstInteractionLayer = layerNumber;
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
    
    //Check if an interaction acutally happened
    //
    if (fMCFirstInteractionLayer==29){
        fMCFirstInteractionLayer=-1;
        fisInteraction=false;
    }

    // G4Analysis Manager part
    //
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleIColumn(0, fisInteraction);
    analysisManager->FillNtupleIColumn(3, fMCFirstInteractionLayer); 
    //analysisManager->AddNtupleRow(); //done later on in EventAction

    fisInteraction = false;
    fMCFirstInteractionLayer = -1; 
}

void CaliceEcalSD::clear() {}

void CaliceEcalSD::PrintAll() {}

//**************************************************
