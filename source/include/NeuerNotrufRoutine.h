#ifndef NEUERNOTRUFROUTINE_H
#define NEUERNOTRUFROUTINE_H

#include "EventRoutine.h"
#include "EventList.h"
#include "Notarzt.h"
#include "NotfallWarteschlange.h"
#include "Zufall.h"

class NeuerNotrufRoutine : public EventRoutine
{
    public:
        NeuerNotrufRoutine(
            NotfallWarteschlange* n,
            Notarzt* arzt,
            EventList* eList,
			Zufall* randomGen
        );
        virtual ~NeuerNotrufRoutine();
        void execute(Event* event);
    private:
        NotfallWarteschlange* notfallWarteschlange;
        Notarzt* notarzt;
        EventList* eventList;
		Zufall* randomGenerator;
};

#endif // NEUERNOTRUFROUTINE_H
