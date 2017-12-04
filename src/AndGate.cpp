#include "AndGate.h"

AndGate::AndGate(int signal1, int signal2, string name, int nInputs, int nOutputs) : LogicComponent(name,nInputs,nOutputs)
{
    iter = false;
    inputList = new string[2];
    outputList = new string[1];
    inputList[1] = signal1;
    inputList[2] = signal2;
}

AndGate::~AndGate()
{
    delete inputList;
    delete outputList;
}

void AndGate::iterate()
{
    iter = true;
    if(inputList[1] == inputList[2] && inputList[1] == "1")
    {
        outputList[1] = "1";
    }
    else
        outputList[1] = "0";
}

bool AndGate::isIterate()
{
    return iter;
}

void AndGate::setInputs(int signal1, int signal2)
{
    iter = false;
    inputList[1] = signal1;
    inputList[2] = signal2;
}
