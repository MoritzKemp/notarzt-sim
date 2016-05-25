
#include <stdlib.h>
#include <iostream>

#include "Event.h"
#include "EventList.h"
#include "SimulationManager.h"
#include "StateStorage.h"
#include "EndRoutine.h"
#include "NeuerNotrufRoutine.h"
#include "NotfallWarteschlange.h"
#include "HinfahrtPatientRoutine.h"
#include "AnkunftPatientRoutine.h"

using namespace std;

int main(int argv, char** argc)
{
    //Initial simulation objects
    EventList* eventList = new EventList();
    Notarzt* notarzt = new Notarzt(0, NotarztStates::WARTEND, NotarztPlace::STADTVIERTEL_0);

    //Initalize storage
    StateStorage* storage = new StateStorage();
    storage->registerObject(notarzt);

    NotfallWarteschlange* notfallWarteschlange = new NotfallWarteschlange(storage);

    // Initiale events
    int numInitialEvents = 3;
    Event* events[numInitialEvents];
    events[0] = new Event(3, EventType::NEUER_NOTRUF);
    events[1] = new Event(44, EventType::NEUER_NOTRUF);
    events[2] = new Event(32, EventType::NEUER_NOTRUF);

    // Routines
    int numOfRoutines = 4;
    EventRoutine* routines[numOfRoutines];
    routines[0] = new NeuerNotrufRoutine(notfallWarteschlange, notarzt, eventList, storage);
    routines[1] = new HinfahrtPatientRoutine(notarzt, eventList, notfallWarteschlange);
    routines[2] = new AnkunftPatientRoutine(notarzt, eventList, notfallWarteschlange);
    routines[3] = new EndRoutine(EventType::END);

    SimulationManager* simulationManager = new SimulationManager(
        eventList,
        routines,
        numOfRoutines,
        storage
    );
    simulationManager->run(events, numInitialEvents, 90);

    notfallWarteschlange->printList();
};
