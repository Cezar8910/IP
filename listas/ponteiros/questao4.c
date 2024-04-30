#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Faça um programa que aloque dinamicamente um vetor de strings str, receba
de entrada várias strings enquanto existir entrada no buffer e guarde-as nesse vetor
utilizando ponteiros auxiliares (ponteiro temporário na hora de dar realloc).*/

// Primeiro preciso fazer a alocacao com o malloc e depois partir para a realocacao
int main()
{
    char **str = NULL; // Ponteiro duplo nulo, comecamos como NULL porque vamos realocar
    char entrada[50];
    int i = 0, j = 0;

    while (scanf(" %49[^\n]", entrada) != EOF)
    {
        // Vamos alocar primeiro
        char *novaStr = (char *)malloc(strlen(entrada) + 1); // +1 porque estamos considerando o caractere final \0

        // Precisamos fazer a verificacao de sempre quando alocamos ou realocamos os vetores ou o que quer que seja
        if (novaStr == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(novaStr); // Limpei
            exit(1);       // Cai fora
        }
        strcpy(novaStr, entrada);

        // Agora vamos realocar a memoria
        char **ptr_aux = (char **)realloc(str, (i + 1) * sizeof(char *));

        // Verificacao
        if (ptr_aux == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(ptr_aux); // Limpei
            exit(1);       // Cai fora
        }

        str = ptr_aux; // Atribuindo o meu ponteiro duplo principal ao ponteiro auxiliar
        str[i] = novaStr;
        i++;
    }
    printf("\n");
    for (j = 0; j < i; j++)
    {
        if (str == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(str); // Limpei
            exit(1);   // Cai fora
        }
        else
        {
            printf("%s\n", str[j]);
            free(str[j]);
        }
    }
    free(str);

    return 0;
}
