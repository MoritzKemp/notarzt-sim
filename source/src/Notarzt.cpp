#include "Notarzt.h"
#include <iostream>

using namespace std;
Notarzt::Notarzt(
    int initTime,
    NotarztStates initState,
    int initPlace

)
{
    timestamp = initTime;
    place = initPlace;
    state = initState;
}

Notarzt::~Notarzt()
{
    //dtor
}

int Notarzt::getTimestamp()
{
    return timestamp;
}

int Notarzt::getNotarztPlace()
{
    return place;
}

NotarztStates Notarzt::getNotarztState()
{
    return state;
}

void Notarzt::setTimestamp(int newTimestamp)
{
    timestamp = newTimestamp;
}

void Notarzt::setNotarztPlace(int newPlace)
{
    place = newPlace;
}

void Notarzt::setNotarztState(NotarztStates newState)
{
    state = newState;
}

void Notarzt::getState()
{
    cout << "Notarzt: timestamp "<< timestamp << ", state " << (int)state << ", place: " << (int)place << endl;
}

