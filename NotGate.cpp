#include "NotGate.h"

NotGate::NotGate(string signal, string name, int nInputs, int nOutputs) : LogicComponent(name, nInputs, nOutputs)
{
    iter = false;
    inputList = new string[1];
    outputList = new string[1];
    inputList[1] = signal;
}

NotGate::NotGate(string name):LogicComponent(name,1,1)
{
    iter = false;
    inputList = new string[1];
    outputList = new string[1];
}

NotGate::~NotGate()
{
    delete inputList;
    delete outputList;
}

string NotGate::getName()
{
    return componentName;
}

void NotGate::iterate()
{
    if(inputList[0]=="0")
    {
        outputList[0] = "1";
    }
    else
        outputList[0] = "0";
    iter = true;
    cout << componentName << " Elemaninin Girisi: " << inputList[0];
    cout << " cikisi ise " << outputList[0] << endl;
}

bool NotGate::isIterate()
{
    return iter;
}

void NotGate::setInputs(int signal)
{
    iter = false;
    inputList[0] = signal;
}

void NotGate::addInput(string input)
{
    inputList[countofAvailableInputs] = input;
    countofAvailableInputs++;
    if(countofAvailableInputs>=1) iterate();
}

void NotGate::print()
{

}

string NotGate::getOutput(int address)
{
    return outputList[address];
}
