#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"


Fila* fila_cria(void){

    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}