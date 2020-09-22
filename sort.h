#ifndef SORT_H
#define SORT_H


class Sort
{
private:
  static int particao(int *vet, int inicio, int fim);
  static void merge(int *vet, int f, int m, int l);
  static void max_heapify(int *vet, int n, int i);
public:
  Sort();
  static void selectionSort( int *vet, int tam);
  static void bubbleSort(int *vet, int tam);
  static void mergeSort(int *vet, int f, int l);
  static void quickSort(int *vet, int inicio, int final);
  static void make_heap(int *vet, int n);
  static void insertionSort(int *vet, int n);


};

#endif // SORT_H
