#include <stdio.h>

int main()
{
    // d - direita, e - esquerda, f - frente, x - final

    char direcoes;
    int valorDirecoes;
    int entrou = 0;
    int count = 19; // Distancia inicial

    int i, j; // Ponto incial(10km do lado esquerdo do mapa)

    while (entrou == 0)
    {
        scanf(" %c", &direcoes);

        if (direcoes != 'x')
        {
            switch (direcoes)
            {
            case 'e':
                scanf("%d", &valorDirecoes);
                printf(".");
                count -= (2 * (valorDirecoes));

                for (i = 0; i <= count; i++)
                {
                    printf(" ");
                }
                for (j = 0; j < valorDirecoes; j++)
                {
                    printf("<-");
                }
                printf("\n");

                break;
            case 'd':
                scanf("%d", &valorDirecoes);

                printf(".");

                for (i = 0; i <= count; i++)
                {
                    printf(" ");
                }
                for (j = 0; j < valorDirecoes; j++)
                {
                    printf("->");
                    count += 2;
                }
                printf("\n");

                break;
            case 'f':
                scanf("%d", &valorDirecoes);

                for (j = 0; j < valorDirecoes; j++)
                {
                    printf(".");
                    for (i = 0; i <= count; i++)
                    {
                        printf(" ");
                    }
                    printf("|\n");
                }

                break;
            }
        }
        else
        {
            entrou = 1;
            printf(".");
            for (i = 0; i <= count; i++)
            {
                printf(" ");
            }

            printf("x");
        }
    }
    return 0;
}