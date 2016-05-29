/**
 * Ereignisliste für die diskrete,
 * eventgesteruerte Simulation.
 */


#include "EventList.h"
#include <iostream>

EventList::EventList()
{};

EventList::~EventList()
{};

Event* EventList::popEvent()
{
    Event* event = eventList.front();
    eventList.pop_front();
    return event;
};

Event* EventList::getNextEvent()
{
    return *eventList.begin();
};

void EventList::addEvent(Event* event)
{
	// 1. Find insert location by execution time
	int found = 0;
    Event* currentEvent;
	list<Event*>::iterator iter = eventList.begin();

	while(iter != eventList.end() && found == 0)
	{
        currentEvent = *iter;
        int currTime_1 = currentEvent->getExecutionTime();
        int evTime_1 = event->getExecutionTime();

		if(currTime_1 < evTime_1){
			iter++;
		} else {
			found = 1;
		}
	}
	// 2. Insert event
	eventList.insert(iter, event);
};

int EventList::removeEventByType(EventType type)
{
	// 1. Search event in list
	int found = 0;
    Event* currentEvent;
	list<Event*>::iterator iter = eventList.begin();

	while(iter != eventList.end() && found == 0)
	{
        currentEvent = *iter;
		if(currentEvent->getType() == type){
			found=1;
			// 2. Remove event
			eventList.erase(iter);
		} else {
			iter++;
		}
	}

	return found;
}

void EventList::printList()
{
	list<Event*>::iterator iter;
    Event* currentEvent;
    int count = 1;
    cout << "Current event list content: "<< endl;
	for(iter = eventList.begin(); iter != eventList.end(); iter++)
	{
        currentEvent = *iter;
        cout << "[" << count << "] " ;
		cout << "Event execution on: "<< currentEvent->getExecutionTime() << " ";
		cout << "Event type: "<< (int)currentEvent->getType() << endl;
		count++;
	}
	cout << endl;
};
