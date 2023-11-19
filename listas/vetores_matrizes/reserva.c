#include <stdio.h>
/*               0             B
               2 1 3         L U R
                 4             F
                 5             D       */
int main()
{
    char movimento[1][2];
    int cubopresente[3][3][6], cubofuturo[3][3][6], i, j, k, jalternado, ialternado;
    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                cubopresente[i][j][k] = k;
                cubofuturo[i][j][k] = k;
            }
    while (scanf(" %c %c", &movimento[0][0], &movimento[0][1]) != EOF)
    {
        // esquerda_direita UR, UL, DR, DL
        if ((movimento[0][0] == 'U' || movimento[0][0] == 'D') && (movimento[0][1] == 'L' || movimento[0][1] == 'R'))
        {
            if (movimento[0][0] == 'U')
            {
                i = 0;
                k = 1;
            }
            else
            {
                i = 2;
                k = 5;
            }
            if ((movimento[0][0] == 'U' && movimento[0][1] == 'R') || (movimento[0][0] == 'D' && movimento[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[0][2 - p][k];
                    cubofuturo[p][1][k] = cubopresente[1][2 - p][k];
                    cubofuturo[p][2][k] = cubopresente[2][2 - p][k];
                }
            }
            if ((movimento[0][0] == 'U' && movimento[0][1] == 'R') || (movimento[0][0] == 'D' && movimento[0][1] == 'R'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cubofuturo[i][j][0] = cubopresente[i][j][3];
                    cubofuturo[i][j][3] = cubopresente[i][j][4];
                    cubofuturo[i][j][4] = cubopresente[i][j][2];
                    cubofuturo[i][j][2] = cubopresente[i][j][0];
                }
            }
            if ((movimento[0][0] == 'U' && movimento[0][1] == 'L') || (movimento[0][0] == 'D' && movimento[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[2][p][k];
                    cubofuturo[p][1][k] = cubopresente[1][p][k];
                    cubofuturo[p][2][k] = cubopresente[0][p][k];
                }
            }
            if ((movimento[0][0] == 'U' && movimento[0][1] == 'L') || (movimento[0][0] == 'D' && movimento[0][1] == 'L'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cubofuturo[i][j][0] = cubopresente[i][j][2];
                    cubofuturo[i][j][2] = cubopresente[i][j][4];
                    cubofuturo[i][j][4] = cubopresente[i][j][3];
                    cubofuturo[i][j][3] = cubopresente[i][j][0];
                }
            }
        }
        if ((movimento[0][0] == 'L' || movimento[0][0] == 'R') && (movimento[0][1] == 'L' || movimento[0][1] == 'R'))
        {
            if (movimento[0][0] == 'L')
            {
                j = 0;
                jalternado = 2;
                k = 2;
                ialternado = 2;
            }
            else
            {
                j = 2;
                jalternado = 0;
                k = 3;
                ialternado = 2;
            }
            if ((movimento[0][0] == 'R' && movimento[0][1] == 'R') || (movimento[0][0] == 'L' && movimento[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[0][2 - p][k];
                    cubofuturo[p][1][k] = cubopresente[1][2 - p][k];
                    cubofuturo[p][2][k] = cubopresente[2][2 - p][k];
                }
            }
            if ((movimento[0][0] == 'R' && movimento[0][1] == 'L') || (movimento[0][0] == 'L' && movimento[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[2][p][k];
                    cubofuturo[p][1][k] = cubopresente[1][p][k];
                    cubofuturo[p][2][k] = cubopresente[0][p][k];
                }
            }
            if ((movimento[0][0] == 'R' && movimento[0][1] == 'R') || (movimento[0][0] == 'L' && movimento[0][1] == 'R'))
            {
                for (int i = 0; i < 3; i++)
                {
                    cubofuturo[i][j][1] = cubopresente[2 - i][jalternado][0];
                    cubofuturo[i][j][4] = cubopresente[i][j][1];
                    cubofuturo[i][j][5] = cubopresente[i][j][4];
                    cubofuturo[i][jalternado][0] = cubopresente[2 - i][j][5];
                }
            }
            if ((movimento[0][0] == 'R' && movimento[0][1] == 'L') || (movimento[0][0] == 'L' && movimento[0][1] == 'L'))
            {
                for (int i = 0; i < 3; i++)
                {
                    cubofuturo[i][j][5] = cubopresente[2 - i][jalternado][0];
                    cubofuturo[i][jalternado][0] = cubopresente[2 - i][j][1];
                    cubofuturo[i][j][1] = cubopresente[i][j][4];
                    cubofuturo[i][j][4] = cubopresente[i][j][5];
                }
            }
        }
        if ((movimento[0][0] == 'F' || movimento[0][0] == 'B') && (movimento[0][1] == 'L' || movimento[0][1] == 'R'))
        {
            if (movimento[0][0] == 'F')
            {
                i = 2;
                k = 4;
                ialternado = 0;
            }
            else
            {
                i = 0;
                k = 0;
                ialternado = 2;
            }
            if ((movimento[0][0] == 'F' && movimento[0][1] == 'L') || (movimento[0][0] == 'B' && movimento[0][1] == 'R'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[0][2 - p][k];
                    cubofuturo[p][1][k] = cubopresente[1][2 - p][k];
                    cubofuturo[p][2][k] = cubopresente[2][2 - p][k];
                }
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        cubopresente[i][j][k] = cubofuturo[i][j][k];
            }
            if ((movimento[0][0] == 'F' && movimento[0][1] == 'R') || (movimento[0][0] == 'B' && movimento[0][1] == 'L'))
            {
                for (int p = 0; p < 3; p++)
                {
                    cubofuturo[p][0][k] = cubopresente[2][p][k];
                    cubofuturo[p][1][k] = cubopresente[1][p][k];
                    cubofuturo[p][2][k] = cubopresente[0][p][k];
                }
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        cubopresente[i][j][k] = cubofuturo[i][j][k];
            }
            if ((movimento[0][0] == 'F' && movimento[0][1] == 'R') || (movimento[0][0] == 'B' && movimento[0][1] == 'R'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cubofuturo[i][j][1] = cubopresente[2 - j][i][2];
                    cubofuturo[j][i][2] = cubopresente[ialternado][j][5];
                    cubofuturo[j][ialternado][3] = cubopresente[i][j][1];
                    cubofuturo[ialternado][j][5] = cubopresente[2 - j][ialternado][3];
                }
            }
            if ((movimento[0][0] == 'F' && movimento[0][1] == 'L') || (movimento[0][0] == 'B' && movimento[0][1] == 'L'))
            {
                for (int j = 0; j < 3; j++)
                {
                    cubofuturo[j][i][2] = cubopresente[i][2 - j][1];
                    cubofuturo[ialternado][j][5] = cubopresente[j][i][2];
                    cubofuturo[i][j][1] = cubopresente[j][ialternado][3];
                    cubofuturo[j][ialternado][3] = cubopresente[ialternado][2 - j][5];
                }
            }
        }
        for (int k = 0; k < 6; k++)
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    cubopresente[i][j][k] = cubofuturo[i][j][k];
    }

    for (int k = 0; k < 6; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                printf("%d", cubofuturo[i][j][k]);
                if (j == 2)
                    printf("\n");
                if (i == 2 && j == 2)
                    printf("\n");
            }
    return 0;
}
