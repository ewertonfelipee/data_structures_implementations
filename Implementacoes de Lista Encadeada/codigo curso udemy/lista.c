#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista
{
	int info;
	struct lista* prox;
};

Lista* criar_lista()
{
	return NULL;
}

Lista* inserir_lista(Lista* l, int i)
{
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void imprimir_lista(Lista* l)
{
	Lista* p;

	for(p = l; p != NULL; p = p->prox)
		printf("%d\n", p->info);
}

int vazia(Lista* l)
{
	if(l == NULL)
		return 1;
	return 0;
}

Lista* buscar(Lista* l, int v)
{
	Lista* p;
	for(p = l; p != NULL; p = p->prox)
	{
		if(p->info == v)
			return p;
	}
	return NULL;
}