// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <TrocoSolver.h>
using namespace std;

int TrocoSolverDivConquer::DivConq(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &ultima) {
    int i;
    recursivecalls++;
    if (value == 0) {
        return 0;
    }
    int qtd = value;
    for (i = 0; i < denom.size(); i++) {
        if (denom[i] > value) 
            continue;
        int aux = qtd;
        qtd = min(qtd, 1 + DivConq(denom, value - denom[i], ultima));
        if (qtd < aux)
            ultima[value] = denom[i];
    }
    return qtd;
} 

int TrocoSolverDivConquer::BuscaMoeda(const vector<unsigned int> &denom, int moeda) {
    for(int i = 0; i < denom.size(); i++)
        if(denom[i] == moeda) return i;
}

void TrocoSolverDivConquer::solve(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &coins) {
    coins.resize(denom.size(), 0);
    recursivecalls = 0;
    vector<unsigned int> ultima;
    ultima.resize(value + 1, 0);
    int quantMin = DivConq(denom, value, ultima);
    unsigned int num = value;
    while (quantMin != 0 && num > 0) {
        coins[BuscaMoeda(denom, ultima[num])]++;
        num -= ultima[num];
        quantMin--;
    }
}