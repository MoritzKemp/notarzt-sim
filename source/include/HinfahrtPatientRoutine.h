#ifndef HINFAHRTPATIENTROUTINE_H
#define HINFAHRTPATIENTROUTINE_H

#include <EventRoutine.h>
#include <Notarzt.h>
#include <EventList.h>
#include "NotfallWarteschlange.h"

class HinfahrtPatientRoutine : public EventRoutine
{
    public:
        HinfahrtPatientRoutine(Notarzt* n, EventList* l, NotfallWarteschlange* warteschlange);
        virtual ~HinfahrtPatientRoutine();
        void execute(Event* event);
    private:
        Notarzt* notarzt;
        EventList* eventList;
        NotfallWarteschlange* notfallWarteschlange;
};

#endif // HINFAHRTPATIENTROUTINE_H
