#include <stdio.h>
#include <stdlib.h>
#include "ARV.h"

//No da arvore binaria
struct arvno{

    char info;
    ArvNo* esq;
    ArvNo* dir;
};
//Ponteiro para o no raiz
struct arv{

    ArvNo* raiz;
};

//Funcao responsavel por criar um novo no da arvore, recebendo como
//parametros a informacao e as duas subarvores(que podem ser NULL)
//associadas:
ArvNo* arv_criano(char c, ArvNo* esq, ArvNo* dir){

    ArvNo* p = (ArvNo*)malloc(sizeof(ArvNo)); //aloca dinamicamente
    //o espaco para armazenar o novo no da arvore
    p->info = c;
    p->esq = esq;
    p->dir = dir;
    return p;
}

//cria a representacao do tipo abstrato, recebendo como paramentro
// o no raiz:
Arv* arv_cria(ArvNo* r){

    Arv* a = (Arv*)malloc(sizeof(Arv));
    a->raiz = r;
    return a;
}

//imprime o conteudo de cada no e as estrutura da arvore, 
//usando a notacao textual ">" ou "<"
static void imprime(ArvNo* r){

    printf("<");
    if(r != NULL){

        printf("%c", r->info); // mostra a informacao
        imprime(r->esq); // imprime a subarvore a esquerda
        imprime(r->dir); // imprime a subarvore a direita
    }
    printf(">");
}

//funcao externa do tipo abstrato eh responsavel apenas por invocar
//a funcao recursiva a partir do no raiz.
void arv_imprime(Arv* a){

    imprime(a->raiz); //imprime recursivamente a partir da raiz
}

//funcao recursiva para liberar os nos
static void libera(ArvNo* r){

    if(r != NULL){
        libera(r->esq); //libera a sae
        libera(r->dir); //libera a sad
        free(r); //libera o no raiz
    }
}

//funcao externa para liberar a estrutura da arvore
void arv_libera(Arv* a){

    libera(a->raiz); //libera a hierarquia de nos
    free(a); // libera a raiz
}

//percorre verificando a existencia de determinado simbolo em um de seus nos
static int pertence(ArvNo* r, char c){

    if(r == NULL){
        return 0; // arvore vazia: nao encontrou
    }
    else{
        return  c == r->info || 
                pertence(r -> esq, c) || 
                pertence(r -> dir, c);
    }
}
int arv_pertece(Arv* a, char c){

    return pertence(a->raiz, c);
}

//funcao com valor de retorno o ponteiro do no que contem a informacao
//ao inves de um booleano
static ArvNo* busca(ArvNo* r, char c){

    if(r == NULL){
        return NULL; // arvore vazia: nao encontrou
    }
    else if(c == r->info){
        return r;
    }
    else{
        ArvNo* p = busca(r->esq, c);// busca na sae
        if(p != NULL){
            return p;//encontrou na sae
        }
        else{
            return busca(r->dir, c);//busca na sad
        }
    }
}
ArvNo* arv_busca(Arv* a, char c){
    return busca(a->raiz, c);
}

//calcula o max entre dois numeros
static int max2(int a, int b){

    return (a > b) ? a  : b;
}

//calcula a altura
static int altura(ArvNo* r){

    if(r == NULL)
        return -1;
    else
        return 1 + max2(altura(r->esq), altura(r->dir));
}
int arv_altura(Arv* a){

    return altura(a->raiz);
}