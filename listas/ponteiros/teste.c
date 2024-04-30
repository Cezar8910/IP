/*Questão 5: Em um sistema de streaming de músicas, os usuários podem criar playlists e
adicionar músicas, porém é possível que alguma música seja removida do sistema, e essa
mudança deve ser refletida nas playlists que contenham aquela música. Desenvolva um
programa que simule esse sistema, a entrada irá consistir em várias linhas, onde cada uma
possuirá um dos seguintes formatos:
CREATE playlist_id Cria uma playlist com o id fornecido
ADD playlist_id nome_musica Adiciona a música na playlist fornecida
DEL playlist_id nome_musica Apaga a música da playlist fornecida
BAN nome_musica Remove a música da plataforma
FIM Fim da leitura
Após o término da leitura, imprima todas as playlists em ordem decrescente de quantidade
de músicas, incluindo as músicas em cada uma.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 50

typedef struct Musica
{
    char nome[TAM];
} Musica;

typedef struct Playlist
{
    char id[TAM];
    int qtd_musica;
    Musica *musicas;
} Playlist;

int main()
{
    char opcao[10];

    int flag_p = 0;

    Playlist *p_playlist = NULL;

    p_playlist = (Playlist *)malloc((flag_p + 1) * (sizeof(Playlist))); // alocar memoria pro ponteiro

    printf("**** BEM VINDO AO SPOTICIN ****\n\nSelecione a opcao desejada:\nCREATE - Criar uma nova playlist\nADD - Adicionar uma musica na playlist\nDEL - Deletar uma musica da playlist\nBAN - Banir uma musica da plataforma\nFIM - Sair do programa\n");
    scanf(" %s", opcao);

    while (strcmp(opcao, "FIM") != 0)
    { // enquanto o usuario nao escolher a opcao "FIM"
        // CREATE playlist_id - Cria uma playlist com o id fornecido
        if (strcmp(opcao, "CREATE") == 0)
        { // se o usuario escolher CREATE

            char id[TAM];
            printf("Por favor, digite o id da playlist a ser criada: \n");
            scanf(" %[^\n]", id);

            p_playlist = (Playlist *)realloc(p_playlist, (flag_p + 1) * (sizeof(Playlist)));
            if (p_playlist == NULL)
                exit(1);
            strcpy(p_playlist[flag_p].id, id); // copia o id
            p_playlist[flag_p].musicas = NULL; // inicializa tudo como nulo
            p_playlist[flag_p].qtd_musica = 0; // inicializa como zero
            flag_p++;                          // adiciona mais um na flag

            printf("\nSelecione a opcao desejada:\nCREATE - Criar uma nova playlist\nADD - Adicionar uma musica na playlist\nDEL - Deletar uma musica da playlist\nBAN - Banir uma musica da plataforma\nFIM - Sair do programa\n");
        }

        // ADD playlist_id nome_musica Adiciona a música na playlist fornecida
        else if (strcmp(opcao, "ADD") == 0)
        {

            char id[TAM];
            char music[TAM];
            int achou = -1;

            printf("Por favor, digite a playlist a adicionar musica: \n");
            scanf(" %[^\n]", id); // ler qual playlist

            printf("Por favor, digite o nome da musica a ser adicionada: \n");
            scanf(" %[^\n]", music); // ler qual musica

            for (int i = 0; i < flag_p; i++)
            { // ir procurar a playlist pelo nome

                if (strcmp(p_playlist[i].id, id) == 0)
                {
                    achou = i;
                }
            }

            if (achou == -1)
            {
                printf("Playlist nao encontrada\n");
            }

            else
            {
                // realocar espaco pro ponteiro de musica
                int facilitar = p_playlist[achou].qtd_musica;
                p_playlist[achou].musicas = (Musica *)realloc(p_playlist[achou].musicas, (facilitar + 1) * sizeof(Musica));
                if (p_playlist[achou].musicas == NULL)
                    exit(1);
                strcpy(p_playlist[achou].musicas[facilitar].nome, music); // copiar o nome da musica
                p_playlist[achou].qtd_musica++;
            }

            printf("\nSelecione a opcao desejada:\nCREATE - Criar uma nova playlist\nADD - Adicionar uma musica na playlist\nDEL - Deletar uma musica da playlist\nBAN - Banir uma musica da plataforma\nFIM - Sair do programa\n");
        }

        // DEL playlist_id nome_musica Apaga a música da playlist fornecida
        else if (strcmp(opcao, "DEL") == 0)
        {
            char id[TAM];
            char music[TAM];
            int achoup = -1, achoum = -1;

            printf("Por favor, digite o id da playlist: \n");
            scanf(" %[^\n]", id); // nome da playlist

            printf("Por favor, digite o nome da musica a ser deletada: \n");
            scanf(" %[^\n]", music); // nome da musica

            for (int i = 0; i < flag_p; i++)
            {
                if (strcmp(p_playlist[i].id, id) == 0)
                {               // se achou a playlist
                    achoup = i; // playlist achada
                    for (int j = 0; j < p_playlist[i].qtd_musica; j++)
                    {
                        if (strcmp(p_playlist[i].musicas[j].nome, music) == 0)
                        {               // ir procurando as musicas
                            achoum = j; // musica achada
                        }
                    }
                }
            }

            if (achoup == -1)
            { // nao encontrou a playlist
                printf("Playlist nao encontrada\n");
            }

            else if (achoup != -1 && achoum == -1)
            { // encontrou a playlist mas nao encontrou a musica
                printf("Musica nao encontrada\n");
            }

            else if (achoup >= 0 && achoum >= 0)
            { // achou tanto a playlist quanto a musica
                // copiar a ultima pra aquela do lugar
                int copiar = p_playlist[achoup].qtd_musica;
                p_playlist[achoup].musicas[achoum] = p_playlist[achoup].musicas[p_playlist[achoup].qtd_musica - 1];
                p_playlist[achoup].qtd_musica--;
                p_playlist[achoup].musicas = (Musica *)realloc(p_playlist[achoup].musicas, (p_playlist[achoup].qtd_musica) * (sizeof(Musica)));
                if (p_playlist[achoup].musicas == NULL)
                    exit(1);
                printf("Musica removida.\n");
            }
            printf("\nSelecione a opcao desejada:\nCREATE - Criar uma nova playlist\nADD - Adicionar uma musica na playlist\nDEL - Deletar uma musica da playlist\nBAN - Banir uma musica da plataforma\nFIM - Sair do programa\n");
        }

        // BAN nome_musica Remove a música da plataforma
        else if (strcmp(opcao, "BAN") == 0)
        {
            char music[TAM];

            printf("Por favor, digite o nome da musica a ser banida da plataforma: \n");
            scanf(" %[^\n]", music);

            for (int i = 0; i < flag_p; i++)
            {
                for (int j = 0; j < p_playlist[i].qtd_musica; j++)
                {

                    if (strcmp(p_playlist[i].musicas[j].nome, music) == 0)
                    { // se achar a musica em alguma playlist

                        p_playlist[i].musicas[j] = p_playlist[i].musicas[p_playlist[i].qtd_musica - 1];
                        // liberar aquela musica e realocar
                        p_playlist[i].qtd_musica--;
                        p_playlist[i].musicas = (Musica *)realloc(p_playlist[i].musicas, (p_playlist[i].qtd_musica) * (sizeof(Musica)));
                        if (p_playlist[i].musicas == NULL)
                            exit(1);
                    }
                }
            }
            printf("Musica banida.\n");
            printf("\nSelecione a opcao desejada:\nCREATE - Criar uma nova playlist\nADD - Adicionar uma musica na playlist\nDEL - Deletar uma musica da playlist\nBAN - Banir uma musica da plataforma\nFIM - Sair do programa\n");
        }

        scanf(" %s", opcao);
    }

    for (int i = 0; i < flag_p - 1; i++)
    { // ir ajeitar por quantidade de musica
        for (int j = i + 1; j < flag_p; j++)
        {
            if (p_playlist[i].qtd_musica < p_playlist[j].qtd_musica)
            {
                Playlist aux;
                aux = p_playlist[i];
                p_playlist[i] = p_playlist[j];
                p_playlist[j] = aux;
            }
        }
    }

    for (int i = 0; i < flag_p; i++)
    {

        printf("\n***** Playlist %s *****\n", p_playlist[i].id);

        for (int j = 0; j < p_playlist[i].qtd_musica; j++)
        {
            printf("[%d] %s\n", j + 1, p_playlist[i].musicas[j].nome);
        }

        free(p_playlist[i].musicas);
    }
    printf("**** OBRIGADA POR USAR O SPOTICIN ****");
    free(p_playlist);
}