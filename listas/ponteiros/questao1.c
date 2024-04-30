#include <stdio.h>
#include <stdlib.h>

int main()
{
    // QUESTAO 1
    char c = 'a'; // Variavel
    char *pc;     // Ponteiro

    pc = &c; // Ponteiro recebendo o endereco de c

    // Letra a
    printf("Endereco de c = %p\nValor de c = %c\n", &c, c);
    // Letra b
    printf("\nValor de pc = %p\nValor guardado por pc = %c\n", pc, *pc);
    // Letra c
    printf("\nEndereco de pc = %p\n", &pc); // Endereco do proprio ponteiro
    // Letra d
    printf("\nEndereco do valor guardado no endereco apontado por pc = %p\nValor guardado no endereco de pc = %p\n", &*pc, *&pc);
    /* Justificativa:
    Ambos tem o mesmo valor, porem com maneiras difentes de serem chamados porque na primeira vez eu estou pegando o endereco do valor(por isso usamos &*pc), pois o "&" representa o endereco do proprio ponteiro e "*" o valor que ele aponta, ou seja, o endereco do ponteiro que aponta para o endereco da variavel c.

    Na outra ele esta pedindo o valor guardado no endereco, ou seja, como "*" representa justamente o valor guardado pelo ponteiro, nos devemos receber o valor "*" guardado no endereco "&" do ponteiro "pc"(endereco da variavel c).

    Por isso ambos os valores(enderecos) sao iguais.
    */
    return 0;
}
