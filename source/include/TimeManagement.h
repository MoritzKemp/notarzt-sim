#ifndef TIME_MANAGEMENT_H
#define TIME_MANAGEMENT_H

#include "EventRoutine.h"
#include "EventList.h"

class TimeManagement
{
    private:
        EventList* eventList;
        EventRoutine *routines;
        int numOfRoutines;
        TimeManagement(EventList* evList, EventRoutine* r[], int sizeRoutines);
        ~TimeManagement();

    public:
        void executeNextEvent();
        static TimeManagement *getInstance();
};
#endif
