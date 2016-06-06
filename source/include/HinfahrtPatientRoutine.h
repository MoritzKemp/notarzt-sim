#ifndef HINFAHRTPATIENTROUTINE_H
#define HINFAHRTPATIENTROUTINE_H

#include <EventRoutine.h>
#include <Notarzt.h>
#include <EventList.h>
#include "NotfallWarteschlange.h"
#include "Zufall.h"

/** \brief Routine für den Beginn der Hinfahrt zum Patienten/Notfall
 * 
 * Diese Routine beschreibt die Zustandsänderungen in der
 * Notarzt-Simulation wenn der Notarzt den Weg zum
 * Patienten/Notfall einschlägt.
 */
class HinfahrtPatientRoutine : public EventRoutine
{
    public:
		/** \brief Konstruktor
 		 * 
 		 * Abhängigkeiten werden injiziert und eine spezielle
 		 * EventRoutine mit dem Event-Typ ABFAHRT_ZU_PATIENT wird erstellt.
 		 */
        HinfahrtPatientRoutine(
			Notarzt* notarzt, 
			EventList* eventList, 
			NotfallWarteschlange* notfallWarteschlange,
			Zufall* randomGenerator
		);
        virtual ~HinfahrtPatientRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 * 
 		 * Das Losfahren des Notarztes zum Patienten verändert
 		 * den Zustand des Notarztes und berechnet die die Ankunftzeit
 		 * beim Patienten, um ein neues Event mit dem Typ ANKUNFT_PATIENT
 		 * zu erstellen.
 		 * Die Berechnung der Ankunftzeit geht aus einer stochastisch
 		 * ermittelten Fahrtzeit und der aktuellen Simulationszeit
 		 * hervor.
 		 * Zudem wird ein mögliches Ereignis gelöscht, das die Ankunft
 		 * des Notarztes in der Zentrale ankündigt. Dies ist dann
 		 * der Fall, wenn diese Routine aufgerufen wird, während
 		 * sich der Notarzt auf dem Rückweg zur Zentrale befindet,
 		 * also ein Notfall mit hoher Priorität eingegangen ist.
 		 */
        void execute(Event* event);

    private:
        Notarzt* notarzt;
        EventList* eventList;
        NotfallWarteschlange* notfallWarteschlange;
		Zufall* randomGenerator;
};

#endif // HINFAHRTPATIENTROUTINE_H
