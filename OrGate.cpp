#include "OrGate.h"
#include <iostream>

OrGate::OrGate(string name) : LogicComponent(name,2,1)
{
    iter = false;
    inputList = new string[2];
    outputList = new string[1];
}

OrGate::OrGate(string signal1, string signal2, string name) : LogicComponent(name,2,1)
{
    iter = false;
    inputList = new string[2];
    outputList = new string[1];
    inputList[0] = signal1;
    inputList[1] = signal2;
}

OrGate::~OrGate()
{
    delete inputList;
    delete outputList;
}

void OrGate::iterate()
{
    iter = true;
    if(inputList[0]==inputList[1] && inputList[0]=="0")
    {
        outputList[0] = "0";
    }
    else
        outputList[0] = "1";
    cout << componentName << " Elemaninin Girisleri: " << inputList[0];
    cout << " ve " << inputList[1] << " cikisi ise " << outputList[0] << endl;
}

string OrGate::getName()
{
    return componentName;
}

bool OrGate::isIterate()
{
    return iter;
}

void OrGate::setInputs(int signal1, int signal2)
{
    iter = false;
    inputList[0] = signal1;
    inputList[1] = signal2;
}

void OrGate::print()
{
    std::cout << outputList[0] << endl;
}

void OrGate::addInput(string input)
{
    inputList[countofAvailableInputs] = input;
    countofAvailableInputs++;
    if(countofAvailableInputs>=2) iterate();
}

string OrGate::getOutput(int address)
{
    return outputList[address];
}
