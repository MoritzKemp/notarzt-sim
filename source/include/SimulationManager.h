#ifndef SIMULATIONMANAGER_H
#define SIMULATIONMANAGER_H


class SimulationManager
{
    private:
    EventList* eventList;
    EventRoutine* routineList;
    int numOfEvents;
    int numOfRoutines;
    void executeEvent();

    public:
    SimulationManager(
        EventList* eList,
        int numEvents,
        EventRoutine* roList,
        int numRoutines
    );
    ~SimulationManager();
    void run();
};

#endif
