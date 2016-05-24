#include "SimulationManager.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

SimulationManager::SimulationManager(
    EventList* eList,
    EventRoutine* roList[],
    int numRoutines,
    StateStorage* storage
){
    eventList = eList;
    routineList = roList;
    numOfRoutines = numRoutines;
    stateStorage = storage;
};

SimulationManager::~SimulationManager()
{
    free(eventList);

    for(int j=0; j<numOfRoutines; j++)
    {
        free(routineList[j]);
    }
};

void SimulationManager::executeEvent(Event *event)
{
    EventRoutine* routine;
    int found = 0;
    int i=0;
    while(!found && i< numOfRoutines)
    {
        routine = routineList[i];

        if(routine->getType() == event->getType())
        {
            routine->execute(event);
            found = 1;
        }
        i++;
    }

    if(!found)
    {
        cout << "No routine for type " << (int)event->getType() << endl;
    }
};

void SimulationManager::run(
    Event* initialEvents[],
    int sizeEvents,
    int endTime
){
    //1. Initialisierung
    // 1.1 Zustandsvariablen auf 0 setzen

    //1.2 Ereignisliste mit Startereignissen initialisieren
    cout << "Initialize events" << endl;
    for(int i=0; i<sizeEvents; i++)
    {
        eventList->addEvent(initialEvents[i]);
    }
    //1.3 Simulationsende-Ereignis hinzufügen
    Event* endEvent = new Event(endTime, EventType::END);
    eventList->addEvent(endEvent);

    cout << "Initial event list: " << endl;
    eventList->printList();

    Event* currentEvent = eventList->popEvent();

    //2. Simulationsschleife
    while(currentEvent->getType() != EventType::END)
    {
        cout << "Execute next event of type: " << (int) currentEvent->getType() << endl;
        executeEvent(currentEvent);

        eventList->printList();

        // Next event
        currentEvent = eventList->popEvent();

        //3. Zustände abspeichern
        stateStorage->saveState();
    }

    // Execute end routine
    executeEvent(currentEvent);
};

