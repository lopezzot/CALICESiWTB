//**************************************************
// \file CaliceDetectorConstruction.cc
// \brief: Implementation of 
//         CaliceDetectorConstruction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 February 2022
//**************************************************

//Includers from Geant4
//
#include "G4SDManager.hh"
#include "G4GDMLParser.hh"

//Includers from project files
//
#include "CaliceDetectorConstruction.hh"
//#include "CaliceSensitiveCalorimeter.hh"
#include "CaliceEcalSD.hh"
 
//Constructor definition
//
CaliceDetectorConstruction::CaliceDetectorConstruction(const G4GDMLParser& parser)
    : G4VUserDetectorConstruction(),
    //   theSensitiveCalorimeter( 0 ),
    fParser(parser) {
}

//Construct() method definition
//
G4VPhysicalVolume* CaliceDetectorConstruction::Construct() {
    
    ConstructSDandField();
    return fParser.GetWorldVolume();

}

//ConstructSDandField() method definition
//
void CaliceDetectorConstruction::ConstructSDandField() {
    
    auto ecalSD = new CaliceEcalSD("EcalSD", "CaloHitsCollection");
    G4SDManager::GetSDMpointer()->AddNewDetector(ecalSD);
 
    //G4cout << "Constructing Sensitive Detector..." << G4endl; 
    ///////////////////////////////////////////////////////////////////////

    // Example how to retrieve Auxiliary Information for sensitive detector
    //
    const G4GDMLAuxMapType* auxmap = fParser.GetAuxMap();
    G4cout << "Found " << auxmap->size()
           << " volume(s) with auxiliary information."
           << G4endl << G4endl;
    for(G4GDMLAuxMapType::const_iterator iter=auxmap->begin(); iter!=auxmap->end(); iter++) {
        G4cout << "Volume " << ((*iter).first)->GetName()
           << " has the following list of auxiliary information: "
           << G4endl << G4endl;
        for (G4GDMLAuxListType::const_iterator vit=(*iter).second.begin(); vit!=(*iter).second.end(); vit++) {
            G4cout << "--> Type: " << (*vit).type
                   << " Value: " << (*vit).value << G4endl;
        }
    }
    G4cout<<G4endl;

    // The same as above, but now we are looking for
    // sensitive detectors setting them for the volumes
    //
    for(G4GDMLAuxMapType::const_iterator iter=auxmap->begin(); iter!=auxmap->end(); iter++) {
        G4cout << "Volume " << ((*iter).first)->GetName()
               << " has the following list of auxiliary information: "
               << G4endl << G4endl;
        for (G4GDMLAuxListType::const_iterator vit=(*iter).second.begin(); vit!=(*iter).second.end();vit++) {
            if ((*vit).type=="SensDet") {
                G4cout << "Attaching sensitive detector " << (*vit).value
                << " to volume " << ((*iter).first)->GetName()
                <<  G4endl << G4endl;

                G4LogicalVolume* myvol = (*iter).first;
                myvol->SetSensitiveDetector(ecalSD);
            }
        }
    }

}

//**************************************************
