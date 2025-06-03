#ifndef HEAP_H
#define HEAP_H 

void heapify( int* heap_max, int tam, const int j); //função que verifica se o pai é maior que os filhos, se não, troca pelo maior filho


void heapmax ( int* vetor, int tam); //função que transforma o heap em heap máximo
 
void heapsort (int* vetor, int tam ); //função que ordena o vetor usando heapsort
#endif
