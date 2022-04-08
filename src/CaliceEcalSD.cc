//**************************************************
// \file   CaliceEcalSD.cc
// \brief: Implementation of 
//         CaliceEcalSD class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 18 February 2022
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
      fHitsCollection(nullptr),
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
   
    //Create hits collection
    //
    fHitsCollection = new CaliceHitsCollection( SensitiveDetectorName, collectionName[0] );
  
    //Add this collection in hce
    //
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection( hcID, fHitsCollection );

    //Create hits: 1 hit per silicon cell -> 9720 hits
    //
    for ( G4int i=0; i<fNofCells; i++ ) {
        fHitsCollection->insert( new CaliceCalorimeterHit() );
    }
    
    totE = 0.; //to do: maybe delete totE variable
 
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
    G4double stepLength = aStep->GetStepLength()/mm;
    auto touchable = (aStep->GetPreStepPoint()->GetTouchable());
    int trackID = aStep->GetTrack()->GetTrackID();

    //Get calorimeter si cell id and layer number 
    //
    int layerNumber = -1;
    //layerNumber = floor(touchable->GetReplicaNumber(3)/9);      //wafer number divded by 9
                                                                  //old method by Katy, wrong and deprecated
    layerNumber = ComputeLayer( touchable->GetReplicaNumber(3) ); //layerNumber from 0 to 29

    G4int sicellcp = touchable->GetCopyNumber( );
    G4int sistripcp = touchable->GetCopyNumber( 1 );
    G4int waffercp = touchable->GetReplicaNumber( 3 );
    G4int sicellid = CalculateSiCellID( waffercp, sistripcp, sicellcp ); 

    //Find corresponding hit and store hit info
    //
    auto hit = (*fHitsCollection)[sicellid];
    hit->Add( edep, stepLength );
    hit->SetPos( aStep->GetPreStepPoint()->GetPosition() );
    hit->SetTrackID( trackID );
    hit->SetLayerID( layerNumber );
    hit->SetSiCellID( sicellid );
    
    //Add values for G4Analysis
    //
    if ( aStep->GetTrack()->GetParentID() == 0 && aStep->GetSecondaryInCurrentStep() != NULL ) {
        fisInteraction = true;
        fMCFirstInteractionLayer = layerNumber;
    }

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

    //G4Analysis Manager part
    //
    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleIColumn(0, fisInteraction);
    analysisManager->FillNtupleIColumn(5, fMCFirstInteractionLayer); 
    //analysisManager->AddNtupleRow(); //done later on in EventAction

    fisInteraction = false;
    fMCFirstInteractionLayer = -1; 
}

void CaliceEcalSD::clear() {}

void CaliceEcalSD::PrintAll() {}

//**************************************************
