#include <stdio.h>
#include <string.h>
#define TAM 70
typedef struct
{
    char nome[100];
    float product;
} Funcionario;

int main()
{

    Funcionario func[TAM];

    float soma = 0, media;
    int i;

    for (i = 0; i < TAM; i++)
    {
        printf("Digite o nome do %o funcionario: ", i + 1);
        scanf(" %99[^\n]", func[i].nome);
        printf("Digite sua produtividade: ");
        scanf("%f", &(func[i].product));

        soma += func[i].product;
    }

    media = soma / TAM;

    for (i = 0; i < TAM; i++)
    {
        if (func[i].product < media)
        {
            printf("O %do funcionarioa [%s] tem produtividade abaixo da media\n", i + 1, func[i].nome);
        }
    }

    return 0;
}