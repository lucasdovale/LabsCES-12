// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 3 - Sorting
// Escrito por Lucas do Vale Bezerra, COMP-22

#include <mysortfunctions.h>
#include <math.h>
using namespace std;

int med3(int a, int b, int c) {
    int soma = a + b + c;
    int maior, menor = a;
    if (b > maior)
        maior = b;
    if (c > maior)
        maior = c;
    if (b < menor)
        menor = b;
    if (c < menor)
        menor = c;
    return (soma - maior - menor);
}

int Partition_pivotMed(vector<int> &v, int left, int right) {
    int pivot = med3(v[left], v[(left + right)/2], v[right]);
    int l = left + 1;
    int r = right;
    int aux;
    while (true) {
        while (l < right && v[l] < pivot)
            l++;
        while (r > left && v[r] >= pivot)
            r--;
        if (l >= r)
            break;
        aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}

int Partition_pivotFixo(vector<int> &v, int left, int right) {
    int pivot = v[left];
    int l = left + 1;
    int r = right;
    int aux;
    while (true) {
        while (l < right && v[l] < pivot)
            l++;
        while (r > left && v[r] >= pivot)
            r--;
        if (l >= r)
            break;
        aux = v[l];
        v[l] = v[r];
        v[r] = aux;
    }
    v[left] = v[r];
    v[r] = pivot;
    return r;
}

void QuickSort1Rec(vector<int> &v, int menor, int maior, SortStats &stats, int recursionDepth) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = max((int) stats.depth_recursion_stack, recursionDepth);
    while (menor < maior) {
        int p = Partition_pivotMed(v, menor, maior); stats.recursive_calls++;
        if (p - menor < maior - p) {
            QuickSort1Rec(v, menor, p - 1, stats, recursionDepth + 1);
            menor = p + 1;
        }
        else {
            QuickSort1Rec(v, p + 1, maior, stats, recursionDepth + 1);
            maior = p -1;
        }
    }
}

void QuickSort2Rec(vector<int> &v, int menor, int maior, SortStats &stats, int recursionDepth) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = max((int) stats.depth_recursion_stack, recursionDepth);
    if (menor < maior) {
        int p = Partition_pivotMed(v, menor, maior); stats.recursive_calls++;
        QuickSort2Rec(v, menor, p - 1, stats, recursionDepth + 1);
        QuickSort2Rec(v, p + 1, maior, stats, recursionDepth + 1);
    }
}

void QuickSortFixo(vector<int> &v, int menor, int maior, SortStats &stats, int recursionDepth) {
    stats.recursive_calls++;
    stats.depth_recursion_stack = max((int) stats.depth_recursion_stack, recursionDepth);
    if (menor < maior) {
        int p = Partition_pivotFixo(v, menor, maior); stats.recursive_calls++;
        QuickSortFixo(v, menor, p - 1, stats, recursionDepth + 1);
        QuickSortFixo(v, p + 1, maior, stats, recursionDepth + 1);
    }
}

void myquicksort_2recursion_medianOf3(vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 0;
    stats.depth_recursion_stack = 0;
    QuickSort2Rec(v, 0, v.size() - 1, stats, 1);
}

void myquicksort_1recursion_medianOf3(vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 0; 
    stats.depth_recursion_stack = 0;
    QuickSort1Rec(v, 0, v.size() - 1, stats, 1);
}

void myquicksort_fixedPivot(vector<int> &v, SortStats &stats) {
    stats.recursive_calls = 0;
    stats.depth_recursion_stack = 0;
    QuickSortFixo(v, 0, v.size() - 1, stats, 1);
}