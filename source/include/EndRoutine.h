#ifndef ENDROUTINE_H
#define ENDROUTINE_H

#include <EventRoutine.h>
#include "EventType.h"

class EndRoutine : public EventRoutine
{
    public:
        EndRoutine(EventType t);
        virtual ~EndRoutine();
        void execute(Event* event);
};

#endif // ENDROUTINE_H
