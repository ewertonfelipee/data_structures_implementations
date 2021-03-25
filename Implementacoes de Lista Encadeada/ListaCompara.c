#include <stdio.h>
#include <stdlib.h>

int lst_igual(Lista* l1, Lista* l2){

    ListaNO* p1; // ponteiro auxiliar 
    ListaNO* p2; // ponteiro auxiliar
    for(p1 = l1 -> prim, p2 = l2 -> prim; 
    p1 != NULL && p2 != NULL; 
    p1 = p1 -> prox, p2 = p2 -> prox){

        if(p1 -> info != p2 -> info){

            return 0;
        }
    }
    return p1 == p2;
}