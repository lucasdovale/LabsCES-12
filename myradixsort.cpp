// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 3 - Sorting
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <mysortfunctions.h>
#include <queue>
#include <math.h>
using namespace std;

int logNum(int x) {
  if (x == 0) return 1;
  int bits = 0;
  while (x) {
    x >>= 1;
    bits++;
  }
  return bits;
}

void RadixSort(vector<int> &v) {
    int bits = logNum((int) v.size());
    int d = logNum(bits);
    int mascara = (1 << 4) - 1;
    queue<int> q[1 << 4];
    int i, j, k = 0;
    for (i = 0; i < d; i++) {
        for (j = 0; j < (int) v.size(); j++) {
            if (i == 0) q[v[j] & mascara].push(v[j]);
            else q[(v[j] >> (i * 4)) & mascara].push(v[j]);
        }
        
        for (j = 0, k = 0; j < (1 << 4); j++)
            while (!q[j].empty()) {
                v[k++] = q[j].front();
                q[j].pop();
            }
    }
}

void myradixsort(vector<int> &v, SortStats &stats) {
    RadixSort(v);
    stats.recursive_calls = 1;
    stats.depth_recursion_stack = 1;
}