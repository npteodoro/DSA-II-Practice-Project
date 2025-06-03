
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"


void heapify( int* heap_max, int tam, const int j) //função que verifica se o pai é maior que os filhos, se não, troca pelo maior filho
{


    int maior_filho; // <-- variavel auxiliar que tem o indice do maior filho
    maior_filho = (heap_max [2*j + 1] > heap_max[2*j + 2] )? (2*j + 1) : (2*j + 2); // <-- descobre qual é a posição do maior filho

    //se o pai for menor que o maior filho os dois trocam de lugar:
    if (heap_max [j] < heap_max [maior_filho]) {
 int tr1,tr2; // <-- variavel auxiliar para a troca
 tr1 =  heap_max[j];
 tr2 = heap_max[maior_filho];
 heap_max[maior_filho] = tr1;
 heap_max[j] = tr2;

    }
    else return;// <-- se não sai da recursividade

    if (maior_filho < (tam/2) - 1 ) heapify(heap_max , tam , maior_filho); //se o maior filho não for folha ajusta recursivamente os nós abaixo desse
return;
}

void heapmax ( int* vetor, int tam) //função que transforma o heap em heap máximo
 {
   int L; //variavel auxiliar
   int meio = tam/2 - 1 ;//variavel auxiliar para saber onde começar a transformação (ultimo nó interno)

   for (L=meio;L>=0;L--){ //para todos os nós não folhas

    heapify(vetor, tam, L); //corrige a posição do indice L em relação aos seus filhos
  }
 }



void heapsort (int* vetor, int tam )
{
    //considerando o vetor como uma arvore binária da forma:
    //raiz: vetor[0]
    //pai do elemento n: floor([n − 1]/2)
    //filho esquerdo do elemento n: 2n + 1
    //filho direito do elemento n: 2n + 2
 heapmax(vetor,tam); //transformar o vetor em heapmax


 //usar propriedades do heapmax para odenar o vetor:
    int k; // <-- varivael auxiliar que indica quantos valores ja estão ordenados
    


    for (k=0; tam - k >= 3 ; k++){

 int tr1,tr2; // <-- variavel auxiliar para a troca
 tr1 = vetor[0];
 tr2 = vetor[tam - k-1];
 vetor[tam - k - 1] = tr1;
 vetor[0] = tr2;

if (tam-k == 3) break;



 heapify(vetor,tam-k,0); //corrige a posição da raiz , que foi recem trocada


    }

    if(vetor[0] > vetor [1] ) 
    {
    //troca o primeiro pelo segundo, pois sabemos que o terceiro já esta ordenado
        int tr1,tr2; // <-- variavel auxiliar para a troca
 tr1 = vetor[0];
 tr2 = vetor[1];
 vetor[1] = tr1;
 vetor[0] = tr2;
    }
        //vetor esta em ordem crescente, contudo para as torres de hanoi é mais facil de visualizar se o vetor estiver em ordem decrescente



    for (int m=0;m<=tam/2;m++) // função para transformar crescente em decrescente
    {
        
    //troca de posição numeros simétricos em relação ao meio
int tr1,tr2; // <-- variavel auxiliar para a troca
 tr1 = vetor[m];
 tr2 = vetor[tam-m-1];
 vetor[tam - m - 1] = tr1;
 vetor[m] = tr2;
    }


}

