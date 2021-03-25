#include <stdio.h>
#include <stdlib.h>

int lst_pertence(Lista* l, int v){

    for (ListaNO* p = l -> prim; p != NULL; p = p -> prox)
    {
        if(p -> info == v){
            return 1;
        }
    }
    return 0; // nao encontrou o elemento
}