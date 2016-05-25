/**
 * Implementierung eines allgemeinen Ereignises
 * im Rahmen der diskreten, ereignisgesteureten
 * Simulation.
 */

#include "Event.h"

Event::Event(int exeTime, EventType t)
{
	executionTime = exeTime;
    type = t;
};

Event::~Event()
{
};

int Event::getExecutionTime()
{
	return executionTime;
};

EventType Event::getType()
{
	return type;
};

