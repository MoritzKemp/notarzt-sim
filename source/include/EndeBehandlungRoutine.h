#ifndef ENDEBEHANDLUNGROUTINE_H
#define ENDEBEHANDLUNGROUTINE_H

#include "EventRoutine.h"
#include "Notarzt.h"
#include "EventList.h"
#include "NotfallWarteschlange.h"

/** \brief Routine für das Ende einer Behandlung eines Notfalls
 *
 * Diese Routine beschreibt die Zustandsänderungen in
 * der Notarzt-Simulation wenn die Behandlung eines Notfalls
 * abgeschlossen ist.
 */
class EndeBehandlungRoutine : public EventRoutine
{
    public:
		/** \brief Konstruktor
 		 * 
 		 * Abhängigkeiten werden injiziert und eine spezielle
 		 * EventRoutine mit dem Event-Typ ENDE_BEHANDLUNG wird erstellt.
 		 */ 
        EndeBehandlungRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			NotfallWarteschlange* notfallWarteschlange
		);
        virtual ~EndeBehandlungRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 *
 		 * Das Ende der Behandlung eines Notfalls bzw. Patienten
 		 * verändert den Zustand des Notarztes. Dabei muss zuerst
 		 * entschieden werden, ob der Notarzt gleich zu einem
 		 * weiterem Notfall fahren muss oder zurück in die 
 		 * Zentrale fährt.
 		 * Einentsprechendes Event entweder vom Typ ABFAHRT_ZU_PATIENT
 		 * oder ABFAHRT_ZU_ZENTRALE wird erstellt. Dieses abhängige 
 		 * Event (abhängig von ENDE_BEHANDLUNG) bekommt als Zeitpunkt
 		 * der Erscheinung den selben Zeitpunkt wie das Event vom
 		 * Typ ENDE_BEHANDLUNG, welches diese Routine ausgelöst hat.
 		 * Es passiert also in der Simulation augenblicklich ohne
 		 * Zeitverzögerung.
 		 */ 
		void execute(Event* event);
    private:
		Notarzt* notarzt;
		EventList* eventList;
		NotfallWarteschlange* notfallWarteschlange;
};

#endif // ENDEBEHANDLUNGROUTINE_H
