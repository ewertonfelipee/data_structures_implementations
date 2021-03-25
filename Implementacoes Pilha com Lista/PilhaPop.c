#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

float pilha_pop(Pilha* p){

    ListaNo* t = p -> prim;
    float v = t -> info;//pega a informacao para retornar o valor posteriormente
    p -> prim = t -> prox;
    free(t);
    return v;
}