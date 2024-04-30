#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *p;
    p = (int *)calloc(1, sizeof(int)); // Usando o calloc, atribuindo a quantidade de valores que eu quero, e a quantidade de espaco necessaria para ele

    *p = 5;

    printf("%d\n", *p);

    printf("--------------------\n");

    int *d;
    d = (int *)malloc(sizeof(int)); // Usando o malloc, atribuindo a quantidade de bits necessarias para o tipo que eu defini

    *d = 5;

    printf("%d\n", *d);
    free(p); // Liberando o espaco deixado pela alocacao do calloc
    free(d); // Liberando o espaco deixado pela alocacao do malloc

    return 0;
}

/*Diferencas entre malloc e calloc
malloc -> Eh mais rapido que o calloc porque o malloc reserva um espaco de memoria que vai ser atribuido aquele ponteiro, porem ele nao apaga o anterior, gerando um lixo de memoria.

calloc -> Tem a mesma funcao de alocacao dinamica do malloc, porem ao reservar o endereco de memoria para o ponteiro ele automaticamente apaga o anterior, entao voce nao sofre com lixo de memoria, mas torna o programa mais lento porque ele vai fazer esse processo de exclusao de endereco.

free -> Eh o "apagador" do malloc, a funcao desempenhada pelo free eh o que o calloc acaba fazendo em conjunto, entao usamos o free no malloc justamente para nao acumular tanto lixo de memoria e acabar prejudicando a performace do programa.
*/

// Usando ponteiros com structs e funcoes

typedef struct
{
    int red, green, blue;
} Ponto;

Ponto *preecheLinha(int *tam)
{
    Ponto pTemp, *tLinha, *linha = NULL;
    printf("Digite as cores deste ponto RGB: ");
    scanf("%d %d %d", &pTemp.red, &pTemp.green, &pTemp.blue);
    while (pTemp.red != 255)
    {
        tLinha = linha;
        linha = (Ponto *)realloc(linha, (*tam + 1) * sizeof(Ponto));

        if (linha == NULL)
        {
            printf("Falha na alocacao inicial\n");
            free(tLinha);
            exit(1);
        }
        linha[(*tam)++] = pTemp;
        printf("Digite as cores deste ponto RGB: ");
        scanf("%d %d %d", &pTemp.red, &pTemp.green, &pTemp.blue);
    }
    return linha;
}

int main()
{
    Ponto *linha;
    int tam = 0;
    linha = preecheLinha(&tam);
    return 0;
}

// Ponteiros duplos

int **criaMatriz(int linhas, int colunas)
{
    int **mat, i, j;
    mat = (int **)malloc(linhas * sizeof(int *));
    if (mat == NULL)
    {
        free(mat);
        exit(1);
    }
    for (i = 0; i < linhas; i++)
    {
        mat[i] = (int *)malloc(linhas * sizeof(int));
        if (mat[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(mat[j]);
                free(mat);
            }
            exit(1);
        }
        for (j = 0; j < colunas; j++)
        {
            mat[i][j] = i + j;
        }
    }
    return mat;
}

void liberaMatriz(int **mat, int linhas)
{
    int i;
    for (i = 0; i < linhas; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

int main2()
{
    int **matriz, lin = 3, col = 4;
    matriz = criaMatriz(lin, col);
    liberaMatriz(matriz, lin);

    return 0;
}
