#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;

    char caminho[100] = "C:\\Users\\cezar\\Onedrive\\Imagens\\escrita.txt";

    arq = fopen(caminho, "r");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    fseek(arq, 0, SEEK_END);
    printf("Tamanho do arquivo: %ld bytes\n", ftell(arq));

    fclose(arq);

    return 0;
}