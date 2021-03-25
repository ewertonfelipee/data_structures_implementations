#include <stdio.h>
#include <stdlib.h>

void lst_insere_ordenado(Lista* l, int v){

    ListaNO* ant = NULL; // cria o ponteiro para o elemento anterior
    ListaNO* p = l -> prim; // percorre a lista

    // cria novo elemento
    ListaNO* novo = (ListaNO*)malloc(sizeof(ListaNO*))
    novo -> info = v;

    while(p != NULL && p -> info < v){

        ant = p;
        p = p -> prox;
    }

    // encadeia novo elemento
    if (ant == NULL)
    {
        novo -> prox = l -> prim; // insere elemento no inicio
        l -> prim = novo;
    }
    else{ // insere elemento no meio da lista
        novo -> prox = ant -> prox;
        ant -> prox = novo;
    }
    
}