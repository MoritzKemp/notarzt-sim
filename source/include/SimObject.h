#ifndef SIMOBJECT_H
#define SIMOBJECT_H


class SimObject
{
    public:
        SimObject();
        virtual ~SimObject();
        virtual void getState()=0;
    private:
};

#endif // SIMOBJECT_H
