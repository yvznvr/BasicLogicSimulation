#ifndef ADDER_H
#define ADDER_H

#include "LogicComponent.h"
#include <iostream>

using namespace std;

class Adder: public LogicComponent
{
    public:
        Adder(int*,int*,int,string);
        virtual ~Adder();
        void iterate();
        bool isIterate();
        void print();

    protected:

    private:
        int *sum1;
        int *sum2;
        int carry;
        bool iter;
        int *output;
};

#endif // ADDER_H
