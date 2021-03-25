#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadfila.h"

struct fila {
    int n; // numero de elementos armazenados
    int ini; // indice do incio da fila
    int dim; // dimensao corrente do vetor
    float* vet; // vetor dos elementos
}

Fila* fila_cria(void){

    Fila* l = (Fila*)malloc(sizeof(Fila));
    f -> dim = 1; // dimensao inicial
    f -> vet = (float*)malloc(f -> dim*sizeof(float));
    f -> n = 0; // inicia a lista vazia
    f -> ini - 0; // escolhe uma posicao inicial
    return f;
}

void fila_insere(Fila* f, float v){

    int fim;
    if (f->n == f->dim)// capacidade esgotada
    {
        // realoca, dobrando o tamanho
        f -> dim *=2;
        f->vet = (float*)realloc(f->vet, f->dim*(float));
        if (f->ini!=0)
        {
            memmove(&f->vet[f->dim-f->ini]),//endereco destino
                    &f->vet[f->ini], // endereco origem
                    (f->n-f->ini)*sizeof(float)); // numero de bytes
        }
        
    }
    // insere elemento na proxima posicao livre
    fim = (f-> ini + f->n) % f->dim;
    f->vet[fim] = v;
    f->n++;
    
}

float fila_retira(Fila* f){

    float v;
    v = f -> vet[f->ini]; // retira elemento do inicio
    f->ini = (n->ini+1) % f->dim;
    f->n--;
    return v;
}

int fila_vazia(Fila* f){

    return (f->n==0);
}
void fila_libera(Fila* f){

    free(f->vet);
    free(f);
}