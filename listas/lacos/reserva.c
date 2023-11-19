#include <stdio.h>
#include <stdlib.h>

int main() {
    int X, N, vip, soma;

    // Entrada de dados
    scanf("%d %d", &X, &N);

    // Variáveis para a melhor escolha
    int melhorCanal = 1;
    int melhorMinuto = 0;
    int menorDistancia = __INT_MAX__;
    int vipGarantido = 0;
    int sequencia;

    // Loop para iterar pelos canais
    for (int i = 0; i < N; i++) {
        int canalA, canalB;

        // Entrada de dados para os minutos
        scanf("%d%d", &canalA, &canalB);
        sequencia = 0;

        // Loop para iterar pelos minutos
        for (int minuto = 0; sequencia <= X; minuto++) {
            // Lógica para calcular a sequência
            if (minuto == 0)
                sequencia = canalA;
            else if (minuto == 1)
                sequencia = canalB;
            else
                sequencia = canalA + canalB;

            // Cálculo da distância sem a função abs
            int distanciaAtual = (X - sequencia) >= 0 ? (X - sequencia) : -(X - sequencia);

            // Verifica se há empate
            if (distanciaAtual == menorDistancia) {
                // Caso de empate, atualiza se o canal atual é maior
                if (i + 1 > melhorCanal) {
                    menorDistancia = distanciaAtual;
                    melhorMinuto = minuto + 1;
                    melhorCanal = i + 1;
                    vip = sequencia;
                }
            } else if (distanciaAtual < menorDistancia) {
                // Atualiza as melhores posições
                menorDistancia = distanciaAtual;
                melhorCanal = i + 1;
                melhorMinuto = minuto + 1;
                vip = sequencia;
            }

            // Atualiza os termos para o próximo passo na sequência
            if (minuto > 1) {
                canalA = canalB;
                canalB = sequencia;
            }
        }
    }

    soma = 0;

    // Cálculo da soma dos dígitos de vip
    while (vip > 0) {
        soma += vip % 10;
        vip /= 10;
    }

    vipGarantido = (soma > 10) ? 1 : 0;

    // Saída formatada
    if (vipGarantido == 1)
        printf("Xupenio, para ir ao Lulupalooza, entre no canal %d e será chamado aproximadamente no minuto %d com VIP garantido!!!\n", melhorCanal, melhorMinuto);
    else
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", melhorCanal, melhorMinuto);

    return 0;
}
