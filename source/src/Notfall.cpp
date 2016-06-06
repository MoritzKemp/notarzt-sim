#include "Notfall.h"
#include <iostream>
using namespace std;

Notfall::Notfall(int cTime, int p, int duration, int pl)
{
    callTime = cTime;
    prio = p;
    treatmentDuration = duration;
	place = pl;
	isInTreatment = 0;
	treatmentTime = 0;
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

int Notfall::inTreatment()
{
	return isInTreatment;
}

void Notfall::setInTreatment(int treatment)
{
	isInTreatment = treatment;
}

int Notfall::getTreatmentStart()
{
	return treatmentTime;
}

void Notfall::setTreatmentStart(int time)
{
	treatmentTime = time;
}

void Notfall::getState()
{
    cout << "Notfall: calltime "<< callTime << ", isUrgent " << prio << ", treatment duration: " << treatmentDuration << ", place: "<< place << endl;
}
