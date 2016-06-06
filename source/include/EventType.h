#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

/** \brief Aufzählung von Ereignistypen
 *
 * Alle Ereignistypen einer spezifischen Simulation
 * werden hier aufgelistet. Bis auf den END-Typ können
 * sich also die Aufzählungen je nach Simulation ändern.
 */
enum class EventType
{
    END 				= 0,
    NEUER_NOTRUF 		= 1,
	ANKUNFT_PATIENT 	= 2,
	ABFAHRT_ZU_PATIENT 	= 3,
	ENDE_BEHANDLUNG 	= 4,
	ABFAHRT_ZU_ZENTRALE = 5,
	ANKUNFT_ZENTRALE 	= 6
};

#endif
