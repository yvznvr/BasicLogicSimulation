#ifndef LOGICCOMPONENT_H
#define LOGICCOMPONENT_H

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class LogicComponent
{
    public:
        LogicComponent(string, int, int);
        virtual ~LogicComponent();
        virtual void print()=0;
        virtual void iterate()=0;
        virtual bool isIterate()=0;
        virtual string getName()=0;
        virtual void addInput(string)=0;
        int getCountofAvailableInputs();
        virtual string getOutput(int)=0;
        string toString(int val);
        int getNumberOfInputs();
    protected:
        string componentName;
        int numberOfInputs;
        int numberOfOutputs;
        string *inputList;
        string *outputList;
        // countofAvailableInputs degiskeni tanimlanmis olan (0 veya 1)
        // tum girislerin sayisini verir
        int countofAvailableInputs;
    private:

};

#endif // LOGICCOMPONENT_H
