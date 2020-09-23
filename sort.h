#ifndef SORT_H
#define SORT_H
#include<iostream>


class Sort
{
private:
  static int particao(int *vet, int inicio, int fim);
  static void merge(int *vet, int f, int m, int l);
  static void max_heapify(int *vet, int n, int i);
  static void counting(int *vet, int n, int k);
  static int getMax(int *vet, int n);
public:
  Sort();
  static void selectionSort( int *vet, int tam);
  static void bubbleSort(int *vet, int tam);
  static void mergeSort(int *vet, int f, int l);
  static void quickSort(int *vet, int inicio, int final);
  static void make_heap(int *vet, int n);
  static void insertionSort(int *vet, int n);
  static void radixSort(int *vet, int n);
  static void printVet(int *vet, int n){for(int i=0;i<n;i++) std::cout<<vet[i]<<" "; std::cout<<std::endl;}


};

#endif // SORT_H
