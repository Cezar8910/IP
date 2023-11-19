#include <stdio.h>

int main()
{
    // Numeros pares seriam equivalente a pedra, impares equivalente a tesoura e primos equivalente a papel;

    int n = 1; // Numero de rodadas
    int i = 0;
    int a, b;             // Valores jogados por cada jogador
    int vitoriaSapo = 0;  // Vitoria de a
    int vitoriaShuas = 0; // Vitoria de b
    int entrou = 0;       // tag
    // p - pedra, g - papel, t - tesoura
    int j = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int primoA = 1;
        int primoB = 1;

        scanf("%d %d", &a, &b);

        for (j = 2; j * j <= a; j++)
        {
            if (a % j == 0)
            {
                primoA = 0;
                break;
            }
        }
        for (j = 2; j * j <= b; j++)
        {
            if (b % j == 0)
            {
                primoB = 0;
                break;
            }
        }
        if (primoA == 1 && a != 1) // papel
        {
            if (b == 1) // Conisderada impar
            {

                primoB = 0;
                vitoriaShuas += 1;
            }
            else if (primoB)
            {
                vitoriaSapo += 1;
                vitoriaShuas += 1;
            }
            else if (b % 2 == 0)
            {
                vitoriaSapo += 1;
            }
            else if (b % 2 != 0)
            {
                vitoriaShuas += 1;
            }
        }
        else if (primoB == 1 && b != 1) // papel
        {
            if (a == 1)
            {
                primoA = 0;
                vitoriaSapo += 1;
            }
            else if (primoA)
            {
                vitoriaShuas += 1;
                vitoriaSapo += 1;
            }
            else if (a % 2 == 0)
            {
                vitoriaShuas += 1;
            }
            else if (a % 2 != 0)
            {
                vitoriaSapo += 1;
            }
        }
        else if (primoA == 0 && primoB == 0)
        {
            if (a % 2 == 0 && b % 2 != 0)
            {
                vitoriaSapo += 1;
            }
            else if (a % 2 != 0 && b % 2 == 0)
            {
                vitoriaShuas += 1;
            }
            else if (a % 2 == 0 && b % 2 == 0)
            {
                vitoriaSapo += 1;
                vitoriaShuas += 1;
            }
            else if (a % 2 != 0 && b % 2 != 0)
            {
                vitoriaSapo += 1;
                vitoriaShuas += 1;
            }
        }
    }
    if (vitoriaSapo == vitoriaShuas)
    {
        printf("Impending doom approaches...\n");
    }
    else if (vitoriaSapo > vitoriaShuas)
    {
        printf("Sapo sopa esta de boa na lagoa!\n");
    }
    else if (vitoriaShuas > vitoriaSapo)
    {
        printf("Testemunhe a verdadeira forca!\n");
    }
    return 0;
}