#ifndef MYTARGETCONSTRUCTION_HH
#define MYTARGETCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

class MyTargetConstruction : public G4VUserDetectorConstruction
{
public:
    MyTargetConstruction();
    ~MyTargetConstruction();

    virtual G4VPhysicalVolume *Construct();
};

#endif
