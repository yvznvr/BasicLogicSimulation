#include "OrGate.h"
#include <iostream>
using namespace std;
OrGate::OrGate(string signal1, string signal2, string name, int nInputs, int nOutputs) : LogicComponent(name,nInputs,nOutputs)
{
    iter = false;
    inputList = new string[3];
    outputList = new string[2];
    inputList[1] = signal1;
    inputList[2] = signal2;
}

OrGate::~OrGate()
{
    delete inputList;
    delete outputList;
}

void OrGate::iterate()
{
    iter = true;
    if(inputList[1]==inputList[2] && inputList[1]=="0")
    {
        outputList[1] = "0";
    }
    else
        outputList[1] = "1";
}

bool OrGate::isIterate()
{
    return iter;
}

void OrGate::setInputs(int signal1, int signal2)
{
    iter = false;
    inputList[1] = signal1;
    inputList[2] = signal2;
}

void OrGate::print()
{
    cout << outputList[1] << endl;
}
