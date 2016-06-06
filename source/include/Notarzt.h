#ifndef NOTARZT_H
#define NOTARZT_H

#include <SimObject.h>
#include <NotarztPlace.h>
#include <NotarztStates.h>

/** \brief Repräsentiert einen Notarzt
 *
 * Klasse für die Erstellung von Notarzt-Objekten,
 * die in der Notarzt-Simulation verwendet werden können.
 * Der Notarzt besitzt keine eigen Logik sondern repräsentiert
 * immer nur einen bestimmten Zustand des Notarztes in der
 * Notarzt-Simulation.
 */
class Notarzt : public SimObject
{
    public:
		/** \brief Konstruktor
 		 *	
 		 * Mit den gegebene Parametern wird der Anfangszustand
 		 * des Notarztes in der Notarzt-Simulation defniert.
 		 * Timestamp wird initial immer auf 0 gesetzt.
 		 */
        Notarzt(NotarztStates state, int place);
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
