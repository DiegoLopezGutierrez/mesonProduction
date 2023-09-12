#ifndef MYTRACKINGACTION_HH
#define MYTRACKINGACTION_HH 1

#include "G4UserTrackingAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4Track.hh"

//#include "G4Event.hh"

class MyTrackingAction : public G4UserTrackingAction
{
    public:
        MyTrackingAction();
        virtual ~MyTrackingAction();

	virtual void PreUserTrackingAction(const G4Track* tr);
};

#endif
