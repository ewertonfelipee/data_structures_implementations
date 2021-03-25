#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

flaot fila_retira(Fila* f){

    ListaNo* t = f -> ini;
    float v = t -> info;
    f->ini = t->prox;
    if(f->ini == NULL){ // verifica se a lista ficou vazia

        f->fim = NULL;
    }
    free(t);
    return v;
}