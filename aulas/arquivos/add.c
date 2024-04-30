#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *arq;

    char caminho[100] = "C:\\Users\\cezar\\Onedrive\\Imagens\\escrita.txt";

    arq = fopen(caminho, "a");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    fprintf(arq, "Adicionando!\n");

    fclose(arq);

    return 0;
}