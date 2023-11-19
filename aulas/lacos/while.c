#include <stdio.h>
#include <math.h>
int main()
{
    // Do while
    /*  int num;
     do
     {
         printf("Digite um numero: ");
         scanf("%d", &num);
         if(num < 4){
             printf("Você errou, digite novamente!\n");
         }

     } while (num < 0); */

    int opcao;
    do
    {
        printf("Menu\n\n");
        printf("1 - Resolver equacao do 1 grau\n");
        printf("2 - Resolver equacao do 2 grau\n");
        printf("3- Sair do sitema.\n\n\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        float a, b, c, delta;
        char continua;

        // O sistema irá fazer algo
        switch (opcao)
        {
        case 1: // Equação do 1° grau
            do
            {
                printf("Digite os valores de a e b \n");
                scanf("%f %f", &a, &b);
                if (a != 0)
                {
                    printf("Raiz = %.2f\n", -b / a);
                }
                else
                {
                    printf("Não é uma equacao do 1 grau\n");
                }
                printf("Deseja continuar?\n");
                scanf(" %c", &continua);

            } while (continua == 'S' || continua == 's');

            break;
        case 2: // Equação do 2° grau
            do
            {
                printf("Digite os valores de a, b e c \n");
                scanf("%f %f %f", &a, &b, &c);
                delta = b * b - (4 * a * c);
                if (delta < 0)
                {
                    printf("Não tem raízes reais\n");
                }
                else if (delta == 0)
                {
                    printf("Possui apenas uma raiz\n Raiz: %.2f\n", -b / (2 * a));
                }
                else
                {
                    printf("Raiz 1 = %.2f\n", (-b - sqrt(delta)) / 2 * a);
                    printf("Raiz 2 = %.2f\n", (-b + sqrt(delta)) / 2 * a);
                }
            } while (continua == 'S' || continua == 's');
            break;
        case 3:
            break;
        default:
            printf("Opcao inexistente!\n");
            break;
        }

    } while (opcao != 3);

    printf("Adeus!");

    return 0;
}