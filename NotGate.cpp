#include "NotGate.h"

NotGate::NotGate(string signal, string name, int nInputs, int nOutputs) : LogicComponent(name, nInputs, nOutputs)
{
    iter = false;
    inputList = new string[1];
    outputList = new string[1];
    inputList[1] = signal;
}

NotGate::~NotGate()
{
    delete inputList;
    delete outputList;
}

void NotGate::iterate()
{
    if(inputList[1]=="0")
    {
        outputList[1] = "1";
    }
    else
        outputList[1] = "0";
    iter = true;
}

bool NotGate::isIterate()
{
    return iter;
}

void NotGate::setInputs(int signal)
{
    iter = false;
    inputList[1] = signal;
}
