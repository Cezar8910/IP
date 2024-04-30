#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int pontos;
    int vitorias;
    int empates;
    int derrotas;
    int golspro;
    int golscontra;
    int saldo;
} Time;

int main()
{
    int numTimes;

    scanf("%d", &numTimes);

    Time equipe[numTimes * 2];

    // Inicializar todas as estruturas como 0
    for (int i = 0; i < numTimes * 2; i++)
    {
        equipe[i].pontos = 0;
        equipe[i].vitorias = 0;
        equipe[i].empates = 0;
        equipe[i].derrotas = 0;
        equipe[i].golspro = 0;
        equipe[i].golscontra = 0;
        equipe[i].saldo = 0;
    }

    // Ler os resultados dos jogos e preencher as estatísticas
    for (int i = 0; i < numTimes; i++)
    {
        char lixo; // variável para armazenar caracteres não utilizados
        int j = i + numTimes;
        scanf(" %s %d %c %d %s", equipe[i].nome, &equipe[i].golspro, &lixo, &equipe[j].golspro, equipe[j].nome);

        // Preencher estatísticas para gols contra e saldo de gols
        equipe[i].golscontra = equipe[j].golspro;
        equipe[j].golscontra = equipe[i].golspro;
        equipe[i].saldo = equipe[i].golspro - equipe[i].golscontra;
        equipe[j].saldo = equipe[j].golspro - equipe[j].golscontra;

        // Determinar vencedores, derrotas e empates
        if (equipe[i].golspro > equipe[j].golspro)
        {
            equipe[i].vitorias = 1;
            equipe[j].derrotas = 1;
            equipe[i].pontos = 3;
        }
        else if (equipe[i].golspro < equipe[j].golspro)
        {
            equipe[j].vitorias = 1;
            equipe[i].derrotas = 1;
            equipe[j].pontos = 3;
        }
        else if (equipe[i].golspro == equipe[j].golspro)
        {
            equipe[i].empates = 1;
            equipe[j].empates = 1;
            equipe[i].pontos = 1;
            equipe[j].pontos = 1;
        }
    }

    // Ordenar a equipe com base nas estatísticas
    for (int i = 0; i < (numTimes * 2) - 1; i++)
    {
        for (int j = i + 1; j < numTimes * 2; j++)
        {
            // Ordenar por pontos, vitórias, saldo de gols, gols pró e nome
            if (equipe[i].pontos < equipe[j].pontos ||
                (equipe[i].pontos == equipe[j].pontos && equipe[i].vitorias < equipe[j].vitorias) ||
                (equipe[i].pontos == equipe[j].pontos && equipe[i].vitorias == equipe[j].vitorias && equipe[i].saldo < equipe[j].saldo) ||
                (equipe[i].pontos == equipe[j].pontos && equipe[i].vitorias == equipe[j].vitorias && equipe[i].saldo == equipe[j].saldo && equipe[i].golspro < equipe[j].golspro) ||
                (equipe[i].pontos == equipe[j].pontos && equipe[i].vitorias == equipe[j].vitorias && equipe[i].saldo == equipe[j].saldo && equipe[i].golspro == equipe[j].golspro && strcmp(equipe[i].nome, equipe[j].nome) > 0))
            {
                Time aux = equipe[i];
                equipe[i] = equipe[j];
                equipe[j] = aux;
            }
        }
    }
    // PS *Que ordenação lascada PQP

    // Imprimir as estatísticas ordenadas
    for (int i = 0; i < numTimes * 2; i++)
    {
        printf("%d. %s %d %d %d %d %d %d %d\n", i + 1, equipe[i].nome, equipe[i].pontos, equipe[i].vitorias, equipe[i].empates, equipe[i].derrotas, equipe[i].golspro, equipe[i].golscontra, equipe[i].saldo);
    }

    return 0;
}

// Se eesa questao eh facil eu me chamo napoeleao, meu irmao me ajude
// Deixando registrado que foi um domingo inteiro nessa merda, pra no final pedir ajuda pro chatgpt e ele piorar ainda mais, me perdi depois disso e tiltei
// Relato - 1 mes programando em C e tenho medo de nao ester aprendendo direito, de nao conseguir chegar la, essa semana começo a desenvolver na tangram e estou perdido ainda com o que vou fazer, que Deus me ajude e que esse seja o caminho certo.