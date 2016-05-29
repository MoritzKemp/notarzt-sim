#ifndef ANKUNFTZENTRALEROUTINE_H
#define ANKUNFTZENTRALEROUTINE_H

#include "Notarzt.h"
#include "NotfallWarteschlange.h"
#include "EventList.h"
#include "EventRoutine.h"

class AnkunftZentraleRoutine : public EventRoutine{
	
	public:
		AnkunftZentraleRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			NotfallWarteschlange* notfallWarteschlange
		);
		~AnkunftZentraleRoutine();
		void execute(Event* event);
	
	private:
		Notarzt* notarzt;
		EventList* eventList;
		NotfallWarteschlange* notfallWarteschlange;
};

#endif

