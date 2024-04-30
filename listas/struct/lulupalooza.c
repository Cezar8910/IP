#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    float valor;
    int quantidade;
} Produto;

int main()
{
    int i, j;
    int qtd_produtos;
    char data[6]; // Mudado para 6 para armazenar "02/02"
    float valor_saida = 0;

    scanf("%d", &qtd_produtos);

    Produto produtos[qtd_produtos];

    for (i = 0; i < qtd_produtos; i++)
    {
        scanf(" %s %f %d", produtos[i].nome, &produtos[i].valor, &produtos[i].quantidade);
    }

    // Entrada data e valor
    char tudo[29];
    char tudo_entrada[7];
    scanf(" %28[^\n]", tudo); // ler a entrada apos os 28 caracteres digitados, tem que ser como string por causa do xx/xx
    scanf(" %s", data);       // lendo a data com os caracteres que faltam

    int valor_entrada;
    scanf(" %6[^\n]", tudo_entrada); // Mesma logica aqui
    scanf("%d", &valor_entrada);     // Pegando o valor em forma de numero porque nao tem nenhum caractere especial

    float resultado = 0;

    // Ordenando os nomes
    for (i = 0; i < qtd_produtos - 1; i++)
    {
        for (j = 0; j < qtd_produtos - 1 - i; j++)
        {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0)
            {
                Produto aux = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = aux;
            }
        }
    }

    // Saida personalizada
    printf("=============\n");
    printf("NF - 0123\n");
    printf("Data - %s\n", data);
    printf("=============\n");

    // Printando os produtos
    for (i = 0; i < qtd_produtos; i++)
    {
        valor_saida = produtos[i].quantidade * produtos[i].valor;
        printf("%dx %s - R$%.2f\n", produtos[i].quantidade, produtos[i].nome, valor_saida);
        resultado += valor_saida;
    }

    printf("\n");
    float troco = valor_entrada - resultado;

    // Printando o final da compra
    printf("Valor Total - R$%.2f\n", resultado);
    printf("Pago - R$%d\n", valor_entrada);
    printf("Troco - R$%.2f\n", troco);
    printf("=============");

    return 0;
}
