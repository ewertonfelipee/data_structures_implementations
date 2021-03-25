#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[])
{
	Lista* lista;
	
	lista = criar_lista();
	
	if(vazia(lista))
		printf("Lista vazia!\n");
	else
		printf("Lista NAO vazia\n");
	
	lista = inserir_lista(lista, 10);
	lista = inserir_lista(lista, 20);
	lista = inserir_lista(lista, 5);
	
	imprimir_lista(lista);
	
	if(vazia(lista))
		printf("Lista vazia!\n");
	else
		printf("Lista NAO vazia\n");
	
	int elemento = 100;
	if(buscar(lista, elemento) == NULL)
		printf("Nao encontrou o elemento %d\n", elemento);
	else
		printf("Encontrou o elemento %d\n", elemento);
	
	return 0;
}