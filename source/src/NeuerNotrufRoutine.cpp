#include "NeuerNotrufRoutine.h"
#include <iostream>
NeuerNotrufRoutine::NeuerNotrufRoutine(
    NotfallWarteschlange* n,
    Notarzt* arzt,
    EventList* eList,
    StateStorage* storage
)
    : EventRoutine(EventType::NEUER_NOTRUF)
{
    notfallWarteschlange = n;
    notarzt = arzt;
    eventList = eList;
    stateStorage = storage;
}

NeuerNotrufRoutine::~NeuerNotrufRoutine()
{
    //dtor
}

void NeuerNotrufRoutine::execute(Event* event)
{
    cout << "Running routine for new emergency call." << endl;
    // Notfall zur Notfall-Warteschlange hizufügen
    int callTime = event->getExecutionTime();
    int isUrgent = 0;
    int treathmentDuration = 12;

    Notfall* neuerNotfall = new Notfall(callTime, isUrgent, treathmentDuration);
    notfallWarteschlange->add(neuerNotfall);

    //Überprüfe, ob Arzt auf Rückweg oder Wartend ist. Wenn ja, dann füge
    //ein Event zur Hinfahrt zum Patienten hinzu, das augeblicklich passiert
    if(
        notarzt->getNotarztState() == NotarztStates::WARTEND
        || notarzt->getNotarztState() == NotarztStates::UNTERWEGS_ZENTRALE
    ){

        Event* newEvent = new Event(event->getExecutionTime(), EventType::ABFAHRT_ZU_PATIENT);
        cout << "Add new emergency: "<< (int)newEvent->getType()<< endl;
        eventList->addEvent(newEvent);
    }
}
