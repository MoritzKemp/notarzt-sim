/**
 * Implementierung eines allgemeinen Ereignises
 * im Rahmen der diskreten, ereignisgesteureten
 * Simulation.
 */
#ifndef EVENT_H
#define EVENT_H

#include <time.h>
#include "EventType.h"

class Event
{
	private:
	int executionTime;
	EventType type;

	public:
	Event(int executionTime, EventType type);
    ~Event();
	int getExecutionTime();
	EventType getType();
};
#endif
