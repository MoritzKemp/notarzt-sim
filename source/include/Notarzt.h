#ifndef NOTARZT_H
#define NOTARZT_H

#include <SimObject.h>
#include <NotarztPlace.h>
#include <NotarztStates.h>


class Notarzt : public SimObject
{
    public:
        Notarzt(int time, NotarztStates state, int place);
        virtual ~Notarzt();
        int getTimestamp();
        NotarztStates getNotarztState();
        int getNotarztPlace();
        void setTimestamp(int newTimestamp);
        void setNotarztState(NotarztStates newState);
        void setNotarztPlace(int newPlace);
        void getState();
    private:
    int timestamp;
    NotarztStates state;
    int place;
};

#endif // NOTARZT_H
