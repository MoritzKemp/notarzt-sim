/**
 * Ereignisliste für die diskrete,
 * eventgesteruerte Simulation.
 */
#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <list>
#include "Event.h"
using namespace std;

class EventList
{
	private:
		list<Event*> eventList;

	public:
        EventList();
        ~EventList();
		Event* getNextEvent();
		void addEvent(Event* event);
		void removeEvent(Event* event);
		void printList();
};
#endif
