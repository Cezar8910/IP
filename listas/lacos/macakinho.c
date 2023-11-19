#include <stdio.h>

int main()
{

    int n; // Quantidade de termos que vao ser calculados
    int i, j;
    int primo1 = 5;
    int primo2 = 3;

    double resultado = 0;

    scanf("%d", &n);
    for (j = 0; j < n; j++)
    {
        int entrou = 0;
        int ehPrimo = 1;
        int ehPrimo2 = 1;

        while (entrou == 0)
        {
            for (i = 2; i * i <= primo1; i++)
            {
                if (primo1 % i == 0) // Nao eh primo
                {
                    ehPrimo = 0;
                    entrou = 1;
                }
            }
            for (i = 2; i * i <= primo2; i++)
            {
                if (primo2 % i == 0) // Nao eh primo
                {
                    ehPrimo2 = 0;
                    entrou = 1;
                }
            }
            for (i = 2; i * i <= primo1 - 2; i++)
            {
                if ((primo1 - 2) % i == 0) // Nao eh primo
                {
                    ehPrimo2 = 0;
                    entrou = 1;
                }
            }
        }
        if (ehPrimo && ehPrimo2)
        {
            resultado += (1.0 / primo1) + (1.0 / primo2);
        }
        primo1 += 2;
        primo2 += 2;
    }
    printf("%.10lf", resultado);
    return 0;
}