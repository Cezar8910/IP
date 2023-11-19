#include <stdio.h>

int main()
{

    /*     "." REPRESENTA ESPAÇO VAZIO

           "&" REPRESENTA JANELA QUE CUSTA 200 REAIS CADA

           "-" REPRESENTA CORDÕES DE SUSTENTAÇÃO QUE CUSTA 50 REAIS CADA

           "#" REPRESENTA A BASE DA CONSTRUÇÃO QUE CUSTA 100 REAIS CADA */

    int andares = 0; //>=1 e <=99

    int valorBase = 0;
    int valorJanela = 0;
    int valorCordoes = 0;

    int entrou = 0;
    int i, j;

    scanf("%d", &andares);

    for (i = 0; i < andares; i++)
    {
        for (j = 0; j < andares - i - 1; j++) // Espaco vazio pra esquerda
        {
            printf(".");
        }

        for (j = 0; j < 2 * i + 1; j++) // Janelas + cordoes
        {
            if (j % 2 == 0)
            {
                printf("&");
                valorJanela++;
            }
            else
            {
                printf("-");
                valorCordoes++;
            }
        }
        for (j = 0; j < andares - i - 1; j++) // Espaco vazio pra direita
        {
            printf(".");
        }

        printf("\n");
    }
    for (i = 0; i < andares * 2 - 1; i++) // Base da piramide
    {
        printf("#");
        valorBase++;
    }
    printf("\n");

    int valorBaseFinal = valorBase * 100;
    int valorJanelaFinal = valorJanela * 200;
    int valorCordoesFinal = valorCordoes * 50;
    printf("O valor total foi: %d", (valorBaseFinal + valorJanelaFinal + valorCordoesFinal));
    return 0;
}