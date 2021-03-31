#include <stdio.h>
#include <stdlib.h>

typedef struct heap Heap;

// cria uma nova lista de prioridade vazia
Heap* heap_cria (int nmax);

//libera a lista de prioridade
void heap_libera (Heap* h);

//verifica se a lista esta vazia: 1 se vazia; 0 se nao
int heap_vazia (Heap* h);

//insere um novo valor na lista de prioridade
void heap_insere (Heap* h, float value);

//retira e retorna o maior valor da lista de priordade
float heap_retira (Heap* h);

int heap_verifica (Heap* h);

// construcao da lista de prioridade
Heap* heap_constroi (int n, float* v);