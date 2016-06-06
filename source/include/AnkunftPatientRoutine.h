#ifndef ANKUNFTPATIENTROUTINE_H
#define ANKUNFTPATIENTROUTINE_H

#include <EventRoutine.h>
#include "Notarzt.h"
#include "EventList.h"
#include "NotfallWarteschlange.h"

/** \brief Routine für die Ankunft des Notarztes beim Patienten
 *
 * Diese Routine beschreibt die Zustandsänderungen in 
 * der Notarzt-Simulation
 * wenn der Notarzt beim Patienten ankommt.
 *
 */
class AnkunftPatientRoutine : public EventRoutine
{
    public:
		/** \brief Konstruktor
 		 *
 		 * Abhängigkeiten werden injiziert und
 		 * eine spezielle EventRoutine mit
 		 * dem Event-Typ ANKUNF_PATIENT wird erstellt.
 		 */
        AnkunftPatientRoutine(
            Notarzt* arzt,
            EventList* eList,
            NotfallWarteschlange* warteschlange
        );
        virtual ~AnkunftPatientRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 *
 		 * Die Ankunft des Notarztes beim Patienten 
 		 * verändert den Zustand des Notarztes und entfernt
 		 * den zugehörigen Notfall, der nun behandelt wird,
 		 * aus der Notfall-Warteschlange.
 		 * Ein neues Event für das Ende der Behandlung
 		 * wird der Simulation hinzugefügt, der Zeitpunkt
 		 * dieses Events entsprechend berechnet.
 		 */
        void execute(Event* event);
    private:
        Notarzt* notarzt;
        EventList* eventList;
        NotfallWarteschlange* notfallWarteschlange;
};

#endif // ANKUNFTPATIENTROUTINE_H
