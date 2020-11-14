// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 4 - Paradigmas da programação
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <SubsetSumSolver.h>
using namespace std;

bool SSPSolverPD::solve(const vector<long> &input, long value, vector<char> &output) {
    output.resize(input.size());
    vector<vector<long>> B;
    B.resize(input.size() + 1);
    for (auto it = B.begin(); it != B.end(); ++it)
        it->resize(value+1);
    // Slide Alonso
    int i,k;
    for(i = 0; i <= value; i++)
        B[0][i] = 0;
    for(k = 1; k <= input.size(); k++)
        for(i = 0; i <= value; i++)
            if(input[k-1] > i) 
                B[k][i] = B[k-1][i];
            else B[k][i] = max(B[k-1][i], B[k-1][i-input[k-1]] + input[k-1]);
    // Preenchida matriz B
    long r = value;
    int s = B[input.size()][value];
    for(i = input.size(); i > 0; i--)
        if(B[i-1][r] == s)
            output[i-1] = false;
        else {
            output[i-1] = true;
            s -= input[i-1];
            r -= input[i-1];
        }
    // Preenchido o vetor output

    // Verificando se o problema foi resolvido
    if(B[input.size()][value] == value)
        return true;
    return false;
}