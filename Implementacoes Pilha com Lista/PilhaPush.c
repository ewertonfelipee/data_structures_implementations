#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

void pilha_push(Pilha* p, float v){

    ListaNo* n = (ListaNo*)malloc(sizeof(ListaNo));
    n -> info = v;
    n ->prox = p -> prim; // p -> prim eh o ponteiro para o primero elemento da pilha
    p -> prim = n;
}