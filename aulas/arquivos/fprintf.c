#include <stdio.h>

int main()
{

    FILE *arq;

    char caminho[100] = "C:\\Users\\cezar\\Onedrive\\Imagens\\escrita.txt", "w";

    fopen(caminho, "w");

    fprintf(caminho, "Olaaaaa!\n");

    fclose(arq);

    return 0;
}