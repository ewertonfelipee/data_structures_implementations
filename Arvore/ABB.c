#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

//No da arvore binaria
struct arvno{

    int info;
    ArvNo* esq;
    ArvNo* dir;
};

static void imprime (ArvNo* r){

    if (r != NULL)
    {
        imprime(r->esq);
        printf("%d\n", r->info);
        imprime(r->dir);
    }
    
}
void abb_imprime(Arv* a){

    return imprime(a->raiz);
}

static ArvNo* busca (ArvNo* r, int v){

    if (r == NULL) return NULL;
    else if (r->info > v) return busca(r->esq, v);
    else if (r->info < v) return busca(r->dir, v);
    else return v;
    
}
ArvNo* abb_busca (Arv* a, int v){

    return busca(a->raiz, v);
}

Arv* abb_cria (void){
    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

static ArvNo* insere (ArvNo* r, int v){

    if (r == NULL)
    {
        r = (ArvNo*)malloc(sizeof(ArvNo));
        r->info = v;
        r->esq=r->dir=NULL;
    }
    else if(v < r -> info){
        r->esq = insere(r->dir, v);
    }
    else{
        r->dir = insere(r->esq, v);
    }
    return r;
    
}

void abb_insere (Arv* a, int v){

    a->raiz = insere(a->raiz, v);
}

static ArvNo* retira (ArvNo* r, int v){

    if(r == NULL) return NULL;
    else if(r->info > v) r->esq=retira(r->esq, v);
    else if(r->info < v) r->dir=retira(r->dir, v);
    else { // achou o elemento
        
        // elemento sem filhos: 1 situacao
        if(r->esq==NULL && r->dir==NULL){

            free(r);
            r = NULL; // raiz atualizada passando a ser null
        }
        // 2 situacao
        // so tem um filho a direita
        else if(r->esq ==NULL){
            ArvNo* t = r; // coloca a raiz na variavel auxiliar
            r = r->dir; // passa a ser a nova raiz
            free(t); // libera a variavel auxliar
        }
        // so tem filho a esquerda
        else if(r->dir == NULL){
            ArvNo* t = r;
            r = r->esq;
            free(t);
        }
        // 3 situacao
        // tem os dois filhos
        else{
            ArvNo* f = r->esq;
            while(f->dir != NULL){
                f = f->dir;
            }
            r->info = f->info; // troca as informacoes
            f->info = v;
            r->esq = retira(r->esq, v);
        }
    }
    return r;
}
void abb_retira (Arv* a, int v){

    a->raiz = retira(a->raiz, v);
}