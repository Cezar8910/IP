#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct
{
    char nome_brinquedo[30];
    int divertimento;
    int aborrecimento;
    int qtd_vezes; // Quantidade de vezes que o brinquedo aparece
    int soma_qtd_vezes;
} Brinquedo;

int main()
{
    int i, j;
    int diversao_total = 0;
    Brinquedo brinquedo[TAM];

    // Inicializando qtd_vezes para todos os brinquedos
    for (i = 0; i < TAM; i++)
    {
        brinquedo[i].qtd_vezes = 0;
        brinquedo[i].soma_qtd_vezes = 0;
    }

    for (i = 0; i < TAM; i++)
    {
        scanf(" %29[^\n] %d %d", brinquedo[i].nome_brinquedo, &brinquedo[i].divertimento, &brinquedo[i].aborrecimento);
    }

    // Encontrando a combinação que proporciona maior diversao
    for (i = 0; i < TAM; i++)
    {
        // Ainda nao encontramos o brinquedo e nem a melhor divesao(por isso -1)
        int melhor_brinquedo = -1;
        int melhor_diversao = -1;

        // Verificando o melhor brinquedo para a rodada atual
        for (j = 0; j < TAM; j++)
        {
            if (brinquedo[j].divertimento > 0 && brinquedo[j].aborrecimento >= 0 && brinquedo[j].qtd_vezes < 3)
            {
                // Funcao dada na questao
                int diversao_atual = brinquedo[j].divertimento - (brinquedo[j].qtd_vezes * brinquedo[j].qtd_vezes * brinquedo[j].aborrecimento);

                if (melhor_brinquedo == -1 || diversao_atual > melhor_diversao)
                {
                    melhor_diversao = diversao_atual;
                    melhor_brinquedo = j;
                }
            }
        }

        // Escolhendo o melhor brinquedo para a rodada
        // Caso seja diferente de menos 1 ehporque achamos o melhor brinquedo da rodada
        if (melhor_brinquedo != -1)
        {
            brinquedo[melhor_brinquedo].qtd_vezes++;
            diversao_total += melhor_diversao;
            brinquedo[melhor_brinquedo].soma_qtd_vezes++;
        }
    }

    // Ordenando os brinquedos com base no número de vezes que foram escolhidos(caso teste 2)
    for (i = 0; i < TAM - 1; i++)
    {
        for (j = 0; j < TAM - i - 1; j++)
        {
            if (brinquedo[j].soma_qtd_vezes < brinquedo[j + 1].soma_qtd_vezes)
            {
                Brinquedo temp = brinquedo[j];
                brinquedo[j] = brinquedo[j + 1];
                brinquedo[j + 1] = temp;
            }
        }
    }

    // Printando a saida
    printf("a maior diversao foi: %d\n", diversao_total);
    printf("indo nos brinquedos: ");
    for (i = 0; i < TAM; i++)
    {
        if (brinquedo[i].qtd_vezes >= 1)
        {
            // Ternario para que se a quantidade de vezes for maior que 1 adiciona "es" na string caso nao seja, ou seja, so pode ser 1 entao vai ser "vez" no singular
            printf("%s %d vez%s", brinquedo[i].nome_brinquedo, brinquedo[i].soma_qtd_vezes, brinquedo[i].qtd_vezes > 1 ? "es" : "");
            // O brinquedo nao pode ser o ultimo e o proximo tem que ter uma quantidade de vezes maior ou igual a 1 e isso significa que ele exista, pois caso seja menor que 1 sera 0 o que indica que ele nao foi escolhido, e com isso adiciona a virgula ou nao.
            if (i < TAM - 1 && brinquedo[i + 1].qtd_vezes >= 1)
            {
                printf(", ");
            }
        }
    }
    printf(".\n");

    return 0;
}
