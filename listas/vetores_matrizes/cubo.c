#include <stdio.h>

int main()
{
    char mov[1][2];
    int cuboAtual[3][3][6], cuboProximo[3][3][6], i, j, k, jAlternado, iAlternado;

    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                cuboAtual[i][j][k] = k;
                cuboProximo[i][j][k] = k;
            }

    while (scanf(" %c %c", &mov[0][0], &mov[0][1]) != EOF)
    {
        // esquerda_direita UR, UL, DR, DL
        if ((mov[0][0] == 'U' || mov[0][0] == 'D') && (mov[0][1] == 'L' || mov[0][1] == 'R'))
        {
            if (mov[0][0] == 'U')
            {
                i = 0;
                k = 1;
            }
            else
            {
                i = 2;
                k = 5;
            }
            if ((mov[0][0] == 'U' && mov[0][1] == 'R') || (mov[0][0] == 'D' && mov[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[0][2 - p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][2 - p][k];
                    cuboProximo[p][2][k] = cuboAtual[2][2 - p][k];
                }
            }
            if ((mov[0][0] == 'U' && mov[0][1] == 'R') || (mov[0][0] == 'D' && mov[0][1] == 'R'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cuboProximo[i][j][0] = cuboAtual[i][j][3];
                    cuboProximo[i][j][3] = cuboAtual[i][j][4];
                    cuboProximo[i][j][4] = cuboAtual[i][j][2];
                    cuboProximo[i][j][2] = cuboAtual[i][j][0];
                }
            }
            if ((mov[0][0] == 'U' && mov[0][1] == 'L') || (mov[0][0] == 'D' && mov[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[2][p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][p][k];
                    cuboProximo[p][2][k] = cuboAtual[0][p][k];
                }
            }
            if ((mov[0][0] == 'U' && mov[0][1] == 'L') || (mov[0][0] == 'D' && mov[0][1] == 'L'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cuboProximo[i][j][0] = cuboAtual[i][j][2];
                    cuboProximo[i][j][2] = cuboAtual[i][j][4];
                    cuboProximo[i][j][4] = cuboAtual[i][j][3];
                    cuboProximo[i][j][3] = cuboAtual[i][j][0];
                }
            }
        }
        if ((mov[0][0] == 'L' || mov[0][0] == 'R') && (mov[0][1] == 'L' || mov[0][1] == 'R'))
        {
            if (mov[0][0] == 'L')
            {
                j = 0;
                jAlternado = 2;
                k = 2;
                iAlternado = 2;
            }
            else
            {
                j = 2;
                jAlternado = 0;
                k = 3;
                iAlternado = 2;
            }
            if ((mov[0][0] == 'R' && mov[0][1] == 'R') || (mov[0][0] == 'L' && mov[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[0][2 - p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][2 - p][k];
                    cuboProximo[p][2][k] = cuboAtual[2][2 - p][k];
                }
            }
            if ((mov[0][0] == 'R' && mov[0][1] == 'L') || (mov[0][0] == 'L' && mov[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[2][p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][p][k];
                    cuboProximo[p][2][k] = cuboAtual[0][p][k];
                }
            }
            if ((mov[0][0] == 'R' && mov[0][1] == 'R') || (mov[0][0] == 'L' && mov[0][1] == 'R'))
            {
                for (int i = 0; i < 3; i++)
                {
                    cuboProximo[i][j][1] = cuboAtual[2 - i][jAlternado][0];
                    cuboProximo[i][j][4] = cuboAtual[i][j][1];
                    cuboProximo[i][j][5] = cuboAtual[i][j][4];
                    cuboProximo[i][jAlternado][0] = cuboAtual[2 - i][j][5];
                }
            }
            if ((mov[0][0] == 'R' && mov[0][1] == 'L') || (mov[0][0] == 'L' && mov[0][1] == 'L'))
            {
                for (int i = 0; i < 3; i++)
                {
                    cuboProximo[i][j][5] = cuboAtual[2 - i][jAlternado][0];
                    cuboProximo[i][jAlternado][0] = cuboAtual[2 - i][j][1];
                    cuboProximo[i][j][1] = cuboAtual[i][j][4];
                    cuboProximo[i][j][4] = cuboAtual[i][j][5];
                }
            }
        }
        if ((mov[0][0] == 'F' || mov[0][0] == 'B') && (mov[0][1] == 'L' || mov[0][1] == 'R'))
        {
            if (mov[0][0] == 'F')
            {
                i = 2;
                k = 4;
                iAlternado = 0;
            }
            else
            {
                i = 0;
                k = 0;
                iAlternado = 2;
            }
            if ((mov[0][0] == 'F' && mov[0][1] == 'L') || (mov[0][0] == 'B' && mov[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[0][2 - p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][2 - p][k];
                    cuboProximo[p][2][k] = cuboAtual[2][2 - p][k];
                }
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        cuboAtual[i][j][k] = cuboProximo[i][j][k];
            }
            if ((mov[0][0] == 'F' && mov[0][1] == 'R') || (mov[0][0] == 'B' && mov[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cuboProximo[p][0][k] = cuboAtual[2][p][k];
                    cuboProximo[p][1][k] = cuboAtual[1][p][k];
                    cuboProximo[p][2][k] = cuboAtual[0][p][k];
                }
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        cuboAtual[i][j][k] = cuboProximo[i][j][k];
            }
            if ((mov[0][0] == 'F' && mov[0][1] == 'R') || (mov[0][0] == 'B' && mov[0][1] == 'R'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cuboProximo[i][j][1] = cuboAtual[2 - j][i][2];
                    cuboProximo[j][i][2] = cuboAtual[iAlternado][j][5];
                    cuboProximo[j][iAlternado][3] = cuboAtual[i][j][1];
                    cuboProximo[iAlternado][j][5] = cuboAtual[2 - j][iAlternado][3];
                }
            }
            if ((mov[0][0] == 'F' && mov[0][1] == 'L') || (mov[0][0] == 'B' && mov[0][1] == 'L'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cuboProximo[j][i][2] = cuboAtual[i][2 - j][1];
                    cuboProximo[iAlternado][j][5] = cuboAtual[j][i][2];
                    cuboProximo[i][j][1] = cuboAtual[j][iAlternado][3];
                    cuboProximo[j][iAlternado][3] = cuboAtual[iAlternado][2 - j][5];
                }
            }
        }
        for (int k = 0; k < 6; k++)
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    cuboAtual[i][j][k] = cuboProximo[i][j][k];
    }

    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                printf("%d", cuboProximo[i][j][k]);
                if (j == 2)
                    printf("\n");
                if (i == 2 && j == 2)
                    printf("\n");
            }
    return 0;
}
