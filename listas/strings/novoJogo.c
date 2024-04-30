#include <stdio.h>
#include <string.h>

int main()
{

    int i, j;
    int dimensao;
    scanf("%d", &dimensao);

    char piso_da_sala[dimensao][dimensao];

    char x = 'x'; // Ponto instavel
    char o = 'o'; // Ponto estável

    int qtd_jogadores;
    char sequencia[100];

    int tamanho;

    for (i = 0; i < dimensao; i++)
    {

        for (j = 0; j < dimensao; j++)
        {
            scanf(" %c", &piso_da_sala[i][j]);
        }
    }
    scanf("%d", &qtd_jogadores);

    scanf("%d", &tamanho);
    scanf(" %s", sequencia);

    return 0;
}