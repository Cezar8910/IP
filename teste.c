#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //Biblioteca usada apenas para calcular a distancia entre os pontos na distancia Euclidiana

// Structs
typedef struct
{
    char *nome_presente[100];
    char *nome_crianca[100];
    Tempo tempo;
    Posicao *posicao;

} Pedido;

typedef struct
{
    float posX;
    float posY;
    float posZ;
} Posicao;

typedef struct
{
    // Colocando como ponteiros, pois o horario e a data vao ser um vetor de horario e data
    Horario *horario;
    Data *data;
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
// Funcoes

Pedido *recebePedido(int *qtdPedidos)
{
    Pedido *pedido = NULL;
    // Precisamos alocar o pedido com malloc para nao usarmos espaco desncessario
    pedido = (Pedido *)malloc(sizeof(Pedido));
    // Caso o pedido seja nulo, vamos dar o fora do programa
    if (pedido == NULL)
    {
        printf("Falha na alocacao da memoria");
        exit(1);
    }
    // Data e hora para o pedido ser valido - 23/12/2013 23h59min
    // if ()
    // Fazendo um for para pedir o nome da crianca e do pedido de acordo com a quantidade de pedidos que foram solicitados
    for (int i = 0; i < qtdPedidos; i++)
    {
        printf("Digite o seu nome e o pedido que voce deseja: ");
        scanf(" %99[^\n] %99[^\n]", pedido->nome_crianca, pedido->nome_presente);
    }
}
void fazerEntregas(Pedido *pedidos, int qtdPedidos)
{
    int i = 0, j = 0; // Declarando as minhas variaveis que funcionarao como linha e coluna para a impressao do meu vetor
    // Enquanto i for < qtdPedidos rode esse loop, porque assim eu garanto que todos os pedidos foram rodados e que ele so vai parar quando o pedido for menor que i = 0, ou seja, nulo
    while (i < qtdPedidos)
    {

        // Fazendo o malloc no ponteiro, ja que nao podemos desperdicar memoria
        pedidos = (char *)malloc(sizeof(char));
        if (pedidos == NULL)
        {
            printf("Falha na alocacao da memoria");
            exit(1);
        }
        // Bubble sort(ordem alfabetica)
        for (i = 0; i < qtdPedidos - 1; i++)
        {
            for (j = 0; i < qtdPedidos - i - 1; i++)
            {
                // Fazendo a ordenacao em ordem alfabetica pelo nome do pedido como base, ja que quando eu ordeno em ordem alfabetica todos os outros parametros tambem vao ser ordenados
                if (strcmp(pedidos[j].nome_presente, pedidos[j + 1].nome_presente) > 0)
                {
                    Pedido aux;
                    aux = pedidos[j];
                    pedidos[j] = pedidos[j + 1];
                    pedidos[j + 1] = aux;
                }
            }
            printf("\n");
        }
        // Liberando a memoria do meu vetor principal
        free(pedidos);
    }
    // Ponteiro temporario para fazermos o realloc
    Pedido *temporario;
    temporario = pedidos;
    // Precisamos agora realocar para caso precisarmos aumentar o tamanho desse vetor
    // Fazendo o realloc para que seja aumentado em 1 de acordo com a quantidade de caracteres a mais digitados pelo usuario, em qualquer uma das instancias da struct
    temporario = (Pedido *)realloc(temporario, (i + 1) * sizeof(Pedido));
    // Verificacao padrao
    if (temporario == NULL)
    {
        printf("Falha na alocacao da memoria");
        // Preciso dar o free para liberar a memoria agora
        free(temporario);
        exit(1);
    }
    // Printando os presentes
    for (int i = 0; i < qtdPedidos; i++)
    {
        for (int j = 0; j < qtdPedidos; j++)
        {
            printf("%s", pedidos[j]); // Imprimindo o meu vetor de pedidos
        }
    }
}

void ordenaPedidos(Pedido *pedidos, int qtdPedidos)
{
    // Ordena o vetor de acorodo com as distancias entre os pedidos, tomando como base a posicao do papai noel atual
    Posicao *posicao;
    Posicao *auxiliar;
    auxiliar = posicao;
    // Como vai estar sempre atualizando a posicao, vamos dar um realloc para garantir que tera espaco suficiente e para eliminar o lixo de memoria presente em cada alocacao, ou caso o vetor seja nulo(== 0)
    auxiliar = (Posicao *)realloc(pedidos, (auxiliar->posX + auxiliar->posY + auxiliar->posZ) * sizeof(Posicao));
    if (auxiliar == NULL)
    {
        printf("Falha na alocacao da memoria");
        free(auxiliar);
        exit(1);
    }
    // Agora devemos chamar a funcao procuraProximoPedido, ja que vamos relacionar o proximo pedido com a posicao dele em relacao a do papai noel
    procuraProximoPedido(&pedidos, qtdPedidos, *posicao);
}

int procuraProximoPedido(Pedido *pedidos, int qtdPedidos, Posicao posAt)
{
    // Deve retornar o indice do pedido mais proximo da posicao atual e que tenha o menor tempo dentre os demais
    pedidos = NULL;
    Tempo *tempo;
    // A posicao inicial vai ser 0
    posAt.posX = 0;
    posAt.posY = 0;
    posAt.posZ = 0;

    // Fazendo a alocacao dinamica do pedido
    pedidos = (Pedido *)malloc(sizeof(Pedido));
    if (pedidos == NULL)
    {
        printf("Falha na alocacao da memoria");
        exit(1);
    }
    int i = 0;
    while (i < qtdPedidos)
    {
        // Se a posicao do meu pedido atual for "menor" em relacao a posAt(mesma posicao para todos) e que tenha um menor tempo retorne ele mesmo
        if (distancia(pedidos[i].posicao, pedidos[i + 1].posicao) < (posAt.posX + posAt.posY + posAt.posZ) && (menorOuIgualH(pedidos[i] < tempo[i + 1].horario)))
        {
            return pedidos;
        }
        i++;
    }
}

// Funcao para comparar os tempos
int menorOuIgualT(Tempo t1, Tempo t2)
{
    // Fazendo um ponteiro de resultado para poder reaproveitalo nas outras funcoes a partir do resultado de cada condicao
    int *resultado = 0;

    // Talvez devesse usar a funcao de data e hora aqui, mas nao esta encaixando
    if (t1.data == t2.data && t1.horario == t2.horario)
    {
        return *resultado = 0;
    }
    else if (t1.data < t2.data || (t1.data == t2.data && t1.horario < t2.horario))
    {
        return *resultado = -1;
    }
    else if (t1.data > t2.data || (t1.data == t2.data && t1.horario > t2.horario))
    {
        return *resultado = 1;
    }
}

// Funcao para comparar as horas
int menorOuIgualH(Horario h1, Horario h2)
{
    int *resultado2;
    if (h1.hora == h2.hora && h1.minuto == h2.minuto)
    {
        return *resultado2 = 0;
    }
    else if (h1.hora < h2.hora || (h1.hora == h2.hora && h1.minuto < h2.minuto))
    {
        return *resultado2 = -1;
    }
    else if (h1.hora > h2.hora || (h1.hora == h2.hora && h1.minuto > h2.minuto))
    {
        return *resultado2 = 1;
    }
}
// Funcao para comparar as datas
int menorOuIgualD(Data d1, Data d2)
{
    int *resultado3 = 0;
    // Caso as datas sejam iguais retorne 0
    if (d1.dia == d2.dia && d1.dia == d2.dia && d1.ano == d1.ano)
    {
        return *resultado3 = 0;
    }
    // Caso a data 1 for menor que a data 2 retorne -1
    else if (d1.ano < d2.ano || d1.mes < d2.mes || d1.dia < d2.dia)
    {

        return *resultado3 = -1;
    }
    // Caso a data 1 for maior que a data 2 retorne 1
    else if (d1.ano > d2.ano || d1.mes > d2.mes || d1.dia > d2.dia)
    {

        return *resultado3 = 1;
    }
}

float distancia(Posicao p1, Posicao p2)
{
    Posicao *posicao;

    // Inicializando as minhas posicoes
    posicao->posX = 0.0;
    posicao->posY = 0.0;
    posicao->posZ = 0.0;

    float diatancia_entre_pontos = sqrt((p2.posX - p1.posX) * (p2.posX - p1.posX) + (p2.posY - p2.posY) * (p2.posY - p2.posY) + (p2.posZ - p1.posZ) * (p2.posZ - p1.posZ));
    // Retorna a distancia entre pontos
    //  D(p1,p2 - Distancia entre os pontos = DIstancia Euclidiana
    return diatancia_entre_pontos;
}

// Funcao principal
int main()
{
    int qtdPedidos = 0;
    Pedido *pedidos;
    Posicao *posicao;

    // Receber os pedidos de presente - parte 1
    recebePedido(&qtdPedidos);
    fazerEntregas(&pedidos, &qtdPedidos);

    return 0;
}