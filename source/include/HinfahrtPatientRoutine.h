#ifndef HINFAHRTPATIENTROUTINE_H
#define HINFAHRTPATIENTROUTINE_H

#include <EventRoutine.h>
#include <Notarzt.h>
#include <EventList.h>
#include "NotfallWarteschlange.h"
#include "Zufall.h"

class HinfahrtPatientRoutine : public EventRoutine
{
    public:
        HinfahrtPatientRoutine(
			Notarzt* notarzt, 
			EventList* eventList, 
			NotfallWarteschlange* notfallWarteschlange,
			Zufall* randomGenerator
		);
        virtual ~HinfahrtPatientRoutine();
        void execute(Event* event);
    private:
        Notarzt* notarzt;
        EventList* eventList;
        NotfallWarteschlange* notfallWarteschlange;
		Zufall* randomGenerator;
};

#endif // HINFAHRTPATIENTROUTINE_H
