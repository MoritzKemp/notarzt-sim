#ifndef NEUERNOTRUFROUTINE_H
#define NEUERNOTRUFROUTINE_H

#include "EventRoutine.h"
#include "EventList.h"
#include "Notarzt.h"
#include "NotfallWarteschlange.h"
#include "Zufall.h"

/** \brief Routine für den Eingang eines Notrufes
 *
 * Diese Routine beschreibt die Zustandsänderungen 
 * in der Notarzt-Simulation wenn ein neuer 
 * Notfall in der Zentrale eintrifft.
 */
class NeuerNotrufRoutine : public EventRoutine
{
    public:
		/** \brief Konstruktor
 		 * 
 		 * Abhängigkeiten werden injiziert und eine spezielle
 		 * EventRoutine mit dem Event-Typ NEUER_NOTRUF wird erstellt.
 		 */
        NeuerNotrufRoutine(
            NotfallWarteschlange* n,
            Notarzt* arzt,
            EventList* eList,
			Zufall* randomGen
        );
        virtual ~NeuerNotrufRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 *
 		 * Trifft ein neuer Notruf in der Zentrale 
 		 * ein, so muss ein neuer Notfall erstellt
 		 * werden und der Simulation hinzugefügt werden,
 		 * indem der Notfall der NotfallWarteschlange 
 		 * hinzugefügt wird.
 		 * Die für die Erstellung eines Notfall benötigten
 		 * Attribute werden stochastisch ermittelt.
 		 * Des weiteren wird der akutelle Zustand des 
 		 * Notarztes überprüft und möglicherweise ein
 		 * Event generiert, dass den Notarzt anweist, 
 		 * den aktuellen Notfall zu behandeln.
 		 */ 
        void execute(Event* event);

    private:
        NotfallWarteschlange* notfallWarteschlange;
        Notarzt* notarzt;
        EventList* eventList;
		Zufall* randomGenerator;
};

#endif // NEUERNOTRUFROUTINE_H
