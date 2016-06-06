#ifndef NOTARZT_STATES
#define NOTARZT_STATES

/** \brief Aufzählung von Notarzt-Zuständen
 *
 * Alle Zustände, die ein Notarzt innerhalb
 * der Notarzt-Simulation annehmen kann, sind
 * hier defniert.
 */
enum class NotarztStates
{
    WARTEND = 0,
    UNTERWEGS_PATIENT = 1,
    UNTERWEGS_ZENTRALE = 2,
    BEHANDLUNG = 3
};

#endif
