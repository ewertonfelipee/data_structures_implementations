#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

void pilha_imprime(Pilha* p){

    for(ListaNo q = p -> prim; q != NULL; q=q->prox){

        printf("%f\n", q -> info);
    }
}