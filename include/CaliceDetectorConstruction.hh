//**************************************************
// \file  CaliceDetectorConstruction.hh
// \brief: Definition of 
//         CaliceDetectorConstruction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2022
//**************************************************

//Prevent including headers multilpe times
//
#ifndef CALICEDETECTORCONSTRUCTION_H
#define CALICEDETECTORCONSTRUCTION_H

//Includers from Geant4
//
#include "G4VUserDetectorConstruction.hh"
class G4GDMLParser;

//Includers from project files
//
class CaliceEcalSD;

/*Class for laoding GDML geometry*/

class CaliceDetectorConstruction : public G4VUserDetectorConstruction {
    
    public: 
        //Constructor
        //
        CaliceDetectorConstruction(const G4GDMLParser& parser);

        virtual G4VPhysicalVolume *Construct();  
        virtual void ConstructSDandField();
  
    private:
        const G4GDMLParser& fParser;
        int fNoOfCells; 
};

#endif

//**************************************************
