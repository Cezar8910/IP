#include <stdio.h>

int main()
{

    //(0 <= X < 24 && 0 <= Y < 24 && X < Y
    float horaSaida;  // x
    float horaVolta;  // y
    char campus;      // A - CAC, B - CCSA
    int quantPessoas; // n

    scanf("%f %f %c %d", &horaSaida, &horaVolta, &campus, &quantPessoas);

    if ((horaSaida < horaVolta) && (horaSaida >= 0) && (horaSaida < 24) && (horaVolta >= 0) && (horaVolta < 24) && (quantPessoas <= 9) && ((campus == 'A') || (campus == 'B')))
    {
        if (campus == 'A' && (horaVolta - horaSaida) > 1)
        {
            if ((horaVolta - horaSaida) >= 1.5)
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else if (quantPessoas <= 5)
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else if (quantPessoas > 5)
            {
                printf("Infelizmente o uninho nao tanka, rodamos!\n");
            }
        }
        else if (campus == 'A' && (horaVolta - horaSaida) <= 1)
        {
            printf("Infelizmente o uninho nao tanka, rodamos!\n");
        }
        if (campus == 'B' && (horaVolta - horaSaida) > 0.75)
        {
            if ((horaVolta - horaSaida) >= 1.12)
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else if (quantPessoas <= 5)
            {
                printf("O uninho faz a boa, obrigado querida mae line\n");
            }
            else if (quantPessoas > 5)
            {
                printf("Infelizmente o uninho nao tanka, rodamos!\n");
            }
        }
        else if (campus == 'B' && (horaVolta - horaSaida) <= 0.75)
        {
            printf("Infelizmente o uninho nao tanka, rodamos!\n");
        }
    }
    else
    {
        printf("Entrada Invalida\n");
    }

    return 0;
}