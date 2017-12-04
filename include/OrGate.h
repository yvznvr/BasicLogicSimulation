#ifndef ORGATE_H
#define ORGATE_H

#include "LogicComponent.h"

class OrGate : public LogicComponent
{
    public:
        OrGate(int, int, string, int, int);
        virtual ~OrGate();
        void iterate();
        bool isIterate();
        void setInputs(int,int);
    protected:

    private:
        bool iter;
};

#endif // ORGATE_H
