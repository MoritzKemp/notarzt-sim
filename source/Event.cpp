/**
 * Implementierung eines allgemeinen Ereignises
 * im Rahmen der diskreten, ereignisgesteureten
 * Simulation.
 */

#include "Event.h"

Event::Event(struct tm *exeTime, EventType t)
{
	executionTime = exeTime;
    type = t;
};

Event::~Event()
{
};

struct tm* Event::getExecutionTime()
{
	return executionTime;
};

EventType Event::getType()
{
	return type;
};

