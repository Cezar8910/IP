#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int quantidade;
    float preco;
} Produto;

int main()
{
    int i, j, flag = 0;
    char operacao[10];

    int tamanho_estoque;
    scanf("%d", &tamanho_estoque);

    Produto estoque[tamanho_estoque][tamanho_estoque];

    for (i = 0; i < tamanho_estoque; i++)
    {
        for (j = 0; j < tamanho_estoque; j++)
        {
            estoque[i][j].quantidade = 0;
            estoque[i][j].preco = 0.0;
            strcpy(estoque[i][j].nome, "");
        }
    }

    char nome[100]; // Ajuste do tamanho máximo do nome

    while (flag == 0)
    {
        scanf(" %s", operacao);

        if (strcmp(operacao, "CREATE") == 0)
        {
            scanf("%d %d", &i, &j);
            if (estoque[i][j].nome[0] == '\0')
            {
                scanf(" %s %d %f", nome, &estoque[i][j].quantidade, &estoque[i][j].preco);
                strcpy(estoque[i][j].nome, nome);
                printf("Produto adicionado no estoque!\n");
            }
            else
            {
                printf("ERRO: espaco ja ocupado\n");
            }
        }
        else if (strcmp(operacao, "READ") == 0)
        {
            scanf(" %s", nome);
            int produtoEncontrado = 0;
            for (i = 0; i < tamanho_estoque; i++)
            {
                for (j = 0; j < tamanho_estoque; j++)
                {
                    if (strcmp(estoque[i][j].nome, nome) == 0)
                    {
                        printf("LINHA: %d COLUNA: %d QTD: %d PRECO: %.2f\n", i, j, estoque[i][j].quantidade, estoque[i][j].preco);
                        produtoEncontrado = 1;
                    }
                }
            }
            if (!produtoEncontrado)
            {
                printf("Produto nao encontrado!\n");
            }
        }
        else if (strcmp(operacao, "UPDATE") == 0)
        {
            scanf(" %s", nome);
            int produtoEncontrado = 0;
            for (i = 0; i < tamanho_estoque; i++)
            {
                for (j = 0; j < tamanho_estoque; j++)
                {
                    if (strcmp(estoque[i][j].nome, nome) == 0)
                    {
                        scanf("%d %f", &estoque[i][j].quantidade, &estoque[i][j].preco);
                        printf("Produto atualizado!\n");
                        produtoEncontrado = 1;
                    }
                }
            }
            if (!produtoEncontrado)
            {
                printf("Produto nao encontrado!\n");
            }
        }
        else if (strcmp(operacao, "DELETE") == 0)
        {
            scanf(" %s", nome);
            int produtoEncontrado = 0;
            for (i = 0; i < tamanho_estoque; i++)
            {
                for (j = 0; j < tamanho_estoque; j++)
                {
                    if (strcmp(estoque[i][j].nome, nome) == 0)
                    {
                        strcpy(estoque[i][j].nome, "");
                        estoque[i][j].quantidade = 0;
                        estoque[i][j].preco = 0.0;
                        printf("Produto removido!\n");
                        produtoEncontrado = 1;
                    }
                }
            }
            if (!produtoEncontrado)
            {
                printf("Produto nao encontrado!\n");
            }
        }
        else if (strcmp(operacao, "PRINT") == 0)
        {
            for (i = 0; i < tamanho_estoque; i++)
            {
                for (j = 0; j < tamanho_estoque; j++)
                {
                    if (estoque[i][j].nome[0] != '\0')
                    {
                        printf("LINHA: %d COLUNA: %d NOME: %s QTD: %d PRECO: %.2f\n", i, j, estoque[i][j].nome, estoque[i][j].quantidade, estoque[i][j].preco);
                    }
                }
            }
        }
        else if (strcmp(operacao, "EXIT") == 0)
        {
            printf("Saindo...\n");
            flag = 1;
        }
    }

    return 0;
}
