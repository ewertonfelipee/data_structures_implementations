#include <stdio.h>
#include <stdlib.h>

Lista* lst_cria(void){

    Lista* l = (Lista*)malloc(sizeof(Lista));
    l -> prim = NULL;
    return l;
}