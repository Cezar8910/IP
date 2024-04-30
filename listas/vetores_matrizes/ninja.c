#include <stdio.h>

int main()
{

    int i, j;
    int linhas, colunas; // Colunas e linhas sempre par
    char cortes;         //'H'(horizontal) ou 'V'(vertical)
    int temporario;

    scanf(" %c %d %d", &cortes, &linhas, &colunas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (cortes == 'H')
    {
        for (i = linhas / 2; i < linhas; i++)
        {
            for (j = 0; j < colunas / 2; j++)
            {
                temporario = matriz[i][j];
                matriz[i][j] = matriz[i][colunas - j - 1];
                matriz[i][colunas - j - 1] = temporario;
            }
        }
    }

    if (cortes == 'V')
    {
        for (i = 0; i < linhas / 2; i++)
        {
            for (j = colunas / 2; j < colunas; j++)
            {
                temporario = matriz[i][j];
                matriz[i][j] = matriz[linhas - i - 1][j];
                matriz[linhas - i - 1][j] = temporario;
            }
        }
    }

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%02d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}