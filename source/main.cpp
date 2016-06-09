
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Event.h"
#include "EventList.h"
#include "SimulationManager.h"
#include "StateStorage.h"
#include "EndRoutine.h"
#include "NeuerNotrufRoutine.h"
#include "NotfallWarteschlange.h"
#include "HinfahrtPatientRoutine.h"
#include "AnkunftPatientRoutine.h"
#include "EndeBehandlungRoutine.h"
#include "RueckfahrtRoutine.h"
#include "AnkunftZentraleRoutine.h"
#include "Zufall.h"
#include "Nachberechnungen.h"

using namespace std;

int main(int argv, char** argc)
{

	//Simulation parameters
	int endOfSimulation = 9000;
	int verbose = 0;

    //Initial simulation objects
    EventList* eventList = new EventList();
    Notarzt* notarzt = new Notarzt(NotarztStates::WARTEND, 0);

    //Initalize storage
    StateStorage* storage = new StateStorage(verbose);
    storage->registerNotarzt(notarzt);

	//Initialize simulation analysis component
	Nachberechnungen nachberechnungen = Nachberechnungen();

    NotfallWarteschlange* notfallWarteschlange = new NotfallWarteschlange(storage);

	// Get stochastic data for emergency call time
	Zufall* randomGenerator = new Zufall();
	vector<int> *callArrivals = new vector<int>();
	int numArrivals;
	randomGenerator->getRandomExpNotruf(endOfSimulation, callArrivals, &numArrivals);
	
    Event* events[numArrivals];

	int eventIter=0;
	for(vector<int>::iterator iter = callArrivals->begin(); iter != callArrivals->end(); iter++)
	{
		events[eventIter++] = new Event(*iter, EventType::NEUER_NOTRUF);
	}
	cout << endl;

    // Routines
    int numOfRoutines = 7;
    EventRoutine* routines[numOfRoutines];
    routines[0] = new NeuerNotrufRoutine(
		notfallWarteschlange, 
		notarzt, 
		eventList, 
		randomGenerator
	);
    routines[1] = new HinfahrtPatientRoutine(
		notarzt, 
		eventList, 
		notfallWarteschlange, 
		randomGenerator
	);
    routines[2] = new AnkunftPatientRoutine(
		notarzt, 
		eventList, 
		notfallWarteschlange
	);
	routines[3] = new EndeBehandlungRoutine(
		notarzt, 
		eventList, 
		notfallWarteschlange
	);
	routines[4] = new RueckfahrtRoutine(
		notarzt, 
		eventList, 
		randomGenerator
	);
	routines[5] = new AnkunftZentraleRoutine(
		notarzt, 
		eventList, 
		notfallWarteschlange
	);
    routines[6] = new EndRoutine();


    SimulationManager* simulationManager = new SimulationManager(
        eventList,
        routines,
        numOfRoutines,
        storage,
		nachberechnungen
    );
    simulationManager->run(events, numArrivals, endOfSimulation); 
};
