#include "EndRoutine.h"
#include "EventType.h"
#include <iostream>

EndRoutine::EndRoutine() : EventRoutine(EventType::END)
{}

EndRoutine::~EndRoutine()
{}

void EndRoutine::execute(Event* event)
{
    std::cout << "Execute END routine" << std::endl;
}
