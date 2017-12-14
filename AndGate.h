#ifndef ANDGATE_H
#define ANDGATE_H

#include "LogicComponent.h"


class AndGate : public LogicComponent
{
    public:
        AndGate(string);
        AndGate(string, string, string, int, int);
        virtual ~AndGate();
        void iterate();
        bool isIterate();
        void setInputs(int,int);
        string getName();
        void addInput(string);
        void print();
        string getOutput(int);
    protected:

    private:
        bool iter;
};

#endif // ANDGATE_H
