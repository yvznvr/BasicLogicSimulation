#include "LogicComponent.h"

LogicComponent::LogicComponent(string name, int inputs, int outputs)
{
    componentName = name;
    numberOfInputs = inputs;
    numberOfOutputs = outputs;
    countofAvailableInputs = 0;
}

LogicComponent::~LogicComponent()
{
    //dtor
}

int LogicComponent::getCountofAvailableInputs()
{
    return countofAvailableInputs;
}

string LogicComponent::toString(int val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}

int LogicComponent::getNumberOfInputs()
{
    return numberOfInputs;
}
