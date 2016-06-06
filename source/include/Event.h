/**
 * Implementierung eines allgemeinen Ereignises
 * im Rahmen der diskreten, ereignisgesteureten
 * Simulation.
 */
#ifndef EVENT_H
#define EVENT_H

#include <time.h>
#include "EventType.h"

/** \brief Klasse für die Erstellung von Ereignissen
 *
 * Implementierung eines Ereignisses (engl. Event) im Rahmen 
 * der diskreten, ereignisgesteuerten Simulation.
 */

class Event
{

	public:
		/** \brief Konstruktor
 		 *
 		 * Erstellt ein Event-Objekt zur Verwendung innerhalb einer
 		 * Simulation (bsp. durch das Hinzufügen zur EventList).
 		 * Die Angabe von Ausführungszeit und Typ sind notwendig,
 		 * um die Behandlung des Events im Rahmen der Simulationsschleife
 		 * zu ermöglichen. Üblicherweise sollte es auch eine
 		 * EventRoutine mit dem entsprechendem Typ existieren.
 		 *
 		 */ 
		Event(int executionTime, EventType type);
    	~Event();
		
		/** \brief Rückgabe der Ausführungszeit
 		 */
		int getExecutionTime();

		/** \brief Rückgabe des Event-Types
 		 */ 
		EventType getType();
	
	private:
		int executionTime;
		EventType type;
};
#endif
