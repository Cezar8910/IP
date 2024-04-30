#include <stdio.h>
#include <string.h>

#define A 'A'
#define B 'B'
#define C 'C'

int main()
{
    char string[1000000];
    char substring[1000000];

    scanf("%s", string);
    int flag = 1;

    int tamanhoIncial = strlen(string);
    int i, j = 0;
    while (flag)
    {
        int achouABC = 0;
        for (i = 0; i < tamanhoIncial; i++)
        {
            // Verifica se as tres letras consecutivas sao 'A', 'B' e 'C'
            if (string[i] == A && string[i + 1] == B && string[i + 2] == C)
            {

                i += 2;
                achouABC = 1;
            }
            else
            {
                substring[j++] = string[i];
            }
        }
        substring[j] = '\0'; // Defino que a substing acabou

        if (!achouABC)
        {
            flag = 0;
        }

        strcpy(string, substring);
        tamanhoIncial = strlen(string);
        j = 0;
    }
    // Printando a string
    if (strlen(substring) == 0)
    {
        printf("string vazia");
    }
    else
    {
        printf("%s", substring);
    }

    return 0;
}
