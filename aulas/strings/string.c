#include <stdio.h>
#include <string.h>

int main()
{

    char origem[20] = "Sport = Pipoca";
    char fim[20];

    strcpy(fim, origem); // Funcao para copia o valor da string na segunda posição do argumento para uma variável string na primeira posição.

    printf("Origem: %s\n", origem);
    printf("Fim: %s\n", fim);

    char destino[50] = "Arroz com";
    char string[] = " feijao";

    strcat(destino, string); // Funcao para concatenar

    printf("Depois da concatenacao: %s\n", destino);

    char str1[30] = "Banana";

    char srtr2[30] = "Uva";

    int resultado = strcmp(str1, srtr2);

    if (resultado == 0)
    {
        printf("As strings sao iguais");
    }

    return 0;
}
