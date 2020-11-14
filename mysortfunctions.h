// CES-12: Algoritmos e Estruturas de Dados II
// Professor: Luiz Gustavo Bizarro Mirisola
// Lab 3 - Sorting
// Escrito por Lucas do Vale Bezerra, COMP-22

#ifndef YOURSORTFUNCTIONS_H
#define YOURSORTFUNCTIONS_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <sortauxfuncs.h>

// MergeSort
void merge(int i, int m, int f, std::vector<int> &v, SortStats &stats);
void mymergesort_recursive(std::vector<int> &v, SortStats &stats);
void mymergesort_iterative(std::vector<int> &v, SortStats &stats);
void MergeSort(int i, int f, std::vector<int> &v, SortStats &stats, int recursionDepth);
void MergeSortIterativo(int i, int f, std::vector<int> &v);

// QuickSort
int med3(int a, int b, int c);
int Partition_pivotMed(std::vector<int> &v, int left, int right);
int Partition_pivotFixo(std::vector<int> &v, int left, int right);
void QuickSort1Rec(std::vector<int> &v, int min, int max, SortStats &stats, int recursionDepth);
void QuickSort2Rec(std::vector<int> &v, int min, int max, SortStats &stats, int recursionDepth);
void QuickSortFixo(std::vector<int> &v, int min, int max, SortStats &stats, int recursionDepth);
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats);
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats);
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats);

// RadixSort
int log(int x);
void RadixSort(std::vector<int> &v);
void myradixsort(std::vector<int> &v, SortStats &stats);

#endif