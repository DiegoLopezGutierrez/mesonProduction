#include "MyActionInit.hh"

MyActionInit::MyActionInit()
{}

MyActionInit::~MyActionInit()
{}

void MyActionInit::Build() const
{
    Generator *generator = new Generator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);

    MyTrackingAction *trackingAction = new MyTrackingAction();
    SetUserAction(trackingAction);
}
