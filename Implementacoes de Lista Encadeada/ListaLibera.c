#include <stdio.h>
#include <stdlib.h>

void lst_libera(Lista* l){

    ListaNO* p = l -> prim;
    while(p != NULL){

        ListaNO* t = p -> prox; // guarda a referencia para o prox nó
        free(p); // libera a memoria apontada por p
        p = t; // faz p apontar para o proximo
    }
    free(t);

}