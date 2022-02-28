//**************************************************
// \file  CaliceEcalSD.hh
// \brief: Definition of 
//         CaliceEcalSD class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 18 February 2022
//**************************************************

//Prevent including headers multiple times
//
#ifndef CaliceEcalSD_h
#define CaliceEcalSD_h

//Includers from project files
//
#include "CaliceCalorimeterHit.hh"

//Includers from Geant4
//
#include "G4VSensitiveDetector.hh"
#include "globals.hh"
class G4Step;
class G4TouchableHistory;
class G4HCofThisEvent;

#define numberOfCells 9720 //18*18*30

class CaliceEcalSD : public G4VSensitiveDetector {
    
    public:
        
        //Constructor and deconstructor
        //
        CaliceEcalSD(const G4String&, const G4String& hitsCollectionName);
        virtual ~CaliceEcalSD();

        void Initialize(G4HCofThisEvent* hitCollection);
        G4bool ProcessHits(G4Step*,G4TouchableHistory*);
        void EndOfEvent(G4HCofThisEvent* hitCollection);
        void clear();
        void PrintAll();
        std::vector<G4double>& Getfelayer() { return felayer; };

        double x,y,z;
        double pixelX, pixelY, pixelZ;
        double radius;

        double totE;

    private:

        CaliceHitsCollection* fHitsCollection;
        G4int fNofReadoutLayers; 
        G4int fNofCells;
        float MeV2MIP;
        G4bool fisInteraction;
        G4int fFirstInteractionLayer;

        std::vector<G4double> felayer;
};

#endif

//**************************************************
