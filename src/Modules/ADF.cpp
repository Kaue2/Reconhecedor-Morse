#include "../../include/Modules/ADF.h"

ADF::ADF() {
    this->alfabeto = { '.', '-', '/', ' ' };
    this->estadoInicial = 0;
    this->estadosFinais = { 1, 2 };
    this->estados = { 0, 1, 2, 3 }; // todos os estados da nossa máquina
    this->transition = {  // inicializando nossa função de estados
        {pair<int, char>(0, '.'), 1},
        {pair<int, char>(0, '-'), 2},
        {pair<int, char>(0, ' '), 0},
        {pair<int, char>(0, '/'), 0},
        {pair<int, char>(1, '.'), 1},
        {pair<int, char>(1, '-'), 2},
        {pair<int, char>(1, ' '), 0},
        {pair<int, char>(1, '/'), 0},
        {pair<int, char>(1, '\0'), 1},
        {pair<int, char>(2, '-'), 2},
        {pair<int, char>(2, '.'), 1},
        {pair<int, char>(2, ' '), 0},
        {pair<int, char>(2, '/'), 0},
        {pair<int, char>(2, '\0'), 2},
    };

}

bool ADF::accepts(string input) {
    int estadoAtual = this->estadoInicial;

    for (char simbolo : input) {
        if (this->alfabeto.count(simbolo) == 0)
            return false;

        auto transicao = this->transition.find({ estadoAtual, simbolo });

        if (transicao == this->transition.end()) {
            return false;
        }

        estadoAtual = transicao->second;
    }

    return this->estadosFinais.count(estadoAtual);
}