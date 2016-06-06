#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "EventList.h"
#include "EventRoutine.h"
#include "StateStorage.h"

/** \brief Steuert die Simulation
 * 
 * Objekte dieser Klasse sind verantwortlich
 * für den grundsätlichen Ablauf einer
 * diskreten, ereignisgesteuerten Simulation.
 * Diese besteht aus eine Initialisierungspahse,
 * wo die initale Ereignisliste mit den initialen
 * Ereignissen gefüllt wird.
 * Anschließend beginnt die Simulationsschleife
 * zu laufen. 
 */
class SimulationManager
{

    public:
		/** \brief Konstruktor
 		 * 
 		 */
    	SimulationManager(
        	EventList* eList,
        	EventRoutine* roList[],
        	int numRoutines,
        	StateStorage* storage
    	);
    	~SimulationManager();
    	void run(Event* initlaEvents[], int sizeEvents, int endTime);

	
    private:
    	EventList* eventList;
    	EventRoutine** routineList;
    	StateStorage* stateStorage;
    	int numOfRoutines;
    	void executeEvent(Event *event);
};

#endif
