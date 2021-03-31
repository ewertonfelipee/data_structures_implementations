#include <stdio.h>
#include "TADStackArray.h"

int main(){

    Pilha* p;

    p = pilha_cria();
    pilha_push(p, 10); 
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_push(p, 40);
    pilha_push(p, 50);
    pilha_pop(p);
    printf("topo: %.2f\n", pilha_topo(p));
    pilha_pop(p);
    printf("topo: %.2f\n", pilha_topo(p));
}