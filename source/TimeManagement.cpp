
#include "TimeManagement.h"
#include "Event.h"

TimeManagement::TimeManagement(EventList* evList, EventRoutine* r[], int sizeRoutines)
{
    eventList = evList;
    routines = r;
};

TimeManagement::~TimeManagement()
{
    delete(eventList);
    for(int i=0; i<numOfRoutines; i++)
    {
        delete routines[i];
    }
};

void TimeManagement::executeNextEvent()
{
    Event*  nextEvent = eventList->getNextEvent();
    int routineFound = 0;
    int i = 0;

    while(!routineFound)
    {
        if(routines[i].getType() == nextEvent->getType())
        {
            routineFound = 1;
        } else
        {
            i++;
        }
    }

    if(routineFound)
    {
        routines[i].execute();
    }
};
