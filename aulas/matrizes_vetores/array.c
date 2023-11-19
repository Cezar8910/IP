#include <stdio.h>

int main()
{

    /*  int n;
     float media, soma = 0;
     scanf("%d", &n);
     float num[n];

     for (int i = 0; i < n; i++)
     {
         printf("Digite o %do elemento: ", i + 1);
         scanf("%f", &num);
         soma += num[i];
     }
     media = soma / n;
     printf("Media: %.2f\n", media);
     for (int i = 0; i < n; i++)
     {
         if (num[i] < media)
         {
             printf("%do elemento: %.2f\n", i + 1, num[i]);
                 }
     } */

    // Ler os numeros de uma sequencia de tras para frente

    /* int n; // Quantidade de vetores
    int i;

    scanf("%d", &n);

    int num[n];

    for (i = 0; i < n; i++)
    {
        printf("Digite os elementos: %d");
        scanf("%d", &num[i]);
    }

    for (i = n - 1; i >= 0; i--)
    {
        printf("Vetor[%d] = %d\n", i+1, num[i]);
    } */

    int i, j, n, iMin, aux;
    printf("Quantos elementos? ");
    scanf("%d", &n);

    int vet[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    iMin = 0; // Considerar o 1o elemento menor
    for (i = 0; n; i++)
    {
        iMin = 1;
        for (j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[iMin])
            {
                iMin = j;
                if (i != iMin)
                {
                    aux = vet[i];
                    vet[i] = vet[iMin];
                    vet[iMin] = aux;
                }
            }
        }
    }
        return 0;
    }