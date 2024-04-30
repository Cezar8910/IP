#include <stdio.h>

int main()
{
    int n, m; // n = altura, m = largura
    int i, j, k;
    int semHash = 0, semHash2 = 0; // flags

    scanf("%d %d", &n, &m);
    char matriz[n][m];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (matriz[i][j] == '.')
            {
                if (i - 1 >= 0)
                {
                    if (matriz[i - 1][j] == 'o')
                    {
                        matriz[i][j] = 'o';
                    }
                }
            }
            if (matriz[i][j] == 'o')
            {
                if (i + 1 < n && matriz[i + 1][j] == '.')
                {
                    matriz[i + 1][j] = 'o';
                }
                else if (i + 1 < n && matriz[i + 1][j] == '#')
                {
                    for (k = 1; !semHash; k++) //Tem hashtag
                    {
                        if (j + k >= m || matriz[i + 1][j + k] != '#')
                        {
                            semHash = 1;
                        }
                    }
                    for (int l = 1; l < k; l++)
                    {
                        if (j + l < m)
                        {
                            matriz[i][j + l] = 'o';
                        }
                    }
                    semHash = 0;
                    for (k = 1; !semHash2; k++)
                    {
                        if (j - k < 0 || matriz[i + 1][j - k] != '#')
                        {
                            semHash2 = 1;
                        }
                    }
                    for (int l = 1; l < k; l++)
                    {
                        if (j - l >= 0)
                        {
                            matriz[i][j - l] = 'o';
                        }
                    }
                    semHash2 = 0;
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
