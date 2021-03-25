#include <stdio.h>
#include <stdlib.h>

void lst_retira(Lista* l, int v){

    ListaNO* ant = NULL; // cria o ponteiro para o elemento anterior
    ListaNO* p = l -> prim; // ponteiro para percerrer a lista

    // procura elemento na lista guardando o anterior
    while(p != NULL && p -> info != v){

        ant = p;
        p = p -> prox;
    }

    // verifica se achou o elemento
    if (p != NULL){ 
        // retira elemento
        if(ant == NULL){ // retira elemento do inicio

            l -> prim = p -> prox;
        }
    }
    else{ // retira elemento no meio da lista
        ant -> prox = p -> prox;
    }
    free(p);
}