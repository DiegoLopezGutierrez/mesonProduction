#include "MyTargetConstruction.hh"

MyTargetConstruction::MyTargetConstruction()
{}

MyTargetConstruction::~MyTargetConstruction()
{}

G4VPhysicalVolume *MyTargetConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    
    // Graphite: ZXF-5Q (POCO graphite); density 1.78 g/cm3
    G4Material *graphite = new G4Material("Graphite", 6., 12.00*g/mole, 1.78*g/cm3);
    
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    // World volume
    G4double world_x = 0.5*m;
    G4double world_y = 0.5*m;
    G4double world_z = 4.*m;

    G4Box *solidWorld = new G4Box("solidWorld", world_x, world_y, world_z);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    // DUNE Beam graphite target (2002.03005, 4.1.1): 2.2 m long, 16 mm diameter (cylindrical)
    G4double target_inner_rad = 0.*mm;
    G4double target_outer_rad = 8.*mm;
    G4double target_length = 1.1*m;    // z / 2
    G4double target_start_th = 0.*deg;
    G4double target_stop_th = 360.*deg;

    G4Tubs *solidTarget = new G4Tubs("solidTarget",
		                     target_inner_rad,
				     target_outer_rad,
				     target_length,
				     target_start_th,
				     target_stop_th);

    G4LogicalVolume *logicTarget = new G4LogicalVolume(solidTarget, graphite, "logicTarget");

    G4double target_z_placement = target_length - world_z;
    G4VPhysicalVolume *physTarget = new G4PVPlacement(0, G4ThreeVector(0., 0., target_z_placement), logicTarget, "physTarget", logicWorld, false, 0, true);

    G4cout << "Physical target constructed at address: " << &physTarget << G4endl;

    return physWorld;
};
