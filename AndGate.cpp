#include "AndGate.h"

AndGate::AndGate(string signal1, string signal2, string name, int nInputs, int nOutputs) : LogicComponent(name,nInputs,nOutputs)
{
    iter = false;
    inputList = new string[2];
    outputList = new string[1];
    inputList[0] = signal1;
    inputList[1] = signal2;
}

AndGate::AndGate(string name): LogicComponent(name,2,1)
{
    iter = false;
    inputList = new string[2];
    outputList = new string[1];
}

AndGate::~AndGate()
{
    delete inputList;
    delete outputList;
}

string AndGate::getName()
{
    return componentName;
}

void AndGate::iterate()
{
    iter = true;
    if(inputList[0] == inputList[1] && inputList[0] == "1")
    {
        outputList[0] = "1";
    }
    else
        outputList[0] = "0";
}

bool AndGate::isIterate()
{
    return iter;
}

void AndGate::setInputs(int signal1, int signal2)
{
    iter = false;
    inputList[0] = signal1;
    inputList[1] = signal2;
}

void AndGate::addInput(string input)
{
    inputList[countofAvailableInputs] = input;
    countofAvailableInputs++;
    if(countofAvailableInputs>=2) iterate();
}

void AndGate::print()
{

}

string AndGate::getOutput(int address)
{
    return outputList[address];
}
