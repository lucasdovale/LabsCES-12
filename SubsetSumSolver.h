// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#ifndef SSP_SOLVER
#define SSP_SOLVER

#include <vector>
#include <string>
#include <SubsetSumSolverAbstract.h>
using namespace std;

class SSPSolverBranchBound : public SubsetSumSolverAbstract {

public:

    virtual bool solve(const vector<long> &input, long value, vector<char> &output);
        
    virtual string getName() { return "BB"; }
    
}; 

class SSPSolverPD : public SubsetSumSolverAbstract {

public:
    
    virtual bool solve(const vector<long> &input, long value, vector<char> &output);
    
    virtual string getName() { return "PD"; }
    
}; 

#endif