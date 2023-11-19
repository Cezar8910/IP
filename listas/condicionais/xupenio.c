#include <stdio.h>

int main()
{

    int limiteVelo;
    float distAcad;
    float carroA;
    float carroB;
    float carroC;

    scanf("%d %f", &limiteVelo, &distAcad);
    scanf("%f", &carroA);
    scanf("%f", &carroB);
    scanf("%f", &carroC);

    float velocidadeA = distAcad / carroA;
    float velocidadeC = distAcad / carroC;
    float velocidadeB = distAcad / carroB;
    float veloMin = limiteVelo / 2;

    if (velocidadeA <= limiteVelo && velocidadeA >= veloMin)
    {
        printf("Xupenio pode utilizar o carro Kwid Laranja, cuja velocidade no percurso eh %.2f\n", velocidadeA);
    }
    if (velocidadeC <= limiteVelo && velocidadeC >= veloMin)
    {
        printf("Xupenio pode utilizar o carro Gol Bolinha, cuja velocidade no percurso eh %.2f\n", velocidadeC);
    }
    if (velocidadeB <= limiteVelo && velocidadeB >= veloMin)
    {
        printf("Xupenio pode utilizar o carro Tesla Branco, cuja velocidade no percurso eh %.2f\n", velocidadeB);
    }
    if (!(velocidadeA >= veloMin && velocidadeA <= limiteVelo) &&
        !(velocidadeB >= veloMin && velocidadeB <= limiteVelo) &&
        !(velocidadeC >= veloMin && velocidadeC <= limiteVelo))
    {
        printf("Infelizmente Xupenio nao podera ir ao evento mais importante do ano\n");
    }
    return 0;
}
