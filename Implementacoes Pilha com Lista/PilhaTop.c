#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

float pilha_topo(Pilha* p){

    if(pilha_vazia(p)){
        printf("pilha vazia\n");
        exit(1);
    }
    return(p -> prim -> info);
}