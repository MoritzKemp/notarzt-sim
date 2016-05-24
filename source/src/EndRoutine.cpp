#include "EndRoutine.h"
#include <iostream>

EndRoutine::EndRoutine(EventType t) : EventRoutine(t)
{}

EndRoutine::~EndRoutine()
{}

void EndRoutine::execute(Event* event)
{
    std::cout << "Execute END routine" << std::endl;
}
