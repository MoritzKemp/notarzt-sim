#include "HinfahrtPatientRoutine.h"
#include  <iostream>

HinfahrtPatientRoutine::HinfahrtPatientRoutine(
    Notarzt* n,
    EventList* l,
    NotfallWarteschlange* warteschlange
) : EventRoutine(EventType::ABFAHRT_ZU_PATIENT)
{
    notarzt = n;
    eventList = l;
    notfallWarteschlange = warteschlange;
}

HinfahrtPatientRoutine::~HinfahrtPatientRoutine()
{
    //dtor
}

void HinfahrtPatientRoutine::execute(Event* event)
{
	std::cout << "Running routine for traveling to patient" << endl;
    notarzt->setNotarztState(NotarztStates::UNTERWEGS_PATIENT);

    int travelTime = 3; // TODO correct estimation of travel time
    int arrivalTime = event->getExecutionTime() + travelTime;
    Event* newEvent = new Event(arrivalTime, EventType::ANKUNFT_PATIENT);
	
	//Lösche das mögliche Ankunft-Event des Notarztes bei der Zentrale
	eventList->removeEventByType(EventType::ANKUNFT_ZENTRALE);

    eventList->addEvent(newEvent);
}
