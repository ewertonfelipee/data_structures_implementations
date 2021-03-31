#include <stdio.h>
#include <stdlib.h>
#include "TADStackArray.h"

/* Para a implementacao de uma pilha com vetor precisamos armazenar o elementos
da pilha em uma array. Os elementos inseridos ocupam as primeiras posicoes do vetor.
Se temos N elementos na pilha, o elemento vetor-1 sera o elemento do topo.
*/

struct pilha{

    int n; // numero de elementos armazenados
    int dim; // dimensao corrente do vetor
    float* vet; // vetor dos elementos
};

Pilha* pilha_cria(void){ 
    
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p -> dim = 2; //dimensao incial
    p -> vet = (float*)malloc(p->dim*sizeof(float));
    p-> n = 0; // inicializa com zero elementos
    return p;
}

void pilha_push(Pilha *p, float v){

    if(p -> n == p -> dim){ // capacidade esgotada. aqui testa se a quantidade
    // de elementos na pilha eh igual a capacidade a dimensao inicial
        p -> dim *= 2;
        p -> vet = (float*)realloc(p -> vet, p -> dim*sizeof(float));
    }
    // insere elemento na proxima posicao livre
    p -> vet[p -> n++] = v;
}

float pilha_pop(Pilha* p){

    float v = p -> vet[--p -> n]; // retira elemento do topo
    return v;
}

int pilha_vazia(Pilha* p){

    return(p -> n == 0);
}

void pilha_libera(Pilha* p){

    free(p -> vet);
    free(p);
}

float pilha_topo(Pilha* p){

    if(pilha_vazia(p)){
        printf("pilha vazia\n");
        exit(1);
    }
    return p -> vet[p -> n - 1];
}