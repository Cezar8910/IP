// Conceito de funcao eh muito basico, por isso aqui vamos abordar funcoes com ponteiros
#include <stdio.h>
#include <stdlib.h>

void imprimir(int *num)
{
    printf("%d\n", *num);
    *num = 22; // Alterando o conteudo apontado pelo ponteiro
}

int main()
{
    int idade = 19;
    imprimir(&idade); // Mandando o endereco da variavel idade que vai ser o ponteiro num, ou seja, o ponteiro num vai estar apontando para o endereco de memoria de idade, permitindo assim que o conteudo dela possa ser alterado pelo ponteiro
    printf("Valor de idade na main: %d", idade);
    return 0;
}