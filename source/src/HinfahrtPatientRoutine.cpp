#include "HinfahrtPatientRoutine.h"

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
    notarzt->setNotarztState(NotarztStates::UNTERWEGS_PATIENT);

    int travelTime = 3; // TODO correct estimation of travel time
    int arrivalTime = event->getExecutionTime() + travelTime;
    Event* newEvent = new Event(arrivalTime, EventType::ANKUNFT_PATIENT);
    eventList->addEvent(newEvent);
}
