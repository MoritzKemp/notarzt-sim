#include "Notfall.h"
#include <iostream>
using namespace std;

Notfall::Notfall(int cTime, int p, int duration, int pl)
{
    callTime = cTime;
    prio = p;
    treatmentDuration = duration;
	place = pl;
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

int Notfall::getPlace()
{
	return place;
}

void Notfall::getState()
{
    cout << "Notfall: calltime "<< callTime << ", isUrgent " << prio << ", treatment duration: " << treatmentDuration << ", place: "<< place << endl;
}
