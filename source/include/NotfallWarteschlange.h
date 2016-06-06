#ifndef NOTFALLWARTESCHLANGE_H
#define NOTFALLWARTESCHLANGE_H

#include <list>
#include "Notfall.h"
#include "StateStorage.h"

using namespace std;

/** \bief Verwaltet Notfälle
 *
 * In der Notarzt-Simulation werden 
 * Notfälle in einer Warteschlange verwaltet.
 * Die Warteschlange defniert dabei den nächsten Notfall,
 * den der Notarzt behandeln muss.
 * Für die Sortierung der Notfälle werden dabei zwei 
 * Kriterien heran gezogen: den Zeitpunkt
 * des Anrufes (ältere Anrufe zuerst) und die Priorität
 * (hohe Priorität immer zuerst).
 */
class NotfallWarteschlange
{
    public:
		/** \brief Konstruktor
 		 * 
 		 * Erstellt ein NotfallWarteschlangen-Objekt. Benötigt
 		 * ein StateStorage Objekt zur Registrierung
 		 * von Notfällen, damit diese automatisch abgespeichert werden.
 		 */
        NotfallWarteschlange(
            StateStorage* storage
        );
        virtual ~NotfallWarteschlange();

		/** \brief Fügt einen Notfall hinzu
 		 *
 		 * Der übergebene Notfall wird der Warteschlange hinzugefügt.
 		 * Seine Position innerhalb der Warteschlange bestimmen seine
 		 * Attribute der Priorität und der Anrufzeit.
 		 */
        void add(Notfall* notfall);
	
		/** \brief Liefert und entfernt den nächsten Notfall
 		 * 
 		 * Liefert den nächsten zu behandelden Notfall zurück
 		 * und löscht diesen aus der Warteschlange.
		 */
        Notfall* pop();

		/** \brief Liefert den nächstenNotfall
 		 * 
 		 * Liefert den nächsten Notfall, ohne ihn aus der Warteschlange
 		 * zu entfernen. D.h. ein direktes, wiederholtes Aufrufen dieser Funktion
 		 * liefert den gleichen Notfall.
 		 */
		Notfall* front();

		/** \brief Druckt die aktuelle Warteschlange auf die Ausgabe
 		 */
        void printList();

    private:
        list<Notfall*> notfallList;
        StateStorage* stateStorage;
};

#endif // NOTFALLWARTESCHLANGE_H
