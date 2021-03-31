#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define pai(i) (((i)-1)/2) //indice de no pai
#define esq(i) (2*(i)+1) // indice do filho a esquerda
#define dir(i) (2*(i)+2) // indide do filho a direita

static void swap (float* v, int i, int j){

    float tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

static void downto (int n, float* v, int i){

    int c = esq(i);
    while (c < n){
        int c2 = dir(i);
        if(c2 < n && v[c2] > v[c]){
            c =c2;
        }
        if(v[c] < v[i]){
            break;
        }
        swap(v,i,c);
        i = c;
        c = esq(i);
    }
}

void hsort(int n, float* v){

    // rearranja os elementos no vetor como em um heap
    for(int i = n/2-1; i>=0; --i){
        downto(n, v, i);
    }
    // remove os elementos, armazenando-os no final do vetor
    int k = n;
    for(int i = 0; i<n; ++i){
        swap(v, 0, --k);
        downto(k,v,0);
    }
}

#define N 100

int main (void){

    int i;
    float v[N];
    srand(0);
    for (i = 0; i < N; ++i)
    {
        v[i] = (float)((double)rand()/RAND_MAX);
    }
    hsort(N, v);
    for (i = 0; i < N; ++i)
    {
        assert(v[i] > v[i-1]);
    }
    printf("OK\n");

    return 0;
    
}