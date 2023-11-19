#include <stdio.h>

int main()
{
    // A < B e N eh o número de iteraçoes da soma.
    float a, b, n; // n -> iteracoes da soma
    float c;       // Resultado
    int i;

    scanf("%f %f %f", &a, &b, &n);

    scanf("%f", &c);

    float base = (b - a) / n;
    float soma = 0;
    for (i = 0; i < n; i++)
    {
        float altura = a + base;
        float area = base * altura * altura;
        soma += area;
        a += base;
    }

    if (soma > c)
    {
        printf("Maior");
    }
    else if (soma < c)
    {
        printf("Menor");
    }
    else if (soma == c)
    {
        printf("Igual");
    }
    return 0;
}