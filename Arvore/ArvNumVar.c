// Arvore com numero variavel de filhos

#include <stdio.h>
#include <stdlib.h>
#include "ArvNumVar.h"

struct arvnno{

    char info;
    ArvnNo* prim; // ponteiro para eventual primeiro filho
    ArvnNo* prox; // ponteiro para eventual irmao
};

struct arvn{

    ArvnNo* raiz;
};

/*

definicao: dado o noh de uma arvore, essa arvore eh composta
por um noh raiz e zero ou mais subarvores

*/

ArvnNo* arvn_criano(char c){

    ArvnNo *a = (ArvnNo*)malloc(sizeof(ArvnNo));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvn_insere (ArvnNo* a, ArvnNo* sa){

    sa->prox = a->prim;
    a->prim = sa;
}
// cria a representacao do tipo abstrato, recebendo como paramentro o noh raiz
Arvn* arvn_cria (ArvnNo* r){

    Arvn* a = (Arvn*)malloc(sizeof(Arvn));
    a->raiz = r;
    return a;
}

static void imprime (ArvnNo* r){

    printf(" <%c", r->info);
    for (ArvnNo* p=r->prim; p!=NULL; p=p->prox){
        imprime(p);
    }
    printf(">");
}
void arnv_imprime(Arvn* a){

    if (a->raiz != NULL)
    {
        imprime(a->raiz);
    }
    
}

static ArvnNo* busca (ArvnNo* r, char c){

    if(r->info==c){
        return r;
    }
    else{
        for(ArvnNo* p=r->prim; p!=NULL; p=p->prox){
            ArvnNo* q= busca(p, c);
            if(q!=NULL){
                return q;
            }
        }
        return NULL;
    }
}

ArvnNo* arvn_busca(Arvn* a, char c){

    if(a->raiz==NULL){
        return NULL;
    }
    else{
        return busca(a->raiz, c);
    }
}

static void libera(ArvnNo* r){
    ArvnNo* p = r->prim;
    while (p!=NULL){
        ArvnNo* t = p->prox;
        libera(p);
        p = t;
    }
    free(r);
}

void arvn_libera (Arvn* a){

    if(a->raiz != NULL){

        libera(a->raiz);
    }
    free(a);
}

static int altura(ArvnNo* r){

    int hmax = -1; // -1 para tratar caso com zero filhos
    for(ArvnNo* p=r->prim; p!=NULL; p=p->prox){
        int h = altura(p);
        if(h > hmax){
            hmax = h;
        }
    }
    return hmax + 1;
}

int arvn_altura(Arvn* a){

    if(a->raiz ==NULL){
        return -1;
    }
    else{
        return altura(a->raiz);
    }
}