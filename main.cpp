#include <iostream>

#include "OrGate.h"

using namespace std;

int main()
{
    OrGate o("1","0","or1",1,1);
    o.iterate();
    o.print();
    return 0;
}
