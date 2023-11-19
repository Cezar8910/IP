#include <stdio.h>

int main()
{

    const int notas = 4;
    const int alunos = 4;
    int i, j;

    float notasAlunos[alunos][notas];
    float mediaAlunos[alunos];

    float media = 0;

    for (i = 0; i < alunos; i++)
    {
        for (j = 0; j < notas; j++)
        {
            scanf("%f", &notasAlunos[i][j]);
            media += notasAlunos[i][j];
        }
        mediaAlunos[i] = media / notas;
        media = 0;
    }

    for (i = 0; i < alunos; i++)
    {
        printf("A media do aluno %d eh %.2f\n", i + 1, mediaAlunos[i]);
    }

    return 0;
}