#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

enum class EventType
{
    END,
    NEUER_NOTRUF,
	ANKUNFT_PATIENT,
	ANKUNFT_ZENTRALE,
	ABFAHRT_ZU_PATIENT,
	ABFAHRT_ZU_ZENTRALE,
	ENDE_BEHANDLUNG
};

#endif
