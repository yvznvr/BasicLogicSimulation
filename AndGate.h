#ifndef ANDGATE_H
#define ANDGATE_H

#include "LogicComponent.h"

class AndGate : public LogicComponent
{
    public:
        AndGate(int, int, string, int, int);
        virtual ~AndGate();
        void iterate();
        bool isIterate();
        void setInputs(int,int);
    protected:

    private:
        bool iter;
};

#endif // ANDGATE_H
