#ifndef NOTARZT_H
#define NOTARZT_H

#include <SimObject.h>
#include <NotarztPlace.h>
#include <NotarztStates.h>


class Notarzt : public SimObject
{
    public:
        Notarzt(int time, NotarztStates state, NotarztPlace place);
        virtual ~Notarzt();
        int getTimestamp();
        NotarztStates getNotarztState();
        NotarztPlace getNotarztPlace();
        void setTimestamp(int newTimestamp);
        void setNotarztState(NotarztStates newState);
        void setNotarztPlace(NotarztPlace newPlace);
        void getState();
    private:
    int timestamp;
    NotarztStates state;
    NotarztPlace place;
};

#endif // NOTARZT_H
