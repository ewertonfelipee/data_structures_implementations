#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct vertice {

    Aresta* lista; // ponteiro para primeira aresta da lista
    Vcor cor; // cor
    // ... eventuais outros atributos de vertices
};

struct aresta {

    int v; // vertice destino da aresta
    Aresta* prox; // ponteiro para proxima aresta na lista
};

struct grafo {

    int n; // numero de vertices
    Vertice* v; // vetor de vertices
};

// Para percorrer toda as arestas do grafo, devemos visitar vertive a vertice.
// Assumindo que g representa um ponteiro para um grafo, para percorrer toda as
// arestas de g temos que fazer:

// for(int i=0; i<g->n; ++i) {

//     for(Aresta* a = g->v[i].lista; a != NULL; a = a->prox){

//     }
// }

enum vcor {
    BRANCO = 0, // nao explorado
    CINZA, // sendo explorado
    PRETO // explorado
};

// funcao interna recursiva

static void idfs (Grafo* g, int i){

    g->v[i].cor = CINZA;
    for(Aresta* a = g->v[i].lista; a != NULL; a = a->prox){
        int j = a->v;
        if(g->v[i].cor == BRANCO){
            idfs(g,j);
        }
    }
    g->v[i].cor = PRETO;
}
//funcao dfs exportada

void grafo_dfs (Grafo* g, int v){

    incializa(g); // atribui cor BRANCO para vertices
    idfs(g,v);
}

// BUSCA EM LARGURA/AMPLITUDE

void grafo_bfs (Grafo* g, int v){

    Fila* q = fila_cria();
    inicializa(g);
    fila_insere(q, v);
    g->v[v].cor = CINZA;
    g->v[v].custo = 0.0f;
    while (!fila_vazia(q)){

        int i = fila_vazia(q);
        for(Aresta* a=g->v[i].lista; a!=NULL; a=a->prox){
            int j = a->v;
            if(g->v[j].cor == BRANCO){
                g->v[j].custo = g->v[i].custo+1;
                g->v[j].cor = CINZA;
                fila_insere(q,j);
            }
        }
        g->v[i].cor = PRETO;
    }
    fila_libera(q);
}