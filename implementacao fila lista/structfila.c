#include <stdio.h>
#include <stdlib.h>
#include "tadfila.h"

struct listano{
    float info;
    ListaNo* prox;
}
struct fila{

    ListaNo* ini;
    ListaNo* fim;
}