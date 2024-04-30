#include <stdio.h>
#include <string.h>

typedef union
{
    char letra;
    int inteiro;
    float real;
} Hibrido;

int main()
{
    Hibrido h;

    h.letra = 'C';
    printf("h como real: %f\n", h.real);

    return 0;
}