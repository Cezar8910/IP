#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 15;
    int *ponteiro;

    ponteiro = &var;

    printf("Conteudo de var = %d\n", var);
    printf("Endereco de var = %p\n", &var);
    printf("Conteudo apontado pelo ponteiro = %d\n", *ponteiro);
    printf("Endereco apontado pelo ponteiro = %p\n", ponteiro);
    printf("Endereco do proprio ponteiro = %p\n", &ponteiro);

    printf("---------------\n");

    *ponteiro = 50; // Muda o valor que o ponteiro aponta, logo o valor da variavel var tambem eh modificado, porem mantendo o mesmo endereco de var

    printf("Conteudo de var = %d\n", var);
    printf("Endereco de var = %p\n", &var);
    printf("Conteudo apontado pelo ponteiro = %d\n", *ponteiro);
    printf("Endereco apontado pelo ponteiro = %p\n", ponteiro);
    printf("Endereco do proprio ponteiro = %p\n", &ponteiro);
    return 0;
}

/*Resumo:
*ponteiro: indica o conteudo do endereco da variavel que o ponteiro aponta, representado pelo *
ponteiro: indica o endereco da variavel apontado pelo ponteiro
&ponteiro: indica o proprio endereco do ponteiro
*/
