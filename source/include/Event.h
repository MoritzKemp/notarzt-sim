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
	struct tm *executionTime;
	EventType type;

	public:
	Event(struct tm *executionTime, EventType type);
    ~Event();
	struct tm* getExecutionTime();
	EventType getType();
};
#endif
