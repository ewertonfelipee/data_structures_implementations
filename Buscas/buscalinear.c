#include <stdio.h>
#include <stdlib.h>

int busca_linear(int n, int* v, int e)
{
    for (int i = 0; i < n; i++){
        if (v[i] == e) return i;
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

    printf("%d\n", busca_linear(tam, v, e));
    return 0;
}