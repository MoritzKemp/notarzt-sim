#ifndef NOTARZT_STATES
#define NOTARZT_STATES

enum class NotarztStates
{
    // Notarzt
    WARTEND = 0,
    UNTERWEGS_PATIENT = 1,
    UNTERWEGS_ZENTRALE = 2,
    BEHANDLUNG = 3
};

#endif
