#include <stdio.h>
#include <stdlib.h>

void lst_imprime(Lista* l){

    for (ListaNO* p = l -> prim; p != NULL; p = p -> prox)
    {
        printf("info = %d\n", p -> info);
    }
    
}