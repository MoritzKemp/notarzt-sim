
#include "RueckfahrtRoutine.h"
#include <iostream>
#include "Event.h"

RueckfahrtRoutine::RueckfahrtRoutine(
	Notarzt* arzt,
	EventList* eList,
	Zufall* random
)
	: EventRoutine(EventType::ABFAHRT_ZU_ZENTRALE)
{
	notarzt = arzt;
	eventList = eList;
	randomGenerator = random;
}

RueckfahrtRoutine::~RueckfahrtRoutine()
{}

void RueckfahrtRoutine::execute(Event* event)
{
	std::cout << "Running routine for traveling back home" << std::endl;
	// 1. Ankunftszeit stochastisch berechnen (Standort 0 ist Zentrale)
	int travelTime = randomGenerator->Fahrzeit(notarzt->getNotarztPlace(), 0);
	int currentTime = event->getExecutionTime();
	int arrivalTime = travelTime + currentTime;

	// 2. Ankunfts-Event erstellen und der Simulation hinzufügen
	Event* newEvent = new Event(arrivalTime, EventType::ANKUNFT_ZENTRALE);
	eventList->addEvent(newEvent);
	
	// 3. Zustand des Notarztes ändern
	notarzt->setNotarztState(NotarztStates::UNTERWEGS_ZENTRALE);
}
