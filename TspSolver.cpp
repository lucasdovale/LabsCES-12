// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 5 - Problema do Caixeiro Viajante
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <TspSolver.h>
#include <vector>
#include <set>
using namespace std;

#define INF 1000000000

void TspSolver::DFS(int s, vector<int> &percourse, set < pair<int, int> > MST[], bool marcado[]) {
    marcado[s] = true;
    percourse.push_back(s + 1);
    for (auto elemento : MST[s]) {
        int distancia = elemento.first;
        int v = elemento.second;
        if(!marcado[v])
            DFS(v, percourse, MST, marcado);
    }
}

void TspSolver::solve(TspReader &tr, vector<int> &percourse) {
    vector<City> cidades;
    int N = tr.getNumCities(); 
    cidades.resize(N);
    tr.copyCitiesVector(cidades);

    int distancias[N][N];
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            distancias[i][j] = cidades[i].disti(cidades[j]);

    vector < pair<int, int> > dist;
    dist.resize(N);
    for (int i = 0; i < N; i++) dist[i] = make_pair(INF, i);
    dist[0] = make_pair(0, 0);

    set < pair<int, int> > MST[N];
    bool marcado[N] = {false};
    int p = 0;
    while(p != -1) {
        marcado[p] = true;
        for(int i = 0; i < N; i++) {
            pair<int, int> candidato = make_pair(distancias[p][i], p);
            dist[i] = min(dist[i], candidato);
        }
        p = -1;
        for(int i = 0; i < N; i++) {
            if(!marcado[i]) {
                if(p == -1)
                    p = i;
                else if(dist[i] < dist[p])
                    p = i;
            }
        }
        if(p != -1) {
            MST[p].insert(make_pair(dist[p].first, dist[p].second));
            MST[dist[p].second].insert(make_pair(dist[p].first, p));
        }
    }
    for(int i = 0; i < N; i++)
        marcado[i] = false;
    DFS(0, percourse, MST, marcado);
}