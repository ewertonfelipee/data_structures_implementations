#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNO;

struct lista{

    ListaNO* prim;
};

struct listano{

    int info;
    ListaNO* prox;
};
