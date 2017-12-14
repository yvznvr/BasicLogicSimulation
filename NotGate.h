#ifndef NOTGATE_H
#define NOTGATE_H

#include "LogicComponent.h"

class NotGate: public LogicComponent
{
    public:
        NotGate(string);
        NotGate(string, string, int, int);
        virtual ~NotGate();
        void iterate();
        bool isIterate();
        void setInputs(int);
        string getName();
        void addInput(string);
        void print();
        string getOutput(int);

    protected:

    private:
        bool iter;
};

#endif // NOTGATE_H
