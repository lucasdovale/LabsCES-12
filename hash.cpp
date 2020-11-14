// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 1 - Hashing
// Escrito por Lucas do Vale Bezerra, COMP-22

#include "hash.h"
#include "hashfunctions.h"
#include <string>
using namespace std; 


Hash::Hash(int tablesize, int (*hf) (std::string)) { 
    _table.resize(tablesize); 
    _hash_func = hf;
}


int Hash::add(std::string str, int &collisions) { 
    if (contains(str,collisions))
        return 0;
    else {
    int index = _hash_func(str);
    _table[index].push_front(str);
    return 1;
    }
} //add


int Hash::remove(std::string str, int &collisions) { 

    int index = _hash_func(str); 

    forward_list <string> :: iterator i; 
    for (i = _table[index].begin(); i != _table[index].end(); i++) { 
        if ((*i).compare(str) == 0) 
            break; 
    }
    
    if (i != _table[index].end()) {
        _table[index].remove(*i);
        return 1;
    }
    else return 0;  
} //remove


int Hash::hash(std::string str) { 
    int hash = 0;
    int indice;

    for(int i = 0; i < str.length(); i++) {
        hash = hash + (int)str[i];
    }
    indice = hash % _table.size();
    return indice;
} //hash
    

int Hash::contains(std::string str, int &collisions) {   

    int index = _hash_func(str); 
    collisions = 0;
    if(_table[index].empty()){
        return 0;
    }
    else {
        forward_list <string> :: iterator i; 
        for (i = _table[index].begin(); i != _table[index].end(); i++) {
            collisions++;
            if ((*i).compare(str) == 0) 
                return 1; 
        }
        if (i ==_table[index].end()) 
            return 0;
    }
} //contains


int Hash::worst_case() {
    int cont = 0, max = 0;
    for (int i = 0; i < _table.size(); i++) {
        forward_list <string> :: iterator j; 
        for (j = _table[i].begin(); j != _table[i].end(); j++) {
            cont++;
        }
        if (cont > max)
            max = cont;
        cont = 0;
    }

    return max;
} //worst_case


int Hash::size() {
    int cont = 0, total = 0;
    for (int i = 0; i < _table.size(); i++) {
        forward_list <string> :: iterator j;
        for (j = _table[i].begin(); j != _table[i].end(); j++) {
            cont++;
        }
        total += cont;
        cont = 0;
    }

    return total;
} //size