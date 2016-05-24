#include "StateStorage.h"
#include <iostream>

using namespace std;

StateStorage::StateStorage()
{
    //ctor
}

StateStorage::~StateStorage()
{
    //dtor
}

void StateStorage::saveState()
{
    cout << "Current State:" << endl;
    list<SimObject*>::iterator iter = observedList.begin();

    SimObject* currentObject;

    while(iter != observedList.end())
    {
        currentObject = *iter;
        currentObject->getState();
        iter++;
    }

    //TODO
    // Datenbakanbindung
}

void StateStorage::registerObject(SimObject *simObject)
{
    observedList.push_front(simObject);
}

void StateStorage::unregister(SimObject *simObject)
{
    observedList.remove(simObject);
}
