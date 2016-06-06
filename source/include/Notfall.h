#ifndef NOTFALL_H
#define NOTFALL_H

#include <SimObject.h>

/** \brief Repräsentiert einen Notfall
 *
 * Klasse für die Erstellung eines
 * Notfall-Objektes, dessen Zustand im Laufe
 * der Simulation verändert werden kann.
 * Besitzt keine eigene Logik, sondern repräsentiert
 * nur den aktuellen Zustand.
 * 
 * Erstellt werden Notfälle im Rahmen der
 * Notfall-Simulation in der Regel nachdem ein
 * neuer Notruf bei der Zentrale eingetroffen ist.
 *
 * Notfälle werden von der NotfallWarteschlange verwaltet.
 */
class Notfall : public SimObject
{
    public:
		/** \brief Konstruktor
 		 *
 		 * Mit den gegebenen Parametern wird der Anfangszustand
 		 * des Notfalls in der Notarzt-Simulation defniert. 
 		 */
        Notfall(
            int callTime,
            int prio,
            int treatmentDuration,
			int place
        );
        virtual ~Notfall();
        int isUrgent();
        int getCallTime();
        int getTreatmentDuration();
		int getPlace();
		int inTreatment();
		void setInTreatment(int treatment);
		void setTreatmentStart(int time);
		int getTreatmentStart();
        void getState();
    private:
        int callTime;
        int prio;
        int treatmentDuration;
		int place;
		int isInTreatment;
		int treatmentTime;
};

#endif // NOTFALL_H
