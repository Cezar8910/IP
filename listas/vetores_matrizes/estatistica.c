#include <stdio.h>

int main()
{

    int n; // Quantidade de notas
    int i, j;

    float media = 0;
    float mediana = 0;

    scanf("%d", &n);
    float notas[50];   // Vetor
    int frequencia[n]; // Vetor da moda

    for (i = 0; i < n; i++)
    {
        scanf("%f", &notas[i]);
        media += notas[i] / n;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (notas[j] > notas[j + 1]) // Ordenacao bubble sort ordem crescente
            {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        frequencia[i] = -1;
    }

    // calcular a frequencia
    for (i = 0; i < n; i++)
    {
        int count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (notas[i] == notas[j])
            {
                count++;
                frequencia[j] = 0;
            }
        }

        if (frequencia[i] != 0)
        {
            frequencia[i] = count;
        }
    }

    // calcular a moda
    int maxFrequencia = frequencia[0];
    float moda = notas[0];
    int semModa;
    
    for (i = 1; i < n; i++)
    {
        if (frequencia[i] > maxFrequencia)
        {
            moda = notas[i];
            maxFrequencia = frequencia[i];
        }
        else if (maxFrequencia == frequencia[i])
        {
            semModa = moda;
        }
    }

    if (n % 2 == 0)
    {
        mediana += (notas[n / 2] + notas[n / 2 - 1]) / 2;
    }
    else
    {
        mediana += notas[n / 2];
    }

    printf("\nMedia: %.2f\nMediana: %.2f\n", media, mediana);

    if (semModa == moda)
    {

        printf("Nao tem moda\n");
    }
    else
    {
        printf("Moda: %.2f\n", moda);
    }
    return 0;
}