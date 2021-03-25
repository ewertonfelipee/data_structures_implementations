#include <stdio.h>
#include <stdlib.h>

void lst_insert(Lista* l, int v){

    ListaNO* novo = (ListaNO*)malloc(sizeof(ListaNO));
    novo -> info = v;
    novo -> prox = l -> prim;
    l -> prim = novo; 
}