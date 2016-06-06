#ifndef ANKUNFTZENTRALEROUTINE_H
#define ANKUNFTZENTRALEROUTINE_H

#include "Notarzt.h"
#include "NotfallWarteschlange.h"
#include "EventList.h"
#include "EventRoutine.h"

/** \brief Routine für die Ankunft des Notarztes in der Zentrale
 *
 * Diese Routine beschreibt die Zustandsänderungen in der
 * Notarzt-Simulation wenn der Notarzt in der Zentrale ankommt.
 */
class AnkunftZentraleRoutine : public EventRoutine{
	
	public:
		/** \brief Konstruktor
 		 * 
 		 * Abhängigkeiten werden injiziert eine 
 		 * spezielle EventRoutine mit dem Event-Typ
 		 * ANKUNFT_ZENTRALE wird erstellt.
 		 */
		AnkunftZentraleRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			NotfallWarteschlange* notfallWarteschlange
		);
		~AnkunftZentraleRoutine();

		/** \brief Spezifizierung der Zustandsänderungen
 		 * 
 		 * Die Ankunft des Notarztes in der Zentrale verändert
 		 * den Zustand des Notarztes auf wartend und erzeugt bei
 		 * bei Bedarf ein neues Event. Das neue Event vom Typ Abfahrt_Patient
 		 * ist abhängig davon, ob bereits ein weiterer Notfall vorliegt oder nicht.
 		 */
		void execute(Event* event);
	
	private:
		Notarzt* notarzt;
		EventList* eventList;
		NotfallWarteschlange* notfallWarteschlange;
};

#endif

