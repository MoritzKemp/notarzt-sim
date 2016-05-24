#ifndef STATESTORAGE_H
#define STATESTORAGE_H

#include <list>
#include "SimObject.h"

class StateStorage
{
    public:
        StateStorage();
        virtual ~StateStorage();
        void saveState();
        void registerObject(SimObject* simObject);
        void unregister(SimObject* simObject);

    private:
        std::list<SimObject*> observedList;
};

#endif // STATESTORAGE_H
