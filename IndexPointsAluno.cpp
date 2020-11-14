// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 2 - Árvores Balanceadas
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <IndexPointsAluno.h>
using namespace std; 

typedef IndexPointsAluno::RBTree RBTree;
typedef IndexPointsAluno::Noh Noh;

// Faz uma rotação simples pela esquerda
void RBTree::rotacaoEsq(Noh *novoNoh) {
  Noh *pt_dir = novoNoh->dir;
  novoNoh->dir = pt_dir->esq;
  if (pt_dir->esq != nil) {
    pt_dir->esq->pai = novoNoh;
  }
  pt_dir->pai = novoNoh->pai;
  if (novoNoh->pai == nil) {
    raiz = pt_dir;
  } else if (novoNoh == novoNoh->pai->esq) {
    novoNoh->pai->esq = pt_dir;
  } else {
    novoNoh->pai->dir = pt_dir;
  }
  pt_dir->esq = novoNoh;
  novoNoh->pai = pt_dir;
}

// Faz uma rotação simples pela direita
void RBTree::rotacaoDir(Noh *novoNoh) {
  Noh *pt_esq = novoNoh->esq;
  novoNoh->esq = pt_esq->dir;
  if (pt_esq->dir != nil) {
    pt_esq->dir->pai = novoNoh;
  }
  pt_esq->pai = novoNoh->pai;
  if (novoNoh->pai == nil) {
    raiz = pt_esq;
  } else if (novoNoh == novoNoh->pai->dir) {
    novoNoh->pai->dir = pt_esq;
  } else {
    novoNoh->pai->esq = pt_esq;
  }
  pt_esq->dir = novoNoh;
  novoNoh->pai = pt_esq;
}

// Insere o Noh sem se preocupar com o banlanceamento
Noh* RBTree::inserirNoh(Noh *novoNoh) {
  Noh *y = nil;
  Noh *x = raiz;
  while (x != nil) {
    y = x;
    if (novoNoh->key < x->key) {
      x = x->esq;
    } else {
      x = x->dir;
    }
  }
  novoNoh->pai = y;
  if (y == nil) {
    raiz = novoNoh;
  } else if (novoNoh->key < novoNoh->pai->key) {
    y->esq = novoNoh;
  } else {
    y->dir = novoNoh;
  }
  novoNoh->esq = novoNoh->dir = nil;
  novoNoh->cor = VERMELHO;
  Balancear(novoNoh);
}

// Balanceia a árvore após inserir um Noh
void RBTree::Balancear(Noh *novoNoh) {
  Noh *y = nil;
  while (novoNoh->pai->cor == VERMELHO) {
    if (novoNoh->pai == novoNoh->pai->pai->esq) {
      y = novoNoh->pai->pai->dir;
      if (y->cor == VERMELHO) {
        novoNoh->pai->cor = PRETO;
        y->cor = PRETO;
        novoNoh->pai->pai->cor = VERMELHO;
        novoNoh = novoNoh->pai->pai;
      } else {
        if (novoNoh == novoNoh->pai->dir) {
          novoNoh = novoNoh->pai;
          rotacaoEsq(novoNoh);
        }
        novoNoh->pai->cor = PRETO;
        novoNoh->pai->pai->cor = VERMELHO;
        rotacaoDir(novoNoh->pai->pai);
      }
    } else if (novoNoh->pai == novoNoh->pai->pai->dir) {
      y = novoNoh->pai->pai->esq;
      if (y->cor == VERMELHO) {
        novoNoh->pai->cor = PRETO;
        y->cor = PRETO;
        novoNoh->pai->pai->cor = VERMELHO;
        novoNoh = novoNoh->pai->pai;
      } else {
        if (novoNoh == novoNoh->pai->esq) {
          novoNoh = novoNoh->pai;
          rotacaoDir(novoNoh);
        }
        novoNoh->pai->cor = PRETO;
        novoNoh->pai->pai->cor = VERMELHO;
        rotacaoEsq(novoNoh->pai->pai);
      }
    }
  }
  while (raiz->pai != nil)
    raiz = raiz->pai;
  raiz->cor = PRETO;
}

// Insere um Noh com conteúdo "data" na árvore
void RBTree::Inserir(const float &key, const long& idx) {
  Noh *novoNoh = new Noh(key, idx);
  // Apenas insere o Noh sem preocupar com o balanceamento
  raiz = inserirNoh(novoNoh);
  // Aumenta o numero de Nohs na árvore
  tamanho++;
}

// Percurso InOrder que retorna tamanho
void RBTree::inOrder(Noh *raizRec, vector<long> &res, float first, float last) {

  if (raizRec != nil) {

    if (first <= raizRec->key) inOrder(raizRec->esq, res, first, last);

    if (first <= raizRec->key && raizRec->key <= last) {
      res.push_back(raizRec->id);
    }
    
    if (last >= raizRec->key) inOrder(raizRec->dir, res, first, last);
  }
}

// Retorna a quantidade de nós na árvore
long IndexPointsAluno::size() {
  return arvore.tamanho;
}

// Insere um elemento com chave key e indice idx na árvore
void IndexPointsAluno::add (float key, long idx) {
  arvore.Inserir(key, idx);
}

// Busca todos os elementos na árvore que tem chave entre first e last
void IndexPointsAluno::find(vector<long> &res, float first, float last) {
  arvore.inOrder(arvore.raiz, res, first, last);
}