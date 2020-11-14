// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 3 - Sorting
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <mysortfunctions.h>
#include <math.h>
using namespace std;

void merge(vector<int> &v, int i, int m, int f, vector<int> &aux, SortStats &stats) {
    stats.recursive_calls++;                       
    int i1 = i;
    int i2 = i;
    int i3 = m + 1;
    while (i2 <= m && i3 <= f) {
        if (v[i2] < v[i3])
            aux[i1++] = v[i2++];
        else aux[i1++] = v[i3++];
    }
    while (i2 <= m) {
        aux[i1++] = v[i2++];
    }
    while (i3 <= f) {
        aux[i1++] = v[i3++];
    }
    for (int j = i; j <= f; j++)
        v[j] = aux[j];
}

void MergeSort(vector<int> &v, vector<int> &aux, int i, int f, SortStats &stats, int recursionDepth) {
    stats.recursive_calls++; 
    stats.depth_recursion_stack = max((int) stats.depth_recursion_stack, recursionDepth);                      
    if (i < f) {
            int m = (i + f)/2;
            MergeSort(v, aux, i, m, stats, recursionDepth + 1);          
            MergeSort(v, aux, m + 1, f, stats, recursionDepth + 1);
            merge(v, i, m, f, aux, stats);
    }
}

void MergeSortIterativo(vector<int> &v, vector<int> &aux, int i, int f, SortStats &stats) {
    int b = 1;
    int p, m, r;
    while (b < f) {
        p = i;
        while (p + b <= f) {
            r = f;
            if (f > p - 1 + 2 * b)
                r = p - 1 + 2 * b;
            m = p + b - 1;
            merge(v, p, m, r, aux, stats);
            p += 2 * b;
        }
        b *= 2;
    }
}

void mymergesort_recursive(vector<int> &v, SortStats &stats) {
    vector<int> aux(v.size());
    stats.recursive_calls = 0;
    stats.depth_recursion_stack = 0;
    MergeSort(v, aux, 0, v.size() - 1, stats, 1);
}

void mymergesort_iterative(vector<int> &v, SortStats &stats) {  
    vector<int> aux(v.size());
    stats.recursive_calls = 1;
    MergeSortIterativo(v, aux, 0, v.size() - 1, stats);
    stats.depth_recursion_stack = 1;
}