#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define pai(i) (((i)-1)/2) //indice de no pai
#define esq(i) (2*(i)+1) // indice do filho a esquerda
#define dir(i) (2*(i)+2) // indide do filho a direita

struct heap
{
    int n;
    int nmax;
    float* v;
};

Heap* heap_cria (int nmax){

    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->n = 0; // inicializa com zero elementos no vetor
    h->nmax = nmax;
    h->v = (float*)malloc(h->nmax*sizeof(float));
    return h;
}

void heap_libera (Heap* h){

    free (h->v);
    free(h);
}

int heap_vazia (Heap* h){

    return (h->n==0);
}

static void troca (Heap* h, int i, int j){

    float tmp = h->v[i];
    h->v[i] = h->v[j];
    h->v[j] = tmp;
}

static void sobe (Heap* h, int i){

    while(i > 0){ // enquanto nao alcancar a raiz
        int p = pai(i);
        if(h->v[p] > h->v[i]){
            break;
        }
        troca(h,p,i);
        i = p;
    }
}

void heap_insere (Heap* h, float value){

    h->v[h->n++] = value;
    sobe(h, h->n-1);
}

static void desce (Heap* h, int i){

    int c = esq(i);
    while(c < h->n){ // esquanto o filho for valido

        int c2 = dir(i);
        if(c2 < h->n && h->v[c2] > h->v[c]){ // filho da direita pode nao existir se existir, testa se eh maior
            c =c2;
        }
        if (h->v[c] < h->v[i]){
            break;
        }
        troca(h, i, c);
        i = c;
        c = esq(i);
    }
}

float heap_retira (Heap* h){

    float r = h->v[0];
    h->v[0] =  h->v[--h->n];
    desce (h, 0);
    return r;
}

int heap_verifica (Heap* h){

    int i;
    for(i = 0; i < h->n/2; ++i){
        int l = esq(i);
        int r = dir(i);
        if(h->v[l] > h->v[i]){
            return 0;
        }
        if(r < h->n && h->v[r] > h->v[i]){
            return 0;
        }
    }
    return 1;
}
