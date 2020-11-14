// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <SubsetSumSolver.h>
using namespace std;

bool SSPSolverBranchBound::solve(const vector<long> &input, long value, vector<char> &output) {
    output.resize(input.size());
    bool solved = false;
    long long i, n = input.size(), soma = 0, bin = 0, subconj = (1LL << n);

    while (bin < subconj) {
        for (i = 0; i < n; i++)
            if ((bin >> i) & 1)
                soma += input[i];

        if (soma == value) {
            for (i = 0; i < n; i++) 
                if ((bin >> i) & 1)
                    output[i] = true;
                else output[i] = false;
            solved = true;
            break;
        }
        bin++;
        soma = 0;
    }
    return solved;
}