#ifndef ANKUNFTPATIENTROUTINE_H
#define ANKUNFTPATIENTROUTINE_H

#include <EventRoutine.h>
#include "Notarzt.h"
#include "EventList.h"
#include "NotfallWarteschlange.h"

class AnkunftPatientRoutine : public EventRoutine
{
    public:
        AnkunftPatientRoutine(
            Notarzt* arzt,
            EventList* eList,
            NotfallWarteschlange* warteschlange
        );
        virtual ~AnkunftPatientRoutine();
        void execute(Event* event);
    private:
        Notarzt* notarzt;
        EventList* eventList;
        NotfallWarteschlange* notfallWarteschlange;
};

#endif // ANKUNFTPATIENTROUTINE_H
