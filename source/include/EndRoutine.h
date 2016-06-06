#ifndef ENDROUTINE_H
#define ENDROUTINE_H

#include <EventRoutine.h>
#include "EventType.h"

/** \brief Routine für das Ende der Simulation
 *
 * Diese Routine verändert keine Objekte 
 * in der Simulation sondern dient der Kontrolle
 * der Simulationsschleife. Die Simulationsschleife
 * bricht ab (und beendet somit die Simulation) sobald
 * diese Routine ausgeführt werden soll.
 */
class EndRoutine : public EventRoutine
{
    public:
		/** \brief Konstruktor
 		 * Erstellt eine spzeielle EventRoutine 
 		 * mit dem Event-Typ ENDE.
 		 */ 
        EndRoutine();
        virtual ~EndRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 *
 		 * Keine Änderung an Objekten der Simulation. 
 		 */ 
        void execute(Event* event);
};

#endif // ENDROUTINE_H
