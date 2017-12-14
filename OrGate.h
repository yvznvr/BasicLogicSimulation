#ifndef ORGATE_H
#define ORGATE_H

#include "LogicComponent.h"

class OrGate : public LogicComponent
{
    public:
        OrGate(string);
        OrGate(string, string, string);
        virtual ~OrGate();
        void iterate();
        bool isIterate();
        void setInputs(int,int);
        void print();
        string getName();
        void addInput(string);
        string getOutput(int);
    protected:

    private:
        bool iter;
};

#endif // ORGATE_H
