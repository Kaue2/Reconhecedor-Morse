#include <iostream>
#include "../include/Modules/ADF.h"

int main()
{
    ADF* automato = new ADF();
    bool aceito = automato->accepts("..-.- / ..--. -..");

    if (aceito) {
        cout << "palavra aceita" << endl;
    }
    else
    {
        cout << "calma lá paizão" << endl;
    }

}