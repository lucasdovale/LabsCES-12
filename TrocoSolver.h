// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#ifndef TROCO_SOLVER
#define TROCO_SOLVER

#include <vector>
#include <string>
#include <TrocoSolverAbstract.h>
using namespace std;

class TrocoSolverDivConquer : public TrocoSolverAbstract {
private:
    long recursivecalls;

public:
    int BuscaMoeda(const vector<unsigned int> &denom, int moeda);
    int DivConq(const vector<unsigned int> &denom, unsigned int value, vector<unsigned int> &ultima);
    virtual void solve(const vector<unsigned int> &denom,unsigned int value, vector<unsigned int> &coins); 
    virtual long countRecursiveCalls() { return recursivecalls; }
    virtual string getName() { return "DC"; }
}; 

class TrocoSolverPD : public TrocoSolverAbstract {

public:
    int PD(const vector<unsigned int> &denom, unsigned int value, vector<int> &quant, vector<unsigned int> &ultima);
    int BuscaMoeda(const vector<unsigned int> &denom, int moeda);
    virtual void solve(const vector<unsigned int> &denom,unsigned int value, vector<unsigned int> &coins); 
    virtual string getName() { return "PD"; }
}; 

class TrocoSolverGreedy : public TrocoSolverAbstract {

public:
    virtual void solve(const vector<unsigned int> &denom,unsigned int value, vector<unsigned int> &coins); 
    virtual string getName() { return "GR"; }    
}; 

#endif