#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include <ctime>
#include "sort.h"
#include <time.h>
#include<map>
using namespace std;

int main()
{
  int repeticoes = 8;
  while(repeticoes >0)
    {

      map<int,string>mp;
      mp[1] = "Selection sort";
      mp[2] = "Bubble sort";
      mp[3] = "Merge sort";
      mp[4] = "Quick sort";
      mp[5] = "Heap sort";
      mp[6] = "Insertion sort";
      mp[7] = "Radix sort";
      if(repeticoes>0 && repeticoes<=7)
        {
          cout<<mp[repeticoes]<<"\n";
          for(int tam=100; tam<=10000000;tam*=10)
            {

              int *cresce= new int[tam+10];
              int *descresce = new int[tam+10];
              int *random = new int[tam+10];

              cout<<endl<<tam<<" Elementos:\n";

              for(int i=0, j=tam-1; i<=tam && j>=0; i++,j--)
                {
                  cresce[i] = i;
                  descresce[i] = j;
                  int aleatorio = rand()%1000;
                  // cout<<"teste: "<<aleatorio;
                  random[i] = aleatorio;
                }

              if(repeticoes == 1)
                {
                  clock_t Ticks[2];
                  Ticks[0] = clock();
                  Sort::selectionSort(cresce,tam-1);
                  Ticks[1] = clock();
                  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                  cout<<"crescente:"<<Tempo<<"(ms)"<<endl;
                  Ticks[0] = clock();
                  Sort::selectionSort(descresce,tam-1);
                  Ticks[1] = clock();
                  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                  cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                  Ticks[0] = clock();
                  Sort::selectionSort(cresce,tam-1);
                  Ticks[1] = clock();
                  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                  cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                }
              else
                {
                  if(repeticoes == 2)
                    {

                      clock_t Ticks[2];
                      Ticks[0] = clock();
                      Sort::bubbleSort(cresce, tam-1);
                      Ticks[1] = clock();
                      double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                      cout<<"crescente tempo(ms): "<<Tempo<<endl;

                      Ticks[0] = clock();
                      Sort::bubbleSort(descresce, tam-1);
                      Ticks[1] = clock();
                      Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                      cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                      Ticks[0] = clock();
                      Sort::bubbleSort(random, tam-1);

                      Ticks[1] = clock();
                      Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                      cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                    }
                  else
                    {
                      if(repeticoes == 3)
                        {

                          //cout<<"\n\n\n\n\n\n\n "<<repeticoes<<"\n\n\n\n\n";
                          clock_t Ticks[2];
                          Ticks[0] = clock();
                          Sort::mergeSort(cresce, 0, tam-1);
                          Ticks[1] = clock();
                          double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                          cout<<"crescente :"<<Tempo<<"(ms)"<<endl;

                          Ticks[0] = clock();
                          Sort::mergeSort(descresce, 0, tam-1);
                          Ticks[1] = clock();
                          Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                          cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                          Ticks[0] = clock();
                          Sort::mergeSort(random, 0, tam-1);
                          Ticks[1] = clock();
                          Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                          cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                        }
                      else{
                          if(repeticoes == 4){

                              clock_t Ticks[2];
                              Ticks[0] = clock();
                              Sort::quickSort(cresce,0,tam-1);
                              Ticks[1] = clock();
                              double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                              cout<<"crescente:"<<Tempo<<"(ms)"<<endl;
                              Ticks[0] = clock();
                              Sort::quickSort(descresce,0,tam-1);
                              Ticks[1] = clock();
                              Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                              cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;


                              Ticks[0] = clock();
                              Sort::quickSort(random,0,tam-1);
                              Ticks[1] = clock();
                              Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                              cout<<"randomico:"<<Tempo<<"(ms)"<<endl;

                            }
                          else
                            {

                              if(repeticoes == 5)
                                {

                                  clock_t Ticks[2];
                                  Ticks[0] = clock();
                                  Sort::make_heap(cresce, tam-1);
                                  Ticks[1] = clock();
                                  double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                  cout<<"crescente: "<<Tempo<<"(ms)"<<endl;

                                  Ticks[0] = clock();
                                  Sort::make_heap(descresce, tam-1);
                                  Ticks[1] = clock();
                                  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                  cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                                  Ticks[0] = clock();
                                  Sort::make_heap(random, tam-1);
                                  Ticks[1] = clock();
                                  Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                  cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                                }
                              else
                                {
                                  if(repeticoes == 6)
                                    {
                                      clock_t Ticks[2];
                                      Ticks[0] = clock();
                                      Sort::insertionSort(cresce, tam-1);
                                      Ticks[1] = clock();
                                      double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                      cout<<"crescente: "<<Tempo<<"(ms)"<<endl;

                                      Ticks[0] = clock();
                                      Sort::insertionSort(descresce, tam-1);
                                      Ticks[1] = clock();
                                      Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                      cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                                      Ticks[0] = clock();
                                      Sort::insertionSort(random, tam-1);
                                      Ticks[1] = clock();
                                      Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                      cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                                    }
                                  else
                                    {
                                      if(repeticoes == 7)
                                        {
                                          clock_t Ticks[2];
                                          Ticks[0] = clock();
                                          Sort::radixSort(cresce, tam-1);
                                          Ticks[1] = clock();
                                          double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                          cout<<"crescente: "<<Tempo<<"(ms)"<<endl;

                                          Ticks[0] = clock();
                                          Sort::radixSort(descresce, tam-1);
                                          Ticks[1] = clock();
                                          Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                          cout<<"decrescente:"<<Tempo<<"(ms)"<<endl;

                                          Ticks[0] = clock();
                                          Sort::radixSort(random, tam-1);
                                          Ticks[1] = clock();
                                          Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
                                          cout<<"randomico:"<<Tempo<<"(ms)"<<endl;
                                        }
                                    }
                                }

                            }
                        }
                    }
                }
            }


        }

      repeticoes--;

    }




}
