#include <iostream>

#include "OrGate.h"
#include "Adder.h"

using namespace std;

int main()
{
    OrGate o("1","0","or1",1,1);
    o.iterate();
    o.print();
    int s1[4] = {1,1,1,1};
    int s2[4] = {1,0,1,0};
    Adder a(s1,s2,0,"adder1");
    a.iterate();
    a.print();
    return 0;
}
