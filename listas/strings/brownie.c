#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int frases; // Número de frases
    scanf("%d", &frases);

    char letras[frases][100];

    for (int nFrases = 0; nFrases < frases; nFrases++)
    {
        char string[100];
        scanf(" %s", string);

        int tamnhoString = strlen(string);
        int tamanho = sqrt(tamnhoString);
        int ehVogal = 0;

        // Encontrar a primeira vogal na substring
        while (string[ehVogal] != '\0' && !(string[ehVogal] == 'A' || string[ehVogal] == 'E' || string[ehVogal] == 'I' || string[ehVogal] == 'O' || string[ehVogal] == 'U'))
        {
            ehVogal++;
        }

        int k = 0;
        char stringFinal[tamanho];

        for (int tam = ehVogal; tam < ehVogal + tamanho && !0; tam++)
        {
            stringFinal[k] = string[tam];
            k++;
        }

        for (int nLetras = 0; nLetras < tamanho; nLetras++)
        {
            letras[nFrases][nLetras] = stringFinal[nLetras];
        }

        letras[nFrases][tamanho] = '\0';
    }

    // Ordenar as substrings
    for (int nFrases = 0; nFrases < frases - 1; nFrases++)
    {
        for (int nLetras = 0; nLetras < frases - nFrases - 1; nLetras++)
        {
            if (strcmp(letras[nLetras], letras[nLetras + 1]) > 0)
            {
                // Troca as letras se estiverem fora de ordem
                char temp[100];
                strcpy(temp, letras[nLetras]);
                strcpy(letras[nLetras], letras[nLetras + 1]);
                strcpy(letras[nLetras + 1], temp);
            }
        }
    }

    int final = 0;
    for (int i = 0; i < frases; i++)
    {
        final += strlen(letras[i]);
    }

    char resultado[final + 1];
    resultado[0] = '\0';

    for (int i = 0; i < frases; i++)
    {
        strcat(resultado, letras[i]);
    }

    resultado[final] = '\0';

    printf("%s", resultado);

    return 0;
}
