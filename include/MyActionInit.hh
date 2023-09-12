#ifndef MYACTIONINIT_HH
#define MYACTIONINIT_HH

#include "G4VUserActionInitialization.hh"

#include "MyGenerator.hh"
#include "MyRunAction.hh"
#include "MyTrackingAction.hh"

class MyActionInit : public G4VUserActionInitialization
{
public:
    MyActionInit();
    virtual ~MyActionInit();

    virtual void Build() const;
};

#endif
