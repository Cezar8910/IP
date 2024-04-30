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
    int menos_diversao = 0;
    int diversao_total = 0;
    int soma_qtd_vezes = 0;
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

    // Encontrando a combinação que proporciona maior diversão
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            // Condições para ser válido
            if (brinquedo[j].divertimento > 0 && brinquedo[j].aborrecimento >= 0)
            {
                // Verificando o maior divertimento dentre os 3 brinquedos
                if (brinquedo[j].divertimento >= brinquedo[0].divertimento && brinquedo[j].divertimento >= brinquedo[1].divertimento && brinquedo[j].divertimento >= brinquedo[2].divertimento)
                {
                    printf("Entrou no %d\n", j + 1);
                    if (i >= TAM - 2)
                    {
                        brinquedo[j].qtd_vezes++; // repeticao
                    }
                    // Funcao dada na questao
                    menos_diversao = (brinquedo[j].qtd_vezes * brinquedo[j].qtd_vezes) * brinquedo[j].aborrecimento;
                    // Calculando a diversao total
                    diversao_total += brinquedo[j].divertimento - menos_diversao;
                    // Somo a quantidade de vezes que passou pelo brinquedo
                    brinquedo[j].soma_qtd_vezes++;
                }
            }
        }
    }

    // Ordenando os brinquedos com base no número de vezes que foram escolhidos(caso teste 2)
    for (i = 0; i < TAM - 1; i++)
    {
        for (j = 0; j < TAM - i - 1; j++)
        {
            if (brinquedo[j].soma_qtd_vezes > brinquedo[i].soma_qtd_vezes)
            {
                Brinquedo temp = brinquedo[i];
                brinquedo[i] = brinquedo[j];
                brinquedo[j] = temp;
            }
        }
    }

    // Printando a saída
    printf("a maior diversao foi: %d\n", diversao_total);
    printf("indo nos brinquedos: ");
    for (i = 0; i < TAM; i++)
    {
        if (brinquedo[i].qtd_vezes >= 1)
        {
            printf("%s %d vez%s", brinquedo[i].nome_brinquedo, brinquedo[i].soma_qtd_vezes, brinquedo[i].qtd_vezes > 1 ? "es" : "");
            if (i < TAM - 1 && brinquedo[i + 1].qtd_vezes >= 1)
            {
                printf(", ");
            }
        }
    }
    printf(".\n");

    return 0;
}
