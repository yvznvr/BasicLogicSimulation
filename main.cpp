#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "LogicComponent.h"
#include "OrGate.h"
#include "Adder.h"
#include "NotGate.h"
#include "AndGate.h"


//using namespace std;

void recognizeComponent(string, vector<LogicComponent*>*);
bool isAdded(string, vector<LogicComponent*>*);
void getLines(string, vector<string>*);
void getInputs(string, vector<string>*);
void getComponent(string, vector<LogicComponent*>*, vector<string>*);
void setInputs(string, vector<LogicComponent*>*, vector<string>*, vector<string>);
string getInputFromAnotherComponent(string, vector<LogicComponent*>*);

int main()
{
    string outputs;
    vector<string> Lines;
    vector<string> Inputs;
    vector<LogicComponent*> logicCircuits;
    getLines("C:\\Users\\Yavuz\\Desktop\\BasicLogicGateSimulator\\test.txt", &Lines);
    for (int i=0;i<Lines.size();i++)
    {
        cout << Lines.at(i) << endl;
    }

    // Giris degerlerini aliyoruz
    getInputs(Lines.at(1), &Inputs);

    // Uzerinden tekrar gecmemiz gerekmeyen alanlari siliyoruz
    // Birinci ve ikinci satirlar
    Lines.erase(Lines.begin());Lines.erase(Lines.begin());
    // Cikis degerlerini bir stringe atadik
    outputs = Lines.back();

    for (int i=0; i<Lines.size(); i++)
    {
        if(!Lines.at(i).find("Output "))
        {
            outputs = Lines.at(i);
            Lines.erase(Lines.begin()+i);
        }
    }

    for (int j=0;j<3;j++)
    {
        for (int i=0;i<Lines.size()-1;i++)
        {
            getComponent(Lines.at(i),&logicCircuits, &Inputs);
        }
    }

    cout << logicCircuits.at(1)->getName() << endl;
    logicCircuits.at(1)->print();

    for (int i=0;i<logicCircuits.size();i++) delete logicCircuits.at(i);

    return 0;
}

void recognizeComponent(string cName, vector<LogicComponent*> *comp)
{
    // Lojik elemanlarin tutuldugu havuza yeni lojik eleman ekler.
    string temp;
    temp = cName;
    cName.pop_back();
    if(cName=="Adder"){
        Adder *adder = new Adder(temp);
        comp->push_back(adder);
    }else if(cName=="OR"){
        OrGate *orgate = new OrGate(temp);
        comp->push_back(orgate);
    }else if(cName=="AND"){
        AndGate *andgate = new AndGate(temp);
        comp->push_back(andgate);
    }else if(cName=="NOT"){
        NotGate *notgate = new NotGate(temp);
        comp->push_back(notgate);
    }
}

bool isAdded(string cName, vector<LogicComponent*> *comp)
{
    // Okunan lojik eleman daha önceden listeye eklenmis mi?
    for (int i=0;i<comp->size();i++)
    {
        if(cName==comp->at(i)->getName())
        {
            return 1;
        }
    }
    return 0;
}

void getLines(string fileName, vector<string>* lines)
{
    // Dosyanin tum satirlarini bir vectore atar
    string a;
    std::ifstream infile(fileName);
    //infile.open(a);
    if(!infile.is_open())
    {
        cout << "Dosya Acilamadi\n";
    }
    while(infile)
    {
        std::getline(infile,a);
        lines->push_back(a);
    }
    infile.close();
}

void getInputs(string strInputs, vector<string>* inputs)
{
    // Devrenen genel girislerini alir
    string temp;
    std::stringstream stream(strInputs);
    while (std::getline(stream,temp,' ')) inputs->push_back(temp);
}

void getComponent(string strInputs, vector<LogicComponent*>* circuits, vector<string>* inputs)
{
    string componentName;
    string temp;
    vector<string> readedInputs;
    std::stringstream stream(strInputs);
    std::getline(stream,componentName,' ');
    // Eger ekli degilse componenti ekle
    if(!isAdded(componentName, circuits))
        recognizeComponent(componentName,circuits);
    // Dosyadan okunan input degerleri (I-1, Adder1-2 gibi)
    while (std::getline(stream,temp,' ')) readedInputs.push_back(temp);
    setInputs(componentName,circuits,inputs,readedInputs);
}

void setInputs(string compName, vector<LogicComponent*> *circuits, vector<string>* inputs, vector<string>readedinputs)
{
    LogicComponent *comp;
    //vector<string> copyofReadedInputs = *readedinputs;
    for(int i=0; i<circuits->size();i++)
    {
        if(compName == circuits->at(i)->getName()) comp=circuits->at(i);
    }

    for (int i=comp->getCountofAvailableInputs(); i<readedinputs.size();i++)
    {
        if(comp->getCountofAvailableInputs()<comp->getNumberOfInputs())
        {
            if(readedinputs.at(i) == "1" || readedinputs.at(i) == "0")
            {
                comp->addInput(readedinputs.at(comp->getCountofAvailableInputs()));
            }
            else if(readedinputs.at(i).at(0) == 'I')
            {
                comp->addInput(inputs->at(comp->getCountofAvailableInputs()));
            }
            else
            {
                // Adder1-2 Or3-2 gibi cikislar setlenecek
                string inp = getInputFromAnotherComponent(readedinputs.at(comp->getCountofAvailableInputs()),circuits);
                if (inp=="-")
                    break;
                comp->addInput(inp);
            }
        }
    }
}

string getInputFromAnotherComponent(string inputsName, vector<LogicComponent*>* circuits)
{
    // Adder1-2, Or3-2 gibi cikislarin degerini bulur
    // deger hesaplanamiyorsa '-' dondurur
    int address = inputsName.find('-');
    for(int i=0;i<circuits->size();i++)
    {
        if(inputsName.substr(0,address)==circuits->at(i)->getName())
        {
            if(!circuits->at(i)->isIterate()) return "-";
            return circuits->at(i)->getOutput(atoi(inputsName.substr(address+1).c_str())-1);
        }
    }
    return "-";
}

