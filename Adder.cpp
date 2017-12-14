#include "Adder.h"
#include <stdlib.h>

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

Adder::Adder(string name): LogicComponent(name, 9,5)
{
    iter = false;
    this->sum1 = new int[4];
    this->sum2 = new int[4];
    this->output = new int[4]();
}

Adder::~Adder()
{
    delete sum1;
    delete sum2;
    delete output;
}

string Adder::getName()
{
    return componentName;
}

void Adder::iterate()
{
    iter = true;
    cout << componentName << " devresinin girisleri" << endl;
    cout << "Sum1: " << sum1[0] << sum1[1] << sum1[2] << sum1[3] << endl;
    cout << "Sum2: " << sum2[0] << sum2[1] << sum2[2] << sum2[3] << endl;
    cout << "Carry: " << carry << endl;
    cout << "Adim Adim İslemler Sonucu Cikislar ise asagidaki sekildedir." << endl;
    cout << "Baslangicta tum cikis degerleri 0 olarak varsayilir" << endl;
    cout << "C S4 S3 S2 S1" << endl;
    for(int i=3 ; i>=0 ; i--){
        output[i] = ((sum1[i] ^ sum2[i]) ^ carry);
        carry = ((sum1[i] & sum2[i]) | (sum1[i] & carry)) | (sum2[i] & carry);
        cout << carry << "  " << output[0] << "  " << output[1] << "  ";
        cout << output[2] << "  " << output[3] << endl;
    }
}

void Adder::print()
{
    cout << "Sum1: " << sum1[0] << sum1[1] << sum1[2] << sum1[3] << endl;
    cout << "Sum2: " << sum2[0] << sum2[1] << sum2[2] << sum2[3] << endl;
    cout << "Carry: " << carry << endl;
    cout << "Sonuc:" << endl;
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

void Adder::addInput(string input)
{
    if(countofAvailableInputs<4)
        sum1[countofAvailableInputs] = atoi(input.c_str());
    else if(countofAvailableInputs!=8)
        sum2[countofAvailableInputs%4] = atoi(input.c_str());
    else
        carry = atoi(input.c_str());
    countofAvailableInputs++;
    if(countofAvailableInputs>=9)
        iterate();
}

string Adder::getOutput(int address)
{
    if(address<4)
        return toString(output[address]);
    else
        return toString(carry);
}
