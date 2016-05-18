#include "SimulationManager.h"

SimulationManager::SimulationManager(
    EventList* eList,
    int numEvents,
    EventRoutine* roList,
    int numRoutines
){
    eventList = evList;
    numOfEvents = numEvents;
    routineList = roList;
    numOfRoutines = numRoutines;
};

SimulationManager::~SimulationManager()
{
    for(int i=0; i<numOfEvents; i++)
    {
        free eventList[i];
    }

    for(int j=0; j<numOfEvents; j++)
    {
        free routineList[j];
    }
};

void SimulationManager::executeEvent()
{
    //TODO
};

void SimulationManager::run(
    Event* initialEvents[],
    int sizeEvents,
    struct tm* simEnd
){
    //1. Initialisierung
    // 1.1 Zustandsvariablen auf 0 setzen

    //1.2 Ereignisliste mit Startereignissen initialisieren
    for(int i=0; i<sizeEvents; i++)
    {
        eventList.addEvent(initialEvents[0]);
    }
    //1.3 Simulationsende-Ereignis hinzufügen
    Event* endEvent = new Event(simEnd, EventType::END);
    eventList.addEvent(endEvent);

    Event* currentEvent = eventList.getNextEvent();

    //2. Simulationsschleife
    while(currentEvent.getType() != EventType::END)
    {
        currentEvent = eventList.getNextEvent();

    }

};

