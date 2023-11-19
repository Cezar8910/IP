#include <stdio.h>

int main()
{
    int alvo, total_canais;
    scanf("%d %d", &alvo, &total_canais);

    int distancia_mais_proxima = alvo; // Inicializa com a distancia maxima possivel
    int canal_escolhido = 0;
    int passo_canal = 1;
    int soma_digitos = 0;
    int valor_mais_proximo = 0;
    int valor_a_somar = 0;

    for (int canal_atual = 1; canal_atual <= total_canais; canal_atual++)
    {
        int soma_atual = 0;
        int primeiro, segundo;
        scanf("%d %d", &primeiro, &segundo);

        int termo_atual, termo_anterior = primeiro;
        int passo_atual = 1;

        if ((alvo < primeiro || alvo > primeiro) && (alvo < segundo))
        {
            if (alvo < primeiro || alvo > primeiro)
            {
                valor_mais_proximo = primeiro;
            }

            int distancia_atual = alvo < primeiro ? primeiro - alvo : alvo - primeiro;

            if (distancia_atual < distancia_mais_proxima)
            {
                distancia_mais_proxima = distancia_atual;
                canal_escolhido = canal_atual;
                passo_canal = 1;
                valor_a_somar = primeiro;
            }
        }

        if (alvo == primeiro)
        {
            passo_canal = 1;
            canal_escolhido = canal_atual;
            canal_atual = 999999;
        }

        if (alvo > primeiro && alvo == segundo)
        {
            passo_canal = 2;
            canal_escolhido = canal_atual;
            canal_atual = 999999;
        }

        passo_atual += 2;

        do
        {
            termo_atual = primeiro + segundo;

            int distancia_atual = alvo < termo_atual ? termo_atual - alvo : alvo - termo_atual;

            if (distancia_atual < distancia_mais_proxima)
            {
                distancia_mais_proxima = distancia_atual;
                canal_escolhido = canal_atual;
                valor_a_somar = termo_atual;
                valor_mais_proximo = termo_atual;
                passo_canal = passo_atual;
            }

            termo_anterior = termo_atual;

            primeiro = segundo;
            segundo = termo_atual;
            passo_atual++;
        } while (abs(segundo - alvo) <= abs(primeiro - alvo));
    }

    while (valor_a_somar != 0)
    {
        soma_digitos += valor_a_somar % 10;
        valor_a_somar /= 10;
    }

    if (soma_digitos > 10)
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", canal_escolhido, passo_canal);
    }
    else
    {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP não vai rolar :(\n", canal_escolhido, passo_canal);
    }

    return 0;
}
