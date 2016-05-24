#ifndef NOTFALLWARTESCHLANGE_H
#define NOTFALLWARTESCHLANGE_H

#include <list>
#include "Notfall.h"
using namespace std;

class NotfallWarteschlange
{
    public:
        NotfallWarteschlange();
        virtual ~NotfallWarteschlange();
        void add(Notfall* notfall);
        Notfall* pop();
        void printList();

    private:
        list<Notfall*> notfallList;
};

#endif // NOTFALLWARTESCHLANGE_H
