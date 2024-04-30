#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int palavrasCheck;
    int somaPalavras = 0;
    char palavras[30];
    int achouPalavra = 0;
    int flag = 1;

    scanf(" %s", palavras);
    scanf("%d", &palavrasCheck);

    char recebePalavra[palavrasCheck][30];

    while (flag)
    {
        for (i = 0; i < palavrasCheck; i++)
        {
            scanf(" %s", recebePalavra[i]);
        }

        for (i = 0; i < palavrasCheck; i++)
        {
            achouPalavra = 1;

            // Verifica manualmente se cada letra da palavra está presente em palavras
            for (j = 0; j < strlen(recebePalavra[i]); j++)
            {
                int letraPresente = 0;

                for (int k = 0; k < strlen(palavras); k++)
                {
                    if (recebePalavra[i][j] == palavras[k])
                    {
                        letraPresente = 1;
                        flag = 0;
                    }
                }

                if (!letraPresente)
                {
                    achouPalavra = 0;
                    flag = 0;
                }
            }

            somaPalavras += achouPalavra;
        }
    }

    printf("E possivel formar %d palavras com esse conjunto\n", somaPalavras);

    return 0;
}
