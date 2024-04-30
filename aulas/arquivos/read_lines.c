#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;
    char linha[100];

    char caminho[100] = "C:\\Users\\cezar\\Onedrive\\Imagens\\escrita.txt";

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    while (!feof(arq))
    {
        fscanf(arq, "%99[^\n]\n", linha);
        printf("Linha - %s\n", linha);
    }

    fclose(arq);

    return 0;
}