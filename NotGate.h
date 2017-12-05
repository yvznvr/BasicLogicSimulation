#ifndef NOTGATE_H
#define NOTGATE_H

#include "LogicComponent.h"

class NotGate: public LogicComponent
{
    public:
        NotGate(string, string, int, int);
        virtual ~NotGate();
        void iterate();
        bool isIterate();
        void setInputs(int);

    protected:

    private:
        bool iter;
};

#endif // NOTGATE_H
