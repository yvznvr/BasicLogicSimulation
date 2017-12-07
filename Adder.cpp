#include "Adder.h"

Adder::Adder(int *sum1 ,int *sum2 , int carry, string name): LogicComponent(name, 9,5)
{
    iter = false;
    this->sum1 = new int[4];
    this->sum2 = new int[4];
    this->output = new int[4];
    this->carry = carry;
    this->sum1 = sum1;
    this->sum2 = sum2;
}

Adder::~Adder()
{
    delete sum1;
    delete sum2;
    delete output;
}


void Adder::iterate()
{
    iter = true;
    for(int i=3 ; i>=0 ; i--){
        output[i] = ((sum1[i] ^ sum2[i]) ^ carry);
        carry = ((sum1[i] & sum2[i]) | (sum1[i] & carry)) | (sum2[i] & carry);
    }
}

void Adder::print()
{
    cout << "C S4 S3 S2 S1" << endl << carry << "  ";
    for(int i=0 ; i<4 ; i++){
        cout << output[i] << "  ";
    }
    cout << endl;
}

bool Adder::isIterate()
{
    return iter;
}
