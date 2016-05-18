
#include <stdlib.h>
#include <iostream>
#include "Event.h"
#include "EventList.h"

using namespace std;

int main(int argv, char** argc)
{
    EventList eventList;

    cout << "Insert 1"<< endl;
    struct tm* exeTime_1 = (struct tm*) malloc(sizeof(struct tm));
    strptime("2016-05-16  14:36:00", "%Y-%m-%d %H:%M:%S", exeTime_1);
    Event* event_1 = new Event(exeTime_1, EventType::ARRIVAL_HOME);
    eventList.addEvent(event_1);

    cout << "Insert 2"<< endl;

    struct tm* exeTime_2 = (struct tm*) malloc(sizeof(struct tm));
    strptime("2016-05-16  10:36:00", "%Y-%m-%d %H:%M:%S", exeTime_2);
    Event* event_2 = new Event(exeTime_2, EventType::ARRIVAL_PATIENT);
    eventList.addEvent(event_2);

    cout << "Insert 3"<< endl;

    struct tm* exeTime_3 = (struct tm*) malloc(sizeof(struct tm));
    strptime("2016-05-16  12:36:00", "%Y-%m-%d %H:%M:%S", exeTime_3);
    Event* event_3 = new Event(exeTime_3, EventType::ARRIVAL_HOME);
    eventList.addEvent(event_3);

    eventList.printList();

};
