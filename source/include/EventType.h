#ifndef EVENT_TYPE_H
#define EVENT_TYPE_H

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
