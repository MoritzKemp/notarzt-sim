#ifndef NOTFALLWARTESCHLANGE_H
#define NOTFALLWARTESCHLANGE_H

#include <list>
#include "Notfall.h"
#include "StateStorage.h"

using namespace std;

class NotfallWarteschlange
{
    public:
        NotfallWarteschlange(
            StateStorage* storage
        );
        virtual ~NotfallWarteschlange();
        void add(Notfall* notfall);
        Notfall* pop();
        void printList();

    private:
        list<Notfall*> notfallList;
        StateStorage* stateStorage;
};

#endif // NOTFALLWARTESCHLANGE_H
