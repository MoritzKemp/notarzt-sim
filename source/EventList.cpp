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

Event* EventList::getNextEvent()
{
    return *eventList.end();
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
        time_t currTime_1 = mktime(currentEvent->getExecutionTime());
        time_t evTime_1 = mktime(event->getExecutionTime());
        std::cout << difftime(currTime_1, evTime_1) << std::endl;
		if(
            difftime(currTime_1, evTime_1) > 0
        ){
			iter++;
		} else {
			found = 1;
		}
	}
	// 2. Insert event
	eventList.insert(iter, event);
};

void EventList::removeEvent(Event* event)
{
};

void EventList::printList()
{
	list<Event*>::iterator iter;
    Event* currentEvent;
    char timeBuff[80];
    int count = 1;
	for(iter = eventList.begin(); iter != eventList.end(); iter++)
	{
        currentEvent = *iter;
        strftime(timeBuff, 80, "%Y-%m-%d %H:%M:%S", currentEvent->getExecutionTime());
        cout << "[" << count << "] " ;
		cout << "Event execution on: "<< timeBuff<< " ";
		cout << "Event type: "<< (int)currentEvent->getType() << endl;
		count++;
	}
};
