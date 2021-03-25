#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

void pilha_libera(Pilha* p){

    ListaNo* q = p -> prim; // variavel auxiliar para armazenar o primeiro elemento
    while(q != NULL){
        ListaNo* t = q -> prox;
        free(q);
        q = t;
    }
    free(p);
}