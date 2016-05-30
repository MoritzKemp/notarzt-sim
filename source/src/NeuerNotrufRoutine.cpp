#include "NeuerNotrufRoutine.h"
#include <iostream>

NeuerNotrufRoutine::NeuerNotrufRoutine(
    NotfallWarteschlange* n,
    Notarzt* arzt,
    EventList* eList,
    StateStorage* storage,
	Zufall* randomGen
)
    : EventRoutine(EventType::NEUER_NOTRUF)
{
    notfallWarteschlange = n;
    notarzt = arzt;
    eventList = eList;
    stateStorage = storage;
	randomGenerator = randomGen;
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

	// Zufallsvariable für die Priorität und die Versorgungsdauer ermitteln
    int isUrgent;
    int treatmentDuration;
	int place;
	isUrgent = randomGenerator->getPrio();
	treatmentDuration = randomGenerator->versorgungszeit(isUrgent);
	place = randomGenerator->getStadtbezirk();

	cout << "-- Finish fetching stochastic data" << endl;

	// Notfall mit den zuvor ermittelten Daten der Simulation hinzufügen
    Notfall* neuerNotfall = new Notfall(callTime, isUrgent, treatmentDuration, place);
    notfallWarteschlange->add(neuerNotfall);
	
	cout << "-- Add emergency to list" << endl;

    //Überprüfe, ob Arzt auf Rückweg oder Wartend ist. Wenn ja, dann füge
    //ein Event zur Hinfahrt zum Patienten hinzu, das augeblicklich passiert
    if(
        notarzt->getNotarztState() == NotarztStates::WARTEND
        || notarzt->getNotarztState() == NotarztStates::UNTERWEGS_ZENTRALE
    ){

        Event* newEvent = new Event(event->getExecutionTime(), EventType::ABFAHRT_ZU_PATIENT);
        eventList->addEvent(newEvent);
    }
    cout << "Add new emergency" <<  endl;
}
