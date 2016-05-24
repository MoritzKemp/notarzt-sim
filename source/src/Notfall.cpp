#include "Notfall.h"
#include <iostream>
using namespace std;

Notfall::Notfall(int cTime, int p, int duration)
{
    callTime = cTime;
    prio = p;
    treatmentDuration = duration;
}

Notfall::~Notfall()
{
    //dtor
}

int Notfall::isUrgent()
{
    return prio;
}

int Notfall::getCallTime()
{
    return callTime;
}

int Notfall::getTreatmentDuration()
{
    return treatmentDuration;
}

void Notfall::getState()
{
    cout << "Notfall: calltime "<< callTime << ", isUrgent " << prio << ", treatment duration: " << treatmentDuration << endl;
}
