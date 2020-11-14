#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <bits/stdc++.h>
#include "IndexPointsAbstract.h"
using namespace std; 


class IndexPointsAluno : public IndexPointsAbstract {
public:
    
    long size();
        
    void add (float key, long idx);
    
    void find(vector<long> &res, float first, float last);
    
    enum Color {VERMELHO, PRETO}; 

    struct Noh { 
        float key;
        long id;
        bool cor;
        Noh *esq, *dir, *pai; 
        Noh() {
            this->esq = this->dir = this->pai = nullptr;
            cor = VERMELHO;
        }
        // Construtor
        Noh(float key, long id) {
            this->key = key;
            this->id = id;
            this->esq = esq;
            this->dir = dir;
            this->pai = pai; 
            this->cor = VERMELHO; 
        }
    }; 

    // Classe da árvore rubro negra
    class RBTree { 

        public:

            int tamanho; 
            Noh *raiz; 
            Noh *nil;
            // Constructor 
            RBTree() { 
                nil = new Noh (0,0);
                nil->esq = nil->dir = nil->pai = nullptr;
                nil->cor = PRETO;
                raiz = nil;
                raiz->esq = nil;
                raiz->dir = nil;
                raiz->pai = nil;
                tamanho = 0;
            } 

            void rotacaoEsq(Noh *); 
            void rotacaoDir(Noh *); 
            Noh* inserirNoh(Noh *novoNoh);
            void Balancear(Noh *novoNoh);
            void Inserir(const float& key, const long& idx); 
            void inOrder(Noh *raizRec, vector<long> &res, float first, float last);  
            
    };

    RBTree arvore;
};//class

#endif