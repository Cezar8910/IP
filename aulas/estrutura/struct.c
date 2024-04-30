#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    float notas[100];
    float media_aluno;
    int qtd_materias;
} Aluno;

int main()
{
    int n;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &n);

    Aluno alunos[n];
    for (int idx = 0; idx < n; idx++)
    {
        scanf(" %s", alunos[idx].nome);
        scanf("%d", &alunos[idx].qtd_materias);

        float media_para_aluno = 0;

        for (int i = 0; i < alunos[idx].qtd_materias; i++)
        {
            scanf("%f", &alunos[idx].notas[i]);
            media_para_aluno += alunos[idx].notas[i];
        }

        media_para_aluno = media_para_aluno / (float)alunos[idx].qtd_materias;
        alunos[idx].media_aluno = media_para_aluno;
    }

    float media_total = 0;
    for (int idx = 0; idx < n; idx++)
    {
        media_total += alunos[idx].media_aluno;
    }
    media_total = media_total / n;
    printf("+ acima da media | - abaixo da media.\n");
    for (int idx = 0; idx < n; idx++)
    {
        printf("O aluno %s: %c\n", alunos[idx].nome, (alunos[idx].media_aluno >= media_total ? '+' : '-'));
    }

    return 0;
}
