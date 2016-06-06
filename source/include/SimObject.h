#ifndef SIMOBJECT_H
#define SIMOBJECT_H

/** \brief Abstrakte Klasse für Zustands-Objekte der Simulation
 *
 * Diese abtrakte Klasse definiert die Schnittstelle
 * zu den Objekten einer Simulation, die in der Gesamtheit
 * den Zustand der Simulation repräsentieren.
 * Die Idee dahinter ist, dass das abspeichern der Zustände
 * nach jedem Durchlauf der Simulationschleife unabhängig
 * von der spezzifischen Implementierung ist.
 */

class SimObject
{
    public:
        SimObject();
        virtual ~SimObject();
		/** \brief Funktionssignatur für das Abspeichern des Objektes
 		 *
 		 * Diese Schnittstelle stellt die minimale Erwartunhshaltung
 		 * an Zustands-Objekten innerhalb einer Simulation dar.
 		 * Sie muss foglich von jedem speziellem Zustands-Objekt implementiert
 		 * werden. Diese Funktion speichert den aktuellen Zustand des Objektes.
 		 *
 		 * TODO Wird in der aktuellen Notarzt-Implementierung nicht
 		 * verwendet. Die aktuelle Architektur lässt keine allgemeien 
 		 * Speicherung von SimObjekten zu.
 		 */
        virtual void getState()=0;
    private:
};

#endif // SIMOBJECT_H
