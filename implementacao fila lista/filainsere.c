#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

void fila_insere(Fila* f, float v){

    ListaNo* n = (ListaNo*)malloc(sizeof(ListaNO));
    n->info = v; // armazena informacao
    n->prox = NULL; // novo noh passa a ser o ultimo
    if(f->fim!=NULL){ // verifica se a lista nao estava vazia

        f->fim->prox = n;
    }
    else{ // fila estava vazia
        f->ini = n;
    }
    f->fim = n; // fila aponta para o novo elemento
}