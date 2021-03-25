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
Lista* lst_cria(void){

    Lista* l = (Lista*)malloc(sizeof(Lista));
    l -> prim = NULL;
    return l;
}
void lst_insert(Lista* l, int v){

    ListaNO* novo = (ListaNO*)malloc(sizeof(ListaNO));
    novo -> info = v;
    novo -> prox = l -> prim;
    l -> prim = novo; 
}
void lst_imprime(Lista* l){
    // ListaNO* p eh uma variavel auxiliar
    for (ListaNO* p = l -> prim; p != NULL; p = p -> prox)
    {
        printf("info = %d\n", p -> info);
    }
    
}
int lst_vazia(Lista* l){

    return(l -> prim == NULL);
}
int lst_pertence(Lista* l, int v){

    for (ListaNO* p = l -> prim; p != NULL; p = p -> prox)
    {
        if(p -> info == v){
            return 1;
        }
    }
    return 0; // nao encontrou o elemento
}
int main(void){

    Lista* l = lst_cria();

    if(lst_vazia(l))
        printf("lista vazia\n");
    else
        printf("lista nao vazia");

    lst_insert(l, 45);
    lst_insert(l, 60);
    lst_insert(l, 99);

    lst_imprime(l);

    if(lst_vazia(l))
        printf("lista vazia\n");
    else
        printf("lista nao vazia\n");

    int v = 99;
    if(lst_pertence(l, v) == NULL)
        printf("nao achou o valor\n");
    else
        printf("achou o valor\n");

    return 0;

    lst_imprime(l);
    return 0;
}