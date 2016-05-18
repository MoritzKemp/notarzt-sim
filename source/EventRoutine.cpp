#include "EventRoutine.h"
#include <iostream>

EventRoutine::EventRoutine(EventType eventType){
	EventRoutine::type = eventType;
};

EventRoutine::~EventRoutine()
{
};

void EventRoutine::execute()
{
    std::cout << "Execute routine type: " << (int)type << std::endl;
};

EventType EventRoutine::getType()
{
    return type;
};
