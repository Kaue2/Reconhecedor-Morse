#pragma once
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
class ADF
{
private:
    set<char> alfabeto;
    set<int> estados;
    set<int> estadosFinais;
    map<pair<int, char>, int> transition;
    int estadoInicial;

public:
    ADF();
    bool accepts(string input);
};