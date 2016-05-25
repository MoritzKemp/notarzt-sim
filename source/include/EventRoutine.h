/*
 * Implementierung einer Ereignisroutine
 * für die diskrete, eventgesteuerte Simulation.
 */
#ifndef EVENT_ROUTINE_H
#define EVENT_ROUTINE_H

#include "Event.h"
#include "EventType.h"

class EventRoutine{
	private:
	EventType type;

	public:
	EventRoutine(EventType type);
    virtual ~EventRoutine();
	virtual void execute(Event* event) = 0;
    EventType getType();
};
#endif