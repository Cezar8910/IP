#include <stdio.h>
#include <string.h>

typedef struct
{
    char tipo[20];
    int valor;
    int performance;
} Peca;

int main()
{
    int dinheiro, numPecas;
    int i, j, k;

    // Aqui eu comeco lendo as entradas iniciais
    scanf("%d %d", &dinheiro, &numPecas);

    // Inicializo as pe�as escolhidas com pe�as inv�lidas
    Peca motorEscolhido = {"", 0, 0};
    Peca rodaEscolhida = {"", 0, 0};
    Peca latariaEscolhida = {"", 0, 0};

    Peca pecas[numPecas];

    for (i = 0; i < numPecas; i++)
    {
        scanf(" %s %d %d", pecas[i].tipo, &pecas[i].valor, &pecas[i].performance);
    }

    // Vari�veis para controlar se encontramos pelo menos uma pe�a de cada tipo
    int encontrouMotor = 0, encontrouRoda = 0, encontrouLataria = 0;

    // Percorro todas as combina��es poss�veis de pe�as
    for (i = 0; i < numPecas; i++)
    {
        for (j = 0; j < numPecas; j++)
        {
            for (k = 0; k < numPecas; k++)
            {
                // Verifico se a combina��o atual � v�lida
                if (pecas[i].valor + pecas[j].valor + pecas[k].valor <= dinheiro)
                {
                    if (strcmp(pecas[i].tipo, "Motor") == 0)
                    {
                        encontrouMotor = 1;
                        if (pecas[i].performance > motorEscolhido.performance)
                        {
                            motorEscolhido = pecas[i];
                        }
                    }
                    else if (strcmp(pecas[i].tipo, "Roda") == 0)
                    {
                        encontrouRoda = 1;
                        if (pecas[i].performance > rodaEscolhida.performance)
                        {
                            rodaEscolhida = pecas[i];
                        }
                    }
                    else if (strcmp(pecas[i].tipo, "Lataria") == 0)
                    {
                        encontrouLataria = 1;
                        if (pecas[i].performance > latariaEscolhida.performance)
                        {
                            latariaEscolhida = pecas[i];
                        }
                    }
                }
            }
        }
    }

    // Verifico se pelo menos uma pe�a de cada tipo foi escolhida
    if (!encontrouMotor || !encontrouRoda || !encontrouLataria)
    {
        printf("Nao foi possivel construir uma caranga...");
        return 0;
    }

    // Calculo a performance total e o dinheiro restante
    int performanceTotal = motorEscolhido.performance + rodaEscolhida.performance + latariaEscolhida.performance;
    int dinheiroRestante = dinheiro - motorEscolhido.valor - rodaEscolhida.valor - latariaEscolhida.valor;

    // Printo o resultado
    printf("Minha nave tem uma performance de %d pontos\n", performanceTotal);

    if (dinheiroRestante > 0)
    {
        printf("E ainda me sobraram %d mangos!", dinheiroRestante);
    }

    return 0;
}
