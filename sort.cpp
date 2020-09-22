#include "sort.h"
#include<iostream>
#include<algorithm>
#include <time.h>

Sort::Sort()
{

}

 void Sort::selectionSort( int *vet,int tam)
{
   int i, j, menor;
   //std::cout<<"testando ss"<<tam<<"\n";
   for(i=0; i<tam-1;i++)
     {
        menor = i;
       for(j=i+1; j<tam;j++)
         {

           if (vet[j]<vet[menor])
           {
                menor = j;
           }
         }
       int aux = vet[i];
       vet[i]= vet[menor];
       vet[menor] = aux;

     }
}

void Sort::bubbleSort(int *vet, int tam)
{
  bool condicao = true;

  for(int qtd = tam-1 ; qtd>0 && condicao ; qtd--)
    {
      condicao=false;
      for(int i=0; i<qtd;i++) // uma percorrida pelo vetor
        {
          if(vet[i]>vet[i+1])
            {

              condicao = true;
              int aux = vet[i];
              vet[i]= vet[i+1];
              vet[i+1] = aux;
            }
        }
    }

}
void Sort::merge(int *vet, int f, int m, int l)
{
  int *aux = new int [l-f+1];
  int i=f, j=m+1;
  bool f1,f2;
  f1=f2=false;
  for(int k=0; k < l-f+1 ; k++)
    {
      if(!f1 && !f2)
        {
          if(vet[i]<vet[j])
            {
              aux[k]=vet[i];
              i++;
            }
          else
            {
              aux[k]=vet[j];
              j++;
            }

          if(i>m) f1=true;
          if(j>l) f2=true;
        }
        else
        {
          if(f1)
            {
              aux[k]= vet[j];
              j++;
            }
            else{
              aux[k]=vet[i];
              i++;
            }
        }

    }
for(int a = 0, b=f; a<l-f+1; a++,b++)
  {
    vet[b]=aux[a];
  }
  delete[] aux;
}

void Sort::mergeSort(int *vet, int f, int l)
{
 // std::cout<<"\nchamou o merge\n";
  int m;
  if(f<l)
    {
      m = (l + f)/2;
      mergeSort(vet,f,m);
      mergeSort(vet,m+1, l);
      merge(vet, f,m,l);
    }
}

void Sort::quickSort(int *vet, int inicio, int final)
{
  int pivo;
    if(inicio<final)
      {
        pivo = particao(vet, inicio, final);
        quickSort(vet, inicio, pivo-1);
        quickSort(vet, pivo+1, final);
      }
}
int Sort::particao(int *vet, int inicio, int fim)
{
  int aleatorio = rand()%(fim - inicio+1) +inicio;
  int aux = vet[inicio]; vet[inicio] = vet[aleatorio]; vet[aleatorio] = inicio;
  int pivot = vet[inicio];
  int esq,dir;
  for(esq = inicio, dir = fim + 1; esq<dir;)
    {
      do esq++; while(esq<=fim && vet[esq]<pivot);
      do dir--; while(vet[dir] > pivot);

      if(esq<dir) // ainda nao é o final
        {
          int aux = vet[esq]; vet[esq] = vet[dir]; vet[dir] = aux;
        }
    }

    aux = vet[inicio]; vet[inicio] = vet[dir]; vet[dir] = aux;
    return dir;

}

void Sort::max_heapify(int *vet, int n, int i)
{
  int e =2*i;
  int d = e+1;
  int maior = i;
  if(e<=n && vet[e]>vet[i]) maior = e;
  if(d<=n && vet[d]> vet[maior]) maior = d;

  if(maior != i)
    {
      int aux = vet[i]; vet[i] = vet[maior]; vet[maior] = aux;
      max_heapify(vet, n, maior);
    }
}
void Sort::make_heap(int* vet, int n)
{
  for(int i = n/2 ; i>0; i--)
    {
        max_heapify(vet, n, i);
    }
  for(int i=n; i>1 ; i--)
    {
      int aux = vet[1];
      vet[1] = vet[i];
      vet[i] = aux;
      max_heapify(vet, i-1, 1);
    }
}
void Sort::insertionSort(int *vet, int n)
{
  int i, j, aux;
  for(i=1;i<n;i++)
    {
      aux = vet[i];
      for(j=i; (j>0) && (aux<vet[j-1]);j--)
        {
          vet[j] = vet[j-1];
        }
      vet[j] = aux;
    }
}
