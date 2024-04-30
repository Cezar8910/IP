// LISTA DE PONTEIROS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
//-------------------------------------------------------------------------------------------------

// QUESTAO 2
int main()
{
    int vet[5] = {1, 2, 3, 4, 5};
    int *p;

    p = vet; // Nao preciso do "&" pois se trata de um vetor

    // Letra a
    printf("Endereco guardado em vet = %p\nEndereco guardado em p = %p\n", vet, p);
    printf("\n");
    // Letra b
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando p com [] = %d\n", p[i]);
    }
    printf("\n");
    // Letra c
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando p com * = %d\n", *p);
        p++; // Incremetando o valor no ponteiro para permitir que ele acesse o proximo...
    }
    printf("\n");
    // Letra d
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando [] = %d\n", vet[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Valores de vet utilizando * = %d\n", *(vet + i));
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

// QUESTAO 3
int main()
{
    char str[50];     // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int count;
    int i = -1;

    // Fiz a modificacao no scanf apenas para poder pegar strings com espacos(o que torna o codigo mais usual)
    scanf(" %49[^\n]", str);

    // Preciso pegar os valores(tamanho) da string principal ate ela acabar
    // Sabemos que *(ponteiro + indice) = vet[indice]
    for (i = 0; *(ptr_str + i) != '\0'; i++)
        ;

    // Preciso agora pegar tudo da string principal e passar para a string invertida, com os elementos invertidos
    // Utilizo essa condicao porque estabeleco que vai rodar ate i ser maior que 0, ja que estou decrementando no *(ptr_str + --i), ou seja, se i for maior que 0 entao ainda tem elementos na string
    while (i > 0)
    {
        *(ptr_inv++) = *(ptr_str + --i);
    }
    *ptr_inv = '\0';

    // Printando a saida
    printf("O inverso da string: %s\n\n", str_inv);

    return 0;
}
//-------------------------------------------------------------------------------------------------

// Questao 4
int main()
{
    char **str = NULL; // Ponteiro duplo nulo, comecamos como NULL porque vamos realocar
    char entrada[50];
    int i = 0, j = 0;

    while (scanf(" %49[^\n]", entrada) != EOF)
    {
        // Vamos alocar primeiro
        char *novaStr = (char *)malloc(strlen(entrada) + 1); // +1 porque estamos considerando o caractere final \0

        // Precisamos fazer a verificacao de sempre quando alocamos ou realocamos os vetores ou o que quer que seja
        if (novaStr == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(novaStr); // Limpei
            exit(1);       // Cai fora
        }
        strcpy(novaStr, entrada);

        // Agora vamos realocar a memoria
        char **ptr_aux = (char **)realloc(str, (i + 1) * sizeof(char *));

        // Verificacao
        if (ptr_aux == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(ptr_aux); // Limpei
            exit(1);       // Cai fora
        }

        str = ptr_aux; // Atribuindo o meu ponteiro duplo principal ao ponteiro auxiliar
        str[i] = novaStr;
        i++;
    }
    printf("\n");
    for (j = 0; j < i; j++)
    {
        if (str == NULL)
        {
            printf("Falha na alocacao da memoria");
            free(str); // Limpei
            exit(1);   // Cai fora
        }
        else
        {
            printf("%s\n", str[j]);
            free(str[j]);
        }
    }
    free(str);

    return 0;
}

//-------------------------------------------------------------------------------------------------

// QUESTAO 5
typedef struct
{
    char nome[30];
} Musica;

typedef struct
{
    char id[30];
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
    char operacao[30];

    int num_playlists = 0;
    Playlist *playlists = NULL;

    printf("Digite a opcao desejada:\nCREATE - Cria uma playlist\nADD - Adiciona uma musica na playlist\nDEL - Apaga uma musica de uma playlist\nBAN - Remove uma musica da plataforma\nFIM - Encerra o programa\n");

    scanf(" %s", operacao);

    while (strcmp(operacao, "FIM") != 0)
    {
        if (strcmp(operacao, "CREATE") == 0)
        {
            char id[30];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            criarPlaylist(&playlists, &num_playlists, id);
        }
        else if (strcmp(operacao, "ADD") == 0)
        {
            char id[30];
            char musica[30];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            printf("Agora, digite a musica que vai ser adicionada nessa playlist:\n");
            scanf(" %[^\n]", musica);
            adicionarMusica(playlists, num_playlists, id, musica);
        }
        else if (strcmp(operacao, "DEL") == 0)
        {
            char id[30];
            char musica[30];
            printf("Digite o id da playlist\n");
            scanf(" %[^\n]", id);
            printf("Digite o nome da musica que vai ser deletada:\n");
            scanf(" %[^\n]", musica);
            removerMusica(playlists, num_playlists, id, musica);
        }
        else if (strcmp(operacao, "BAN") == 0)
        {
            char musica[30];
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
    int temPlaylist = -1, temMusica = -1;

    for (int i = 0; i < num_playlists; i++)
    {
        if (strcmp(playlists[i].id, id) == 0)
        {
            temPlaylist = i;

            for (int j = 0; j < playlists[i].qtd_musicas; j++)
            {
                if (strcmp(playlists[i].musicas[j].nome, nome_musica) == 0)
                {
                    temMusica = j;
                }
            }
        }
    }

    if (temPlaylist == -1)
    {
        printf("Nao achei a tua playlist visse\n");
    }
    else if (temPlaylist != -1 && temMusica == -1)
    {
        printf("Nao achei a tua musica visse\n");
    }
    else if (temPlaylist >= 0 && temMusica >= 0)
    {
        int copiar = playlists[temPlaylist].qtd_musicas;
        playlists[temPlaylist].musicas[temMusica] = playlists[temPlaylist].musicas[playlists[temPlaylist].qtd_musicas - 1];
        playlists[temPlaylist].qtd_musicas--;
        playlists[temPlaylist].musicas = (Musica *)realloc(playlists[temPlaylist].musicas, (playlists[temPlaylist].qtd_musicas) * (sizeof(Musica)));

        if (playlists[temPlaylist].musicas == NULL)
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
    // Bubble sort
    for (int i = 0; i < num_playlists - 1; i++)
    {
        for (int j = 0; j < num_playlists - i - 1; j++)
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