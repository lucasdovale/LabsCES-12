// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <TrocoSolver.h>
using namespace std;

void TrocoSolverGreedy::solve(const vector<unsigned int> &denom,unsigned int value, vector<unsigned int> &coins) {
    coins.resize(denom.size(),0);
    int i;
    for(i = denom.size() - 1; value != 0; i--) {
        while(value >= denom[i]) {
            value -= denom[i];
            coins[i]++;
        }
    }
}