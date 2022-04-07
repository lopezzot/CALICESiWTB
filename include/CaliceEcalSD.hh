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

//#define numberOfCells 9720 //18*18*30
static constexpr G4int numberOfCells = 9720;

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

        double x,y,z;
        double pixelX, pixelY, pixelZ;
        double radius;

        double totE;

        G4int ComputeLayer( G4int copynumber );

    private:

        CaliceHitsCollection* fHitsCollection;
        //G4int fNofReadoutLayers; 
        //G4int fNofCells;
        float MeV2MIP;
        G4bool fisInteraction;
        G4int fMCFirstInteractionLayer;

        G4int CalculateSiCellID( G4int waffercp, G4int sistripcp, G4int sicellcp );
};

inline G4int CaliceEcalSD::CalculateSiCellID( G4int waffercp, G4int sistripcp, G4int sicellcp ){

    G4double sicellid = (6*6)*waffercp + 6*sistripcp + sicellcp; 

    if(sicellid > 9729){
        G4cout<<"ERROR in sicellID computation!!!"<<G4endl;
    }

    return sicellid;
}

inline G4int CaliceEcalSD::ComputeLayer( G4int copynumber ) {
    
    G4int layer = 0;
    G4int doublelayer = copynumber/18;
    G4int relcpnumber = copynumber - doublelayer*18;
    if ( relcpnumber<6 ) { layer = 0; }
    else if ( 6<=relcpnumber && relcpnumber<12 ) { layer = 1; }
    else if ( 12<=relcpnumber && relcpnumber<15 ) { layer = 0; }
    else if ( 15<=relcpnumber && relcpnumber<18 ) { layer = 1; }
    else {G4cout<<"problem with layer numbering!!!!!!!!!!!!!!!"<<G4endl;}
    layer = doublelayer*2 + layer;
    return layer;    

}

#endif

//**************************************************
