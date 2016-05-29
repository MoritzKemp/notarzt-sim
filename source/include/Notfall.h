#ifndef NOTFALL_H
#define NOTFALL_H

#include <SimObject.h>


class Notfall : public SimObject
{
    public:
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
        void getState();
    private:
        int callTime;
        int prio;
        int treatmentDuration;
		int place;
};

#endif // NOTFALL_H
