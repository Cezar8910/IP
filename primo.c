#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nome_presente[100];
    char nome_crianca[100];
    Tempo tempo;
    Posicao posicao;
} Pedido;

typedef struct
{
    float posX;
    float posY;
    float posZ;
} Posicao;

typedef struct
{
    Horario horario;
    Data data;
} Tempo;

typedef struct
{
    int hora;
    int minuto;
} Horario;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

int menorOuIgualT(Tempo t1, Tempo t2);
int menorOuIgualH(Horario h1, Horario h2);
int menorOuIgualD(Data d1, Data d2);
float distancia(Posicao p1, Posicao p2);

int comparePedidos(const void *a, const void *b)
{
    return strcmp(((Pedido *)a)->nome_presente, ((Pedido *)b)->nome_presente);
}

Pedido *recebePedido(int *qtdPedidos)
{
    printf("Digite a quantidade de pedidos: ");
    scanf("%d", qtdPedidos);

    Pedido *pedidos = (Pedido *)malloc(*qtdPedidos * sizeof(Pedido));
    if (pedidos == NULL)
    {
        printf("Falha na alocacao da memoria");
        exit(1);
    }

    for (int i = 0; i < *qtdPedidos; i++)
    {
        printf("Digite o nome da crianca e o pedido desejado: ");
        scanf(" %99[^\n] %99[^\n]", pedidos[i].nome_crianca, pedidos[i].nome_presente);
    }

    return pedidos;
}

void fazerEntregas(Pedido *pedidos, int qtdPedidos)
{
    qsort(pedidos, qtdPedidos, sizeof(Pedido), comparePedidos);

    for (int i = 0; i < qtdPedidos; i++)
    {
        printf("%s - %s\n", pedidos[i].nome_crianca, pedidos[i].nome_presente);
    }
}

void ordenaPedidos(Pedido *pedidos, int qtdPedidos, Posicao posicao)
{
    // Implemente a lógica de ordenação dos pedidos de acordo com a distância
    // entre as posições e a posição atual do Papai Noel.
    // Aqui, você pode usar a função qsort para ordenar o vetor de pedidos.
    // A função comparePedidos já foi definida.
}

int procuraProximoPedido(Pedido *pedidos, int qtdPedidos, Posicao posAt)
{
    int indiceProximo = -1;
    float menorDistancia = FLT_MAX;

    for (int i = 0; i < qtdPedidos; i++)
    {
        float d = distancia(posAt, pedidos[i].posicao);
        if (d < menorDistancia)
        {
            menorDistancia = d;
            indiceProximo = i;
        }
    }

    return indiceProximo;
}

int main()
{
    int qtdPedidos = 0;
    Pedido *pedidos;

    pedidos = recebePedido(&qtdPedidos);
    fazerEntregas(pedidos, qtdPedidos);

    // Supondo que a posição inicial do Papai Noel é (0, 0, 0)
    Posicao posicaoAtual = {0.0, 0.0, 0.0};

    int proximoPedido = procuraProximoPedido(pedidos, qtdPedidos, posicaoAtual);

    printf("Proximo pedido: %s - %s\n", pedidos[proximoPedido].nome_crianca, pedidos[proximoPedido].nome_presente);

    free(pedidos);

    return 0;
}
