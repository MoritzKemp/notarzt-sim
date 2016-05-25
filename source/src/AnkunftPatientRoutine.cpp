#include "AnkunftPatientRoutine.h"
#include "EventType.h"
#include "Notfall.h"
#include <iostream>

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
    cout << "Running routine for arrival at patient." << endl;
    // 1. Änder ZUstand vom Notarzt auf "Behandlung"
    notarzt->setNotarztState(NotarztStates::BEHANDLUNG);

    // 2. Setzte Ereignis für das Ende der Behandlung
    // 2.1 Hole den Notruf, der behandelt wird.
    // Gleichzeitiges Entfernen des Notfalls
    Notfall* behandelterNotfall = notfallWarteschlange->pop();

    // 2.2 Berechne den Zeitpunkt des Behandlungsende
    int zeitBehandlungsende = event->getExecutionTime() + behandelterNotfall->getTreatmentDuration();
    Event* endeBehandlung = new Event(zeitBehandlungsende, EventType::ENDE_BEHANDLUNG);

    eventList->addEvent(endeBehandlung);
}

