#ifndef RUECKFAHRTROUTINE_H
#define RUECKFAHRTROUTINE_H

#include "EventRoutine.h"
#include "Notarzt.h"
#include "EventList.h"
#include "Zufall.h"

class RueckfahrtRoutine : public EventRoutine{
	public:
		RueckfahrtRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			Zufall* randomGenerator
		);
		~RueckfahrtRoutine();
		void execute(Event* event);
	private:
		Notarzt* notarzt;
		EventList* eventList;
		Zufall* randomGenerator;
};

#endif
