//**************************************************
// \file  CaliceCalorimeterHit.cc
// \brief: Implementation of 
//         CaliceCalorimeterHit class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 21 February 2021
//**************************************************

//Includers from project files
//
#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

//Includers from C++
//
#include <iomanip>

G4Allocator<CaliceCalorimeterHit>* CaliceCalorimeterHitAllocator = 0;

//Constructor definition
//
CaliceCalorimeterHit::CaliceCalorimeterHit()
    : G4VHit(),
      fPadIDx(0),
      fPadIDy(0),
      fLayerID(0),
      fEdep(0.),
      fPos(0,0,0),
      fTrackLength(0.),
      fTrackID(0)
      //fVolName 
{}

//Deconstructor definition
//
CaliceCalorimeterHit::~CaliceCalorimeterHit() {}

//Second constructor definition
//
CaliceCalorimeterHit::CaliceCalorimeterHit(const CaliceCalorimeterHit& right) : G4VHit() {
    
    fEdep         = right.fEdep;
    fPos          = right.fPos;
    fTrackLength  = right.fTrackLength;
    fTrackID      = right.fTrackID;
    fLayerID      = right.fLayerID;
    fPadIDx       = right.fPadIDx;
    fPadIDy       = right.fPadIDy;
    fVolName      = right.fVolName;

}

//operator = definition
//
const CaliceCalorimeterHit& CaliceCalorimeterHit::operator=(const CaliceCalorimeterHit& right) {
    
    fEdep        = right.fEdep;
    fPos         = right.fPos;
    fTrackLength = right.fTrackLength;
    fTrackID     = right.fTrackID;
    fLayerID     = right.fLayerID;
    fPadIDx      = right.fPadIDx;
    fPadIDy      = right.fPadIDy;
    fVolName     = right.fVolName;

    return *this;
}

//operator == definition
//
G4int CaliceCalorimeterHit::operator==(const CaliceCalorimeterHit& right) const {

    return ( this == &right ) ? 1 : 0;

}

/*
void CaliceCalorimeterHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(fPos);
    circle.SetScreenSize(2.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}*/

//Print method definition
//
void CaliceCalorimeterHit::Print() {
    G4cout
    << "Edep: " 
    << std::setw(7) << G4BestUnit(fEdep,"Energy")
    << " track length: " 
    << std::setw(7) << G4BestUnit( fTrackLength,"Length")
    << "  position[mm]: " << fPos << G4endl;

}

//**************************************************
