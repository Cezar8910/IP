#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5] = {1, 2, 3, 4, 5};
    int *p;

    p = vet; // Nao preciso do "&" pois se trata de um vetor

    // Letra a
    printf("Endereco guardado em vet = %p\nEndereco guardado em p = %p\n", vet, p);
    printf("\n");
    // Letra b
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando p com [] = %d\n", p[i]);
    }
    printf("\n");
    // Letra c
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando p com * = %d\n", *p);
        p++; // Incremetando o valor no ponteiro para permitir que ele acesse o proximo...
    }
    printf("\n");
    // Letra d
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando [] = %d\n", vet[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando * = %d\n", *(vet + i));
    }

    return 0;
}