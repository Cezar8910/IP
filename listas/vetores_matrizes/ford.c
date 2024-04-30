#include <stdio.h>

int main()
{

    int i, j;
    int k, l;             // Cordenadas da saida
    int n;                // Tamanho da matriz
    int numeroPassos = 0; // Numero de passos
    int temp;

    scanf("%d %d %d", &n, &k, &l);

    int mapa[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                for (l = 0; l < n; l++)
                {
                    mapa[i][j] = mapa[k][l];
                    if (mapa[k + 1][l] - mapa[k][l] == 1)
                    {
                        numeroPassos++;
                        temp = mapa[k][l];
                        mapa[k][l] = mapa[k + 1][l];
                        mapa[k + 1][l] = temp;
                       
                    }
                    else if (mapa[k][l + 1] - mapa[k][l] == 1)
                    {
                        numeroPassos++;
                        temp = mapa[k][l];
                        mapa[k][l] = mapa[k][l + 1];
                        mapa[k][l + 1] = temp;
                     
                    }
                }
            }
        }
    }

    printf("Numero de passos do maior caminho: %d", numeroPassos);

    return 0;
}