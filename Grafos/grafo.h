#include <stdio.h>
#include <stdlib.h>

typedef struct grafo Grafo;

typedef struct vertice Vertice;

typedef struct aresta Aresta;

typedef enum vcor Vcor;

typedef struct fila Fila;

Fila* fila_cria(void);

void fila_insere(Fila* f, float v);

float fila_retira(Fila* f);

int fila_vazia(Fila* f);

void fila_libera(Fila* f);

void fila_imprime(Fila*);