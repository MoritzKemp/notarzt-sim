#ifndef RUECKFAHRTROUTINE_H
#define RUECKFAHRTROUTINE_H

#include "EventRoutine.h"
#include "Notarzt.h"
#include "EventList.h"
#include "Zufall.h"

/** \brief Routine für die Rückfahrt zur Zentrale
 *
 * Diese Routine beschreibt die Zustandsänderungen in 
 * der Notarzt-Simulation wenn der Notarzt sich
 * auf den Weg zurück zur Zentrale macht.
 */
class RueckfahrtRoutine : public EventRoutine{
	public:
		/** \brief Konstruktor
 		 * 
 		 * Abhängigkeiten werden injiziert und
 		 * eine spezielle EventRoutine mit dem
 		 * Event-Typ ABFAHRT_ZU_ZENTRALE wird erstellt.
 		 */
		RueckfahrtRoutine(
			Notarzt* notarzt,
			EventList* eventList,
			Zufall* randomGenerator
		);
		~RueckfahrtRoutine();
		/** \brief Spezifizierung der Zustandsänderungen
 		 * 
 		 * Die Rückfahrt des Arztes zur Zentrale ändert
 		 * den Zustand des Notarztes und generiert
 		 * ein neues Event, dass die Ankunft 
 		 * des Arztes in der Zentrale ankündigt.
 		 * Der Zeitpunkt, wann der Arzt in der Zentrale
 		 * ankommt, wird aus der stochastisch ermittelten 
 		 * Fahrtzeit und der aktuellen Simulationszeit 
 		 * berechnet.
 		 */
		void execute(Event* event);
	private:
		Notarzt* notarzt;
		EventList* eventList;
		Zufall* randomGenerator;
};

#endif
