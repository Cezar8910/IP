#include <stdio.h>

int main()
{

    // CÓDIGO PRECISA SER REVISADO PARA ENTENDER MELHOR A LÓGICA
    //  1 <= N, A, B <= 10000000 | A e B são primos
    long long int n, mc, multiplos, a, b, somaN, resultado, paA, paB, par;

    scanf("%lld", &n);
    scanf("%lld %lld", &a, &b);

    mc = (1 + n / (a * b)) * (n / (a * b)) * a * b / 2; // Múltiplo comum
    somaN = (1 + n) * n / 2;                            // Fatorial da soma
    paA = (n / a) * (1 + n / a) * a / 2;                // Pa de a
    paB = (n / b) * (1 + n / b) * b / 2;                // Pa de b
    multiplos = paA + paB;                              // multiplos de a e b
    resultado = somaN - multiplos + mc;                 // result
    par = resultado % 2 == 0;                           // Verifica se o result é par

    printf("%lld\n", resultado);

    if (par)
    {
        printf("Lá ele!!!\n");
    }
    else
    {
        printf("Opa xupenio AULAS...\n");
    }

    return 0;
}