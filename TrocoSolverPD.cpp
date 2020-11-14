// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <TrocoSolver.h>
using namespace std;

int TrocoSolverPD::PD(const vector<unsigned int> &denom, unsigned int value, vector<int> &quant, vector<unsigned int> &ultima) {
    int cents, quantProv, ultProv, i;
    for (cents = 1; cents <= value; cents++) {
        quantProv = cents;
        ultProv = 1;
        for (i = 0; i < denom.size(); i++) {
            if (denom[i] > cents)
                continue;
            if (quant[(cents - denom[i])] + 1 < quantProv) {
                quantProv = quant[(cents - denom[i])] + 1;
                ultProv = denom[i];
            }
        }
        quant[cents] = quantProv;
        ultima[cents] = ultProv;
    }
    return quant[value];
}

int TrocoSolverPD::BuscaMoeda(const vector<unsigned int> &denom, int moeda) {
    for(int i = 0; i < denom.size(); i++)
        if(denom[i] == moeda) return i;
}

void TrocoSolverPD::solve(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins) {
    coins.resize(denom.size(), 0); 
    vector<int> quant;
    vector<unsigned int> ultima;
    quant.resize(value + 1, 0);
    ultima.resize(value + 1, 0);
    PD(denom, value, quant, ultima);
    unsigned int num = value;
    while (num > 0) {
        coins[BuscaMoeda(denom, ultima[num])]++;
        num -= ultima[num]; 
    }
}