
#include "NotfallWarteschlange.h"
#include <iostream>

NotfallWarteschlange::NotfallWarteschlange(
    StateStorage* storage
)
{
    stateStorage = storage;
}

NotfallWarteschlange::~NotfallWarteschlange()
{
    //dtor
}

void NotfallWarteschlange::add(Notfall* newNotfall)
{
    int found = 0;
    Notfall* currentNotfall;
    list<Notfall*>::iterator iter = notfallList.begin();

    if(newNotfall->isUrgent())
    {
        while(iter != notfallList.end() && !found)
        {
            currentNotfall = *iter;
            if(
                currentNotfall->isUrgent()
                && currentNotfall->getCallTime() < newNotfall->getCallTime()
            ){
                found = 1;
            }
        }
    } else
    {
        while(iter != notfallList.end() && !found)
        {
            currentNotfall = *iter;
            if(
                currentNotfall->isUrgent()
                || currentNotfall->getCallTime() < newNotfall->getCallTime()
            ){
                found = 1;
            }
        }
    }
    notfallList.insert(iter, newNotfall);
    stateStorage->registerObject(newNotfall);
}

Notfall* NotfallWarteschlange::pop()
 {
    Notfall* notfall = notfallList.back();
    notfallList.pop_back();
    stateStorage->unregister(notfall);
    return notfall;
 }

 void NotfallWarteschlange::printList()
 {
    list<Notfall*>::iterator iter;
    Notfall* currentNotfall;
    int count = 1;
    cout << "Current NotfallWarteschlange content: "<< endl;
	for(iter = notfallList.begin(); iter != notfallList.end(); iter++)
	{
        currentNotfall = *iter;
        cout << "[" << count << "] " ;
		cout << "Notfall eingegangen: "<< currentNotfall->getCallTime() << " ";
		cout << "Priorität: "<< (int)currentNotfall->isUrgent() << endl;
		count++;
	}
	cout << endl;
 }

