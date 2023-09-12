#ifndef MYRUNACTION_HH
#define MYRUNACTION_HH 1

#include "G4UserRunAction.hh"
#include "G4Run.hh"

class G4Run;

class MyRunAction : public G4UserRunAction
{
    public:
        MyRunAction();
	virtual ~MyRunAction();

	virtual void BeginOfRunAction(const G4Run*);
	virtual void EndOfRunAction(const G4Run*);
};

#endif
