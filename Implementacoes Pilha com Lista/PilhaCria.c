#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

Pilha* pilha_cria(void){

    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p -> prim = NULL;
    return p;
}