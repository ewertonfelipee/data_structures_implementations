#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int n, int* v, int e)
{
    int ini = 0;
    int fim = n - 1;
    int meio;

    while(ini <= fim){
        meio = (ini + fim) / 2;
        if(e < v[meio]){ fim = meio - 1;}
        else if(e > v[meio]){ ini = meio + 1;}
        else return meio;
    }
    return -1;
}

int main(void)
{
    printf("digite a quantidade do array: ");
    
    int n, e;scanf("%d", &n);

    int v[n];

    printf("Digite os valores do array: ");

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int tam = sizeof(v) / sizeof(int);

    printf("Digite o valor a ser procurado: ");

    scanf("%d", &e);

    printf("O valor procurado esta na posicao: %d\n", busca_binaria(tam, v, e));
    return 0;
}