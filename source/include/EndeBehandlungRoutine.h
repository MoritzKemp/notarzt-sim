#ifndef ENDEBEHANDLUNGROUTINE_H
#define ENDEBEHANDLUNGROUTINE_H

#include "EventRoutine.h"
#include "Notarzt.h"
#include "EventList.h"
#include "NotfallWarteschlange.h"

class EndeBehandlungRoutine : public EventRoutine
{
    public:
        EndeBehandlungRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			NotfallWarteschlange* notfallWarteschlange
		);
        virtual ~EndeBehandlungRoutine();
		void execute(Event* event);
    private:
		Notarzt* notarzt;
		EventList* eventList;
		NotfallWarteschlange* notfallWarteschlange;
};

#endif // ENDEBEHANDLUNGROUTINE_H
