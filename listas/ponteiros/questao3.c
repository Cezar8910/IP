#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50];     // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int count;
    int i = -1;

    // Fiz a modificacao no scanf apenas para poder pegar strings com espacos(o que torna o codigo mais usual)
    scanf(" %49[^\n]", str);

    // Preciso pegar os valores(tamanho) da string principal ate ela acabar
    // Sabemos que *(ponteiro + indice) = vet[indice]
    for (i = 0; *(ptr_str + i) != '\0'; i++)
        ;

    // Preciso agora pegar tudo da string principal e passar para a string invertida, com os elementos invertidos
    // Utilizo essa condicao porque estabeleco que vai rodar ate i ser maior que 0, ja que estou decrementando no *(ptr_str + --i), ou seja, se i for maior que 0 entao ainda tem elementos na string
    while (i > 0)
    {
        *(ptr_inv++) = *(ptr_str + --i);
    }
    *ptr_inv = '\0';

    // Printando a saida
    printf("O inverso da string: %s\n\n", str_inv);

    return 0;
}