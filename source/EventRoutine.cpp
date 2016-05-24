#include "EventRoutine.h"
#include <iostream>

EventRoutine::EventRoutine(EventType eventType){
	EventRoutine::type = eventType;
};

EventRoutine::~EventRoutine()
{
};

EventType EventRoutine::getType()
{
    return type;
};
