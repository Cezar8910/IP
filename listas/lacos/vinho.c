#include <stdio.h>

int main()
{

    int linhas = 1; // Quantidade de linhas
    int N;          // Notas
    int i = 0;
    int countNota = 0;  // Contador de notas
    int x = 0;          // Contador da quantidade de notas
    int countFinal = 0; // contador das médias das notas

    scanf("%d", &linhas);
    for (i = 0; i < linhas; i++)
    {
        int entrou = 0; // tag

        scanf("%d", &N);
        while (entrou == 0)
        {
            if (N == 0)
            {
                if (x != 0)
                {
                    countFinal += (countNota / x); // Média
                }
                countNota = 0; // Contador de notas
                x = 0;         // Contador da quantidade de notas

                entrou = 1; // Sair do loop
            }
            else
            {
                countNota += N;
                x++;
                scanf("%d", &N);
            }
        }
    }

    printf("Elas beberam %d taças!", countFinal);

    return 0;
}