// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 5 - Problema do Caixeiro Viajante
// Escrito por Lucas do Vale Bezerra, COMP-22

#ifndef TSP_SOLVER
#define TSP_SOLVER

#include <TspReader.h>
#include <vector>
#include <set>
using namespace std;

class TspSolver {
    
public:

    void DFS(int s, vector<int> &percourse, set < pair<int, int> > MST[], bool marcado[]);
    void solve(TspReader &tr, vector<int> &percourse); 

}; 

#endif