//**************************************************
// \file  CaliceCalorimeterHit.hh
// \brief: Definition of 
//         CaliceCalorimeterHit class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 21 February 2022
//**************************************************

//Prevent including headers multilple times
//
#ifndef CaliceCalorimeterHit_h
#define CaliceCalorimeterHit_h

//Includers from Geant4
//
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
//#include "G4Threading.hh"
#include "G4String.hh"


class CaliceCalorimeterHit : public G4VHit {
    
    public:
        //Constructor(s) and deconstructor
        //
        CaliceCalorimeterHit();
        CaliceCalorimeterHit(const CaliceCalorimeterHit&);
        virtual ~CaliceCalorimeterHit();

        //Operators
        //
        const CaliceCalorimeterHit& operator=(const CaliceCalorimeterHit&);
        G4int operator==(const CaliceCalorimeterHit&) const;

        inline void* operator new(size_t);
        inline void  operator delete(void*);

        //Methods from base class
        //
        virtual void Draw() {}
        virtual void Print();

        //Methods to handle data
        //
        void Add(G4double de, G4double dl);

        void SetLayerID(G4int z) { fLayerID = z; }
        G4int GetLayerID() const { return fLayerID; }

        void SetPadIDx(G4int idX) { fPadIDx = idX; }
        G4int GetPadIDx() const { return fPadIDx; }

        void SetPadIDy(G4int idY) { fPadIDx = idY; }
        G4int GetPadIDy() const { return fPadIDy; }

        void SetVolName(G4String volName) { fVolName = volName; }
        G4String GetVolName() const { return fVolName; }

        void SetLocalPos(G4ThreeVector xyz) { fLocalPos = xyz; }
        G4ThreeVector GetLocalPos() const { return fLocalPos; }

        void SetWorldPos(G4ThreeVector xyz) { fWorldPos = xyz; }
        G4ThreeVector GetWorldPos() const { return fWorldPos; }

        void SetPos      (G4ThreeVector xyz){ fPos = xyz; };

        void SetTrackID(G4int trackID) { fTrackID = trackID; }
        G4int GetTrackID() const { return fTrackID; }
        
        //Get methods
        //
        G4double GetEdep() const;
        G4double GetTrackLength() const;
        G4ThreeVector GetPos(){ return fPos; };

      
    private:
        G4int fPadIDx;
        G4int fPadIDy;
        G4int fLayerID;
        G4double fEdep;        ///< Energy deposit in the sensitive volume
        G4ThreeVector fPos;
        G4double fTrackLength; ///< Track length in the  sensitive volume
        G4ThreeVector fLocalPos;
        G4ThreeVector fWorldPos;
        G4int fTrackID;
        G4String fVolName;
};

//Aliasing CaliceHitsCollection
//
//using CaliceHitsCollection = G4THitsCollection<CaliceCalorimeterHit>;
typedef G4THitsCollection<CaliceCalorimeterHit> CaliceHitsCollection;
extern /*G4ThreadLocal*/ G4Allocator<CaliceCalorimeterHit>* CaliceCalorimeterHitAllocator;

//Inline methods declaration
//
inline void* CaliceCalorimeterHit::operator new(size_t) {
    
    if (!CaliceCalorimeterHitAllocator) {
        CaliceCalorimeterHitAllocator = new G4Allocator<CaliceCalorimeterHit>;
    }
    void *hit;
    hit = (void *) CaliceCalorimeterHitAllocator->MallocSingle();
    return hit;

}

inline void CaliceCalorimeterHit::operator delete(void *hit) {
    
    if (!CaliceCalorimeterHitAllocator) {
        CaliceCalorimeterHitAllocator = new G4Allocator<CaliceCalorimeterHit>;
    }
    CaliceCalorimeterHitAllocator->FreeSingle((CaliceCalorimeterHit*) hit);

}

inline void CaliceCalorimeterHit::Add(G4double de, G4double dl) {
    fEdep += de; 
    fTrackLength += dl;

}

inline G4double CaliceCalorimeterHit::GetEdep() const { return fEdep; }

inline G4double CaliceCalorimeterHit::GetTrackLength() const { return fTrackLength; }

#endif

//**************************************************
