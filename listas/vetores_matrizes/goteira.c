#include <stdio.h>

int main()
{
    int n, m; // n = altura, m = largura
    int i, j;
    char tipo;
    int entrou = 0; // flag

    scanf("%d %d", &n, &m);
    char matriz[n][m];

    while (scanf(" %c", &tipo) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf(" %c", &tipo);
                matriz[i][j] = tipo;

                switch (tipo)
                {
                    if (matriz[i][j] = '.' || matriz[i][j] = 'o')
                    {
                        matriz[i][j] = matriz[i][j];
                    }
                case '.':
                    if (i - 1 >= 0)
                    {
                        if (matriz[i - 1][j] = 'o')
                        {
                            matriz[i - 1][j] = 'o';
                        }
                    }
                    break;
                case 'o':
                    if (matriz[i + 1][j] == '.')
                    {
                        matriz[i + 1][j] = 'o';
                    }
                    break;
                case '#':
                    if (matriz[i + 1][j] == 'o')
                    {
                        matriz[i + 1][j] = '.';
                    }
                    break;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
