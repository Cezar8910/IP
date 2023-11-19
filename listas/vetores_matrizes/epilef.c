#include <stdio.h>

int main()
{
    // Restrições 1 <= N <= 10
    int n; // Tamanho do tabuleiro
    int i, j;
    scanf("%d", &n);

    char movimentos; // Vetor

    char matriz[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }

    while (scanf(" %c", &movimentos) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {

                if (matriz[i][j] == 'x')

                    switch (movimentos)
                    {
                    case 'R': // Direita (right)

                        if (j > 0)
                        {
                            matriz[i][0] = 'x';
                            matriz[i][j] = 'C';
                        }

                        break;
                    case 'L': // Esquerda (left)

                        if (j < n - 1)
                        {
                            matriz[i][n - 1] = 'x';
                            matriz[i][j] = 'C';
                        }

                        break;
                    case 'U': // Para cima (up)

                        if (i < n - 1)
                        {
                            matriz[n - 1][j] = 'x';
                            matriz[i][j] = 'C';
                        }

                        break;
                    case 'D': // Para baixo (down)

                        if (i > 0)
                        {
                            matriz[0][j] = 'x';
                            matriz[i][j] = 'C';
                        }

                        break;
                    }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
