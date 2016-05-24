#ifndef NOTFALL_H
#define NOTFALL_H

#include <SimObject.h>


class Notfall : public SimObject
{
    public:
        Notfall(
            int callTime,
            int prio,
            int treatmentDuration
        );
        virtual ~Notfall();
        int isUrgent();
        int getCallTime();
        int getTreatmentDuration();
        void getState();
    private:
        int callTime;
        int prio;
        int treatmentDuration;
};

#endif // NOTFALL_H
