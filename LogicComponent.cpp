#include "LogicComponent.h"

LogicComponent::LogicComponent(string name, int inputs, int outputs)
{
    componentName = name;
    numberOfInputs = inputs;
    numberOfOutputs = outputs;
}

LogicComponent::~LogicComponent()
{
    //dtor
}
