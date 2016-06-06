#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <list>
#include "Event.h"
using namespace std;

/** \brief Verwaltet Ereignisse
 *
 * Ereignisliste (engl. event list) für die 
 * diskrete, ereignisgesteuerte Simulation.
 * Die Ereignisliste ist ein Besatndteil jeder
 * ereignisgesteuerten Simulation und defniert das
 * nächste Ereignis der Simulation.
 * Ereignisse können hinzugefügt und wieder entfernt werden.
 * Die Liste sortiert die Ereignisse nach ihrer Ausführungszeit.
 *
 */
class EventList
{
	public:
		/** \brief Konstruktor 
 		*/ 
        EventList();
        ~EventList();

		/** \brief Nächstes Ereignis liefern und löschen
 		 * 
 		 * Liefert jenes Ereignis, dass von der Ausführungszeit
 		 * her das nächste Ereignis ist. Das Ereignis wird zugleich von
 		 * der Liste entfernt.
 		 */ 
        Event* popEvent();

		/** \brief Nächstes Ereignis liefern
 		 * 
 		 * Liefert jenes Ereignis, dass von der Ausführungszeit
 		 * her das nächste Ereignis ist. Kein Löschen, d.h.
 		 * der wiederholte Aufruf liefert das gleiche Ereignis.
 		 */ 
		Event* getNextEvent();

		/** \brief Löscht das nächste Ereignis eines bestimmten Types
 		 * 
 		 * Löscht jenes Ereignis aus der Ereignisliste, dass 
 		 * den selben Typ entspricht wie im übergebenem Parameter. 
 		 * Löscht NICHT alle Events dieses Typs, sondern nur jenes von
 		 * dem Typ, das als nächstes zur Ausführung kommen würde.
 		 *
 		 * Gibt zurück, ob ein Event gelöscht wurde (1) oder nicht (0)
 		 */
		int removeEventByType(EventType type);

		/** \brief Ereignis hinzufügen
 		 * 
 		 * Fügt das übergebene Event der Ereignisliste hinzu und
 		 * sortiert es in die richtige Stelle ein. Die Liste bleibt
 		 * somit sortiert.
 		 */
		void addEvent(Event* event);

		/** \brief Drucken der aktuellen Liste auf die Ausgabe
 		*/
		void printList();

	private:
		list<Event*> eventList;

};
#endif
