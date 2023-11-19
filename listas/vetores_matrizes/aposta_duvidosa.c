#include <stdio.h>

int main()
{
    int i, j, m;

    int k = 0; // Quantidade de matrizes quadradas
    int n = 0; // Tamanho da matriz

    scanf("%d", &k);

    for (m = 0; m < k; m++) // Quantidade de matrizes
    {
        scanf("%d", &n);

        int matriz[n][n];
        int somaLinhas[n], somaColunas[n];
        int somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;

        // Inicializar somas
        for (i = 0; i < n; i++)
        {
            somaLinhas[i] = 0;
            somaColunas[i] = 0;
        }

        // Preencher a matriz e calcular as somas
        for (i = 0; i < n; i++) // linhas
        {
            for (j = 0; j < n; j++) // colunas
            {
                scanf("%d", &matriz[i][j]);
                somaLinhas[i] += matriz[i][j];
                somaColunas[j] += matriz[i][j];

                if (i == j)
                {
                    somaDiagonalPrincipal += matriz[i][j];
                }
                if (i + j == n - 1)
                {
                    somaDiagonalSecundaria += matriz[i][j];
                }
            }
        }

        // Verificar se todas as somas são iguais
        int somaEsperada = somaLinhas[0];
        int ehQuadradoMagico = 1;

        for (i = 0; i < n; i++)
        {
            if (somaLinhas[i] != somaEsperada || somaColunas[i] != somaEsperada)
            {
                ehQuadradoMagico = 0;
                break;
            }
        }

        if (somaDiagonalPrincipal != somaEsperada || somaDiagonalSecundaria != somaEsperada)
        {
            ehQuadradoMagico = 0;
        }

        if (ehQuadradoMagico)
        {
            printf("Eh quadrado magico!!!\n");
        }
        else
        {
            printf("Nao eh!!!\n");
        }
    }

    return 0;
}
