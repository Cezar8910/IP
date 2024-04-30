#include <stdio.h>

int main()
{
    // Intensidade 0 - 255
    int i, j, k, l; // Linhas e colunas da matriz
    int n;          // Tamnho da matriz
    int temp;       // Auxiliar
    char direcao;   // Direita(d) ou esquerda(e)
    int soma = 0;
    int menu;
    int determinante = 0; // Determinante da matriz

    scanf("%d", &n);
    int matrizFiltro[n][n];
    int matrizResultante[n][n];
    int matriz[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("----Menu----\n\n");
    printf("Selecione a opcao desejada: \n");
    printf("1 - Girar a matriz\n");
    printf("2 - Aplicar filtro\n");
    printf("3 - Aplicar degrade\n");
    printf("4 - Gerar preto e branco\n");
    scanf("%d", &menu);

    if (menu == 1)
    {
        printf("Selecione a direcao (e) ou (d): \n");
        scanf(" %c", &direcao);
        if (direcao == 'e')
        {
            for (i = 0; i < n; i++) // Girar para a esquerda -90
            {
                for (j = 0; j < n; j++) // Anda 2 linhas e 2 colunas
                {
                    temp = matriz[i][j];
                    matriz[i][j] = matriz[i + 2][j];
                    matriz[i + 2][j] = temp;
                }
            }
        }
        else if (direcao == 'd') // Girar para a direita +90
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    temp = matriz[i][j];
                    matriz[i][j] = matriz[i - 2][j];
                    matriz[i - 2][j] = temp;
                }
            }
        }
    }

    if (menu == 2) // 2 opcao - Aplicar um filtro e imprimir a matriz resultante da multiplicacao
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &matrizFiltro[n][n]);
                temp = matrizFiltro[i][j];
                matriz[i][0] * matrizFiltro[0][j]; // Multiplicar toda a linha por cada coluna da matriz filtro e imprimir as respectivas linhas
                temp = matrizResultante[i][j];
            }
        }
    }

    if (menu == 3) // 3 opcao ordem crescrecente - bubble sort
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - 1; j++) // Ordenar os elementos das linhas em ordem crescente
            {
                for (k = 0; k < n - j - 1; k++)
                {
                    if (matriz[i][k] > matriz[i][k + 1]) // Mesma logica de trabalhar com um vetor
                    {
                        temp = matriz[i][k];
                        matriz[i][k] = matriz[i][k + 1];
                        matriz[i][k + 1] = temp;
                    }
                }
            }
        }
    }

    if (menu == 4) // 4 opcao  //Multiplicar os elementos para achar o determinante
    {

        determinante += matriz[0][0] * matriz[1][1] * matriz[2][2];
        determinante += matriz[0][1] * matriz[1][2] * matriz[2][0];
        determinante += matriz[0][2] * matriz[1][0] * matriz[2][1];
        determinante -= matriz[0][1] * matriz[1][0] * matriz[2][2];
        determinante -= matriz[0][0] * matriz[1][2] * matriz[2][0];
        determinante -= matriz[0][2] * matriz[1][1] * matriz[2][0];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matriz[i][j] > determinante)
                {
                    matriz[i][j] = 1;
                }
                else
                {
                    matriz[i][j] = 0;
                }
            }
        }
    }

    // Printar a matriz
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}