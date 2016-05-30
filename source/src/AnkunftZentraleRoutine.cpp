
#include <iostream>
#include "AnkunftZentraleRoutine.h"
#include "Notfall.h"
#include "Event.h"

AnkunftZentraleRoutine::AnkunftZentraleRoutine(
	Notarzt* arzt,
	EventList* eList,
	NotfallWarteschlange* warteschlange
)
	:EventRoutine(EventType::ANKUNFT_ZENTRALE)
{
	notarzt = arzt;
	eventList = eList;
	notfallWarteschlange = warteschlange;
}

AnkunftZentraleRoutine::~AnkunftZentraleRoutine()
{}

void AnkunftZentraleRoutine::execute(Event* event)
{
	std::cout << "Running routine for arrival at home" << std::endl;
	// 1. Zustand vom Notarzt ändern
	notarzt->setNotarztPlace(0);
	notarzt->setNotarztState(NotarztStates::WARTEND);
	notarzt->setTimestamp(event->getExecutionTime());

	// 2. Entscheidung, ob direkt zum nächsten Notruf oder warten
	Notfall* notfall = notfallWarteschlange->front();
	if( notfall )
	{
		Event* newEvent = new Event(event->getExecutionTime(), EventType::ABFAHRT_ZU_PATIENT);
		eventList->addEvent(newEvent);
	}
	
}
