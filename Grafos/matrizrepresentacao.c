#include <stdio.h>
#include <stdlib.h>

int mat[5][5] = 
{
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,0,1,1},
    {0,0,1,0,1},
    {0,0,1,1,0}
};
void grau_vertice(int grau)
{
    int n = 5;
    for (int i = 0; i < n; i++){
        grau = 0;
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 1){
                grau = grau + 1;
            }
        }
        printf("o vertice %d tem grau: %d\n", i, grau);
    }
}

int tem_ligacao(int x, int y)
{
    return mat[x][y];
}

int main(void)
{
    int x, y, grau;
    scanf("%d %d", &x, &y);
    if(tem_ligacao(x,y) == 1){
        printf("tem ligacao de a para c\n");
    }
    else{
        printf("nao tem ligacao de a para c\n");
    }

    grau_vertice(grau);
    return 0;
}