#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H

#include "EventList.h"
#include "EventRoutine.h"
#include "StateStorage.h"
class SimulationManager
{
    private:
    EventList* eventList;
    EventRoutine** routineList;
    StateStorage* stateStorage;
    int numOfRoutines;
    void executeEvent(Event *event);

    public:
    SimulationManager(
        EventList* eList,
        EventRoutine* roList[],
        int numRoutines,
        StateStorage* storage
    );
    ~SimulationManager();
    void run(Event* initlaEvents[], int sizeEvents, int endTime);
};

#endif
