#include "EndeBehandlungRoutine.h"
#include "EventType.h"
#include "Notfall.h"
#include <iostream>

EndeBehandlungRoutine::EndeBehandlungRoutine(
	Notarzt* n,
	EventList* evList,
	NotfallWarteschlange* notWarte
)
    : EventRoutine(EventType::ENDE_BEHANDLUNG)
{
    notarzt = n;
	eventList = evList;
	notfallWarteschlange = notWarte;
}

EndeBehandlungRoutine::~EndeBehandlungRoutine()
{
    //dtor
}

void EndeBehandlungRoutine::execute(Event* event)
{
	cout << "Running routine for finish treatment" << endl;
	
	// 1. Entscheidung, ob zurück zur Zentrale oder zu neuem Notfall
	Notfall* notfall = notfallWarteschlange->front();
	Event* newEvent;
	if( notfall )
	{
		newEvent = new Event(event->getExecutionTime(), EventType::ABFAHRT_ZU_PATIENT);
	} else 
	{
		newEvent = new Event(event->getExecutionTime(), EventType::ABFAHRT_ZU_ZENTRALE);
	}
	
	eventList->addEvent(newEvent);
}


