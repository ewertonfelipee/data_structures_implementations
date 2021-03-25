#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

void fila_libera(Fila* f){

    ListaNo* q = f->ini;
    while(q!=NULL){

        ListaNo* t = q -> prox;
        free(q);
    }
    free(t);
}