#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

void fila_imprime(Fila*){

    for(ListaNo* q = f->ini; q != NULL; q=q->prox){

        printf("%f\n", q->info);
    }
}