#include <stdio.h>
#include <string.h>

int main()
{
    int n; // Alunos que serao cadastrados
    int i, j;

    scanf("%d", &n);

    char senha[n][13];

    char nome[n][11];

    int deslocamento;

    for (i = 0; i < n; i++)
    {
        char cpf[12];

        scanf(" %s %s", nome[i], cpf);

        for (j = 0; nome[i][j] != '\0'; j++)
        {

            deslocamento = cpf[j];

            char modificado = nome[i][j];

            char novoNome = (modificado - 'a' + (deslocamento - 48) + 26) % 26 + 'a'; // -48 porque assim eu pego o proprio numero(subtraindo do 0) e nao outro numero na tabela ascii

            senha[i][j] = novoNome;
            if (nome[i][j + 1] == '\0') // Se a senha terminou
            {
                senha[i][j + 1] = cpf[9];  // Adiciona o penultimo digito ao final
                senha[i][j + 2] = cpf[10]; // Adiciona o ultimo digito ao final
                senha[i][j + 3] = '\0';    // Termina a senha
            }
        }
    }

    for (i = 0; i < n - 1; i++) // Ordenando as strings
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(nome[j], nome[j + 1]) > 0) // Bubble sort usando funcoes da string.h
            {
                char aux[11];         // Para ordenar os nomes
                strcpy(aux, nome[j]); // Troca o nome pelo auxiliar
                strcpy(nome[j], nome[j + 1]);
                strcpy(nome[j + 1], aux);

                char aux2[13];          // Impede que a senha ultrapasse o numero de carcteres do nome relacionados ao cpf
                strcpy(aux2, senha[j]); // Troca a senha pelo auxiliar
                strcpy(senha[j], senha[j + 1]);
                strcpy(senha[j + 1], aux2);
            }
        }
    }

    printf("\n"); // Quebrar a linha apos digitar a entrada

    // Printar o resultado
    for (i = 0; i < n; i++)
    {
        printf("%s %s\n", nome[i], senha[i]);
    }

    return 0;
}
