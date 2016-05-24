#include "AnkunftPatientRoutine.h"
#include "EventType.h"

AnkunftPatientRoutine::AnkunftPatientRoutine(
    Notarzt* arzt,
    EventList* eList,
    NotfallWarteschlange* warteschlange
)
    : EventRoutine(EventType::ANKUNFT_PATIENT)
{
    notarzt = arzt;
    eventList = eList;
    notfallWarteschlange = warteschlange;
}

AnkunftPatientRoutine::~AnkunftPatientRoutine()
{
    //dtor
}

void AnkunftPatientRoutine::execute(Event* event)
{
    notarzt->setNotarztState(NotarztStates::BEHANDLUNG);

}

