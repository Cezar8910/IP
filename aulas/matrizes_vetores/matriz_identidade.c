#include <stdio.h>
#define L 3
#define C 3
int main()
{
    int mat[L][C];
    int i, j, ehIdentidade = 1;
    for (i = 0; i < L && ehIdentidade; i++)
        for (j = 0; j < C && ehIdentidade; j++)
        {
            printf("Mat[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
            ehIdentidade = (i == j && mat[i][i] == 1) || (i != j && mat[i][j] == 0);
        }
    printf(ehIdentidade ? "Sim\n" : "Nao\n");
    return 0;
}