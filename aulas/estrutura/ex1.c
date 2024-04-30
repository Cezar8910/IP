#include <stdio.h>
#include <string.h>
#define TAM 3
typedef struct
{
    char nome[100];
    float nota;
} Disciplinhas;

typedef struct
{
    char nome[100];
    float media;
    Disciplinhas cursando[5];

} Aluno;

int main()
{
    int iAluno, iDisc;

    Aluno turma[70];
    Disciplinhas func2[TAM];

    float soma, somaGeral = 0, mediaGeral;

    for (iAluno = 0; iAluno < 70; iAluno++)
    {
        for (iDisc = 0; iDisc < 5; iDisc++)
        {
            scanf(" %99[^\n]", turma[iAluno].cursando[iDisc].nome);
            scanf("%f", &turma[iAluno].cursando[iDisc].nota);
            soma += turma[iAluno].cursando[iDisc].nota;
        }
        turma[iAluno].media = soma / 5;
        somaGeral += turma[iAluno].media;
    }

    mediaGeral = (somaGeral / 70);
    return 0;
}