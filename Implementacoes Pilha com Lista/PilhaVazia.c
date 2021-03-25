#include <stdio.h>
#include <stdlib.h>
#include "TADStackList.h"

int pilha_vazia(Pilha* p){

    return(p -> prim == NULL);
}