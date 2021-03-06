#include "SimulationManager.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

SimulationManager::SimulationManager(
    EventList* eList,
    EventRoutine* roList[],
    int numRoutines,
    StateStorage* storage,
	Nachberechnungen nach
){
    eventList = eList;
    routineList = roList;
    numOfRoutines = numRoutines;
    stateStorage = storage;
	nachberechnungen = nach;

	//Clean database
	stateStorage->deleteOldNotarzt();
	stateStorage->deleteOldNotfall();
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
    cout << "********** Initialize events **********" << endl;
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
	Event* nextEvent;
	cout << "********** End initialization **********" << endl;
	cout << endl;
	cout << "********** Start simulation loop **********" << endl;
    //2. Simulationsschleife
    while(currentEvent->getType() != EventType::END)
    {	
		cout << "** Start execution **" << endl;
        executeEvent(currentEvent);

        eventList->printList();

        // Next event
        nextEvent = eventList->popEvent();

        //3. Zustände abspeichern (nur wenn sich die Zeiten unterscheiden)
        if( nextEvent->getExecutionTime() != currentEvent->getExecutionTime() )
		{
        	stateStorage->saveState(currentEvent->getExecutionTime());
		}

		currentEvent = nextEvent;
		
		cout << "** End execution **" << endl;
		cout << endl;
    }
	cout << "********** End simulation loop **********" << endl;
    // Execute end routine
    executeEvent(currentEvent);

	//Datenauswertung durchführen
	breakdown();
};

void SimulationManager::breakdown()
{
	nachberechnungen.init(stateStorage);	
}

