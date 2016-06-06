#ifndef EVENT_ROUTINE_H
#define EVENT_ROUTINE_H

#include "Event.h"
#include "EventType.h"

/** \brief Abstrakte Erignis-Routine
 *
 * Abstrakte Klasse für die minimale Definition
 * einer Ereignisroutine in einer
 * diskreten, eventgesteuerten Simulation.
 */
class EventRoutine{

	public:
		/** \brief Konstruktor
 		 * 
 		 * Eine Routine besitzt immer einen spezifischen
 		 * Typ, der von der Art der Simulation abhängig ist.
 		 * Dieser Typ ermöglich der Simulationsschleife,
 		 * die passende Routine zu einem Event zu finden.
 		 */
		EventRoutine(EventType type);
    	virtual ~EventRoutine();

		/** \brief Funktionssignatur Ausführung einer Routine
 		 *	
 		 *	Abstrakte Funktion, die die Erwartungshaltung
 		 *	an alle implementierten Ereignisroutinen definiert.
 		 *	Das ermöglicht eine allgemeine Definition der Simulationsschleife
 		 *	ohne dass spezielle Wissen über die implementierten
 		 *	Ereignisroutinen notwendig ist.
 		 *
 		 *	Muss von jeder spezialisierenden Klasse implementiert werden
 		 */
		virtual void execute(Event* event) = 0;

		/** \brief Liefert Ereignistyp
 		 * 
 		 * Fertig implementierte Funtkion zur Rückgabe des Eriegnistyps.
 		 */ 
   		EventType getType();
	
	private:
		EventType type;
};
#endif
