#include <stdio.h>
#include "arvore.h"

int main(int argc, char *argv[])
{
	Arv* a1 = criar('m', criar_vazia(), criar_vazia());
	Arv* a2 = criar('a', criar_vazia(), a1);
	return 0;
}