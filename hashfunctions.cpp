// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 1 - Hashing
// Escrito por Lucas do Vale Bezerra, COMP-22

#include "hashfunctions.h"

// função que retorna o lugar que a string vai ficar
int hashdiv(std::string str, int m) { 
    int hvalue, soma = 0;
    // percorre a string
    for (char c : str) 
    // soma seus caracteres
        soma += c;
    // calcula o resto da soma pelo tamanho do vetor
    hvalue = soma % m;
    // lugar do vetor que a string vai entrar na hash
    return hvalue; 
}

// chamada da funçao hashdiv com vetor de tamanho 29
int hashdiv29(std::string str) {
    return hashdiv(str,29);
}