#include <stdio.h>

int main()
{
    int i, j;
    int palavrasCheck;
    int somaPalavras = 0;
    char palavras[30];
    int achouPalavra = 0;

    scanf("%s", palavras);

    scanf("%d", &palavrasCheck);

    char recebePalavra[palavrasCheck][30];

    for (i = 0; i < palavrasCheck; i++)
    {
        scanf(" %s", recebePalavra[i]);

        achouPalavra = 0; // Reinicializa a variável para cada palavra recebida

        for (j = 0; recebePalavra[i][j] != '\0'; j++)
        {
            int k = 0;
            while (palavras[k] != '\0')
            {
                if (palavras[k] == recebePalavra[i][j])
                {
                    achouPalavra = 1;

                    // Remove todas as ocorrências da letra da palavra em 'palavras'
                    int l = k;
                    while (palavras[l] != '\0')
                    {
                        palavras[l] = palavras[l + 1];
                        l++;
                    }

                    // Após remover a letra, reinicia a verificação da mesma posição
                    k = 0;
                }
                else
                {
                    k++;
                }
            }
        }

        if (achouPalavra)
        {
            somaPalavras++;
        }
    }

    printf("E possivel formar %d palavras com esse conjunto\n", somaPalavras);

    return 0;
}
