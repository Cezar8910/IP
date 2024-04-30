#include <stdio.h>

int main()
{
    int i, j;
    int x, y;             // Coordenadas de saída
    int n;                // Tamanho da matriz
    int numeroPassos = 0; // Número de passos
    int temp;

    scanf("%d %d %d", &n, &x, &y);

    int mapa[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }

    // Inicializar numeroPassos
    numeroPassos = 0;

    // Loop para percorrer o caminho do início ao destino
    while (x != n - 1 || y != n - 1)
    {
        // Se há um caminho para a direita, mova-se para a direita
        if (y < n - 1 && mapa[x][y + 1] - mapa[x][y] == 1)
        {
            numeroPassos++;
            temp = mapa[x][y];
            mapa[x][y] = mapa[x][y + 1];
            mapa[x][y + 1] = temp;
            y++;
        }
        else if (x < n - 1 && mapa[x + 1][y] - mapa[x][y] == 1)
        {
            // Se não, se há um caminho para baixo, mova-se para baixo
            numeroPassos++;
            temp = mapa[x][y];
            mapa[x][y] = mapa[x + 1][y];
            mapa[x + 1][y] = temp;
            x++;
        }
        else
        {
            // Se não houver caminho possível, pare
            break;
        }
    }

    printf("Numero de passos do maior caminho: %d", numeroPassos);

    return 0;
}
