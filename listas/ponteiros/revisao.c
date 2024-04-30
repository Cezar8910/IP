#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct Musica
{
    char nome[TAM];
} Musica;

typedef struct Playlist
{
    char id[TAM];
    int qtd_musicas;
    Musica *musicas;
} Playlist;

// Inicializando as funcoes para poder escrever abaixo da main sem dar problema
void criarPlaylist(Playlist **playlists, int *num_playlists, char *id);
void adicionarMusica(Playlist *playlists, int num_playlists, char *id, char *nome_musica);
void removerMusica(Playlist *playlists, int num_playlists, char *id, char *nome_musica);
void banirMusica(Playlist *playlists, int num_playlists, char *nome_musica);
void imprimirPlaylists(Playlist *playlists, int num_playlists);

int main()
{
    char operacao[TAM];

    int num_playlists = 0;
    Playlist *playlists = NULL;

    printf("Digite a opcao desejada:\nCREATE - Cria uma playlist\nADD - Adiciona uma musica na playlist\nDEL - Apaga uma musica de uma playlist\nBAN - Remove uma musica da plataforma\nFIM - Encerra o programa\n");

    scanf(" %s", operacao);

    while (strcmp(operacao, "FIM") != 0)
    {
        if (strcmp(operacao, "CREATE") == 0)
        {
            char id[TAM];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            criarPlaylist(&playlists, &num_playlists, id);
        }
        else if (strcmp(operacao, "ADD") == 0)
        {
            char id[TAM];
            char musica[TAM];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            printf("Agora, digite a musica que vai ser adicionada nessa playlist:\n");
            scanf(" %[^\n]", musica);
            adicionarMusica(playlists, num_playlists, id, musica);
        }
        else if (strcmp(operacao, "DEL") == 0)
        {
            char id[TAM];
            char musica[TAM];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            printf("Digite o nome da musica que vai ser deletada:\n");
            scanf(" %[^\n]", musica);
            removerMusica(playlists, num_playlists, id, musica);
        }
        else if (strcmp(operacao, "BAN") == 0)
        {
            char musica[TAM];
            printf("Digite o nome da musica: \n");
            scanf(" %[^\n]", musica);
            banirMusica(playlists, num_playlists, musica);
        }

        printf("Digite a operacao desejada:\nCREATE - Cria uma playlist\nADD - Adiciona uma musica na playlist\nDEL - Apaga uma musica de uma playlist\nBAN - Remove uma musica da plataforma\nFIM - Encerra o programa\n");
        scanf(" %s", operacao);
    }

    imprimirPlaylists(playlists, num_playlists);

    // Liberar memória alocada dinamicamente
    for (int i = 0; i < num_playlists; i++)
    {
        free(playlists[i].musicas);
    }
    free(playlists);

    return 0;
}

void criarPlaylist(Playlist **playlists, int *num_playlists, char *id)
{
    *num_playlists += 1;
    *playlists = (Playlist *)realloc(*playlists, (*num_playlists) * sizeof(Playlist));

    if (*playlists == NULL)
    {
        exit(1);
    }

    Playlist *nova_playlist = &(*playlists)[*num_playlists - 1];
    strcpy(nova_playlist->id, id);
    nova_playlist->musicas = NULL;
    nova_playlist->qtd_musicas = 0;
}

void adicionarMusica(Playlist *playlists, int num_playlists, char *id, char *nome_musica)
{
    int achou = -1;

    for (int i = 0; i < num_playlists; i++)
    {
        if (strcmp(playlists[i].id, id) == 0)
        {
            achou = i;
        }
    }

    if (achou == -1)
    {
        printf("Nao achei a tua playlist visse\n");
    }
    else
    {
        int suporte = playlists[achou].qtd_musicas;
        playlists[achou].musicas = (Musica *)realloc(playlists[achou].musicas, (suporte + 1) * sizeof(Musica));

        if (playlists[achou].musicas == NULL)
        {
            exit(1);
        }

        strcpy(playlists[achou].musicas[suporte].nome, nome_musica);
        playlists[achou].qtd_musicas++;
    }
}

void removerMusica(Playlist *playlists, int num_playlists, char *id, char *nome_musica)
{
    int temP = -1, achoum = -1;

    for (int i = 0; i < num_playlists; i++)
    {
        if (strcmp(playlists[i].id, id) == 0)
        {
            temP = i;

            for (int j = 0; j < playlists[i].qtd_musicas; j++)
            {
                if (strcmp(playlists[i].musicas[j].nome, nome_musica) == 0)
                {
                    achoum = j;
                }
            }
        }
    }

    if (temP == -1)
    {
        printf("Nao achei a tua playlist visse\n");
    }
    else if (temP != -1 && achoum == -1)
    {
        printf("Nao achei a tua musica visse\n");
    }
    else if (temP >= 0 && achoum >= 0)
    {
        int copiar = playlists[temP].qtd_musicas;
        playlists[temP].musicas[achoum] = playlists[temP].musicas[playlists[temP].qtd_musicas - 1];
        playlists[temP].qtd_musicas--;
        playlists[temP].musicas = (Musica *)realloc(playlists[temP].musicas, (playlists[temP].qtd_musicas) * (sizeof(Musica)));

        if (playlists[temP].musicas == NULL)
        {
            exit(1);
        }

        printf("Musica removida com sucesso.\n");
    }
}

void banirMusica(Playlist *playlists, int num_playlists, char *nome_musica)
{
    for (int i = 0; i < num_playlists; i++)
    {
        for (int j = 0; j < playlists[i].qtd_musicas; j++)
        {
            if (strcmp(playlists[i].musicas[j].nome, nome_musica) == 0)
            {
                playlists[i].musicas[j] = playlists[i].musicas[playlists[i].qtd_musicas - 1];
                playlists[i].qtd_musicas--;
                playlists[i].musicas = (Musica *)realloc(playlists[i].musicas, (playlists[i].qtd_musicas) * (sizeof(Musica)));

                if (playlists[i].musicas == NULL)
                {
                    exit(1);
                }
            }
        }
    }

    printf("Musica banida com sucesso.\n");
}

void imprimirPlaylists(Playlist *playlists, int num_playlists)
{
    for (int i = 0; i < num_playlists - 1; i++)
    {
        for (int j = i + 1; j < num_playlists; j++)
        {
            if (playlists[i].qtd_musicas < playlists[j].qtd_musicas)
            {
                Playlist temp;
                temp = playlists[i];
                playlists[i] = playlists[j];
                playlists[j] = temp;
            }
        }
    }

    for (int i = 0; i < num_playlists; i++)
    {
        printf("\n%s\n", playlists[i].id);

        for (int j = 0; j < playlists[i].qtd_musicas; j++)
        {
            printf("%s\n", playlists[i].musicas[j].nome);
        }

        free(playlists[i].musicas);
    }
}
/*Tempo de dev: 7h50min*/