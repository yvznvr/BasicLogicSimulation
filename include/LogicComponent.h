#ifndef LOGICCOMPONENT_H
#define LOGICCOMPONENT_H

#include <string>
using namespace std;

class LogicComponent
{
    public:
        LogicComponent(string, int, int);
        virtual ~LogicComponent();
        virtual void print()=0;
        virtual void iterate()=0;

    protected:
        string componentName;
        int numberOfInputs;
        int numberOfOutputs;
        string *inputList;
        string *outputList;
    private:

};

#endif // LOGICCOMPONENT_H
