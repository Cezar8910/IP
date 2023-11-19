#include <stdio.h>

int main()
{

    char fioA;
    char fioB;
    char fioC;
    char fioD;
    char fioE;
    char fioF;

    scanf("%c %c %c %c %c %c", &fioA, &fioB, &fioC, &fioD, &fioE, &fioF);

    // Para 4 fios conectados
    if ((fioA == 'x' && fioB == 'x') || (fioA == 'x' && fioC == 'x') || (fioA == 'x' && fioD == 'x') || (fioA == 'x' && fioE == 'x') || (fioA == 'x' && fioF == 'x') || (fioB == 'x' && fioC == 'x') || (fioB == 'x' && fioD == 'x') || (fioB == 'x' && fioE == 'x') || (fioB == 'x' && fioF == 'x') || (fioC == 'x' && fioD == 'x') || (fioC == 'x' && fioE == 'x') || (fioC == 'x' && fioF == 'x') || (fioD == 'x' && fioE == 'x') || (fioD == 'x' && fioF == 'x') || (fioE == 'x' && fioF == 'x'))
    {
        if (fioA != 'r' && fioB != 'r' && fioC != 'r' && fioD != 'r' && fioE != 'r' && fioF != 'r')
        {
            if (fioA == 'x' && fioB == 'x')
            {
                printf("corta d");
            }
            else if (fioA == 'x' && fioC == 'x')
            {
                printf("corta d");
            }
            else if (fioA == 'x' && fioD == 'x')
            {
                printf("corta c");
            }
            else if (fioA == 'x' && fioE == 'x')
            {
                printf("corta c");
            }
            else if (fioA == 'x' && fioF == 'x')
            {
                printf("corta c");
            }
            else if (fioB == 'x' && fioC == 'x')
            {
                printf("corta d");
            }
            else if (fioB == 'x' && fioD == 'x')
            {
                printf("corta c");
            }
            else if (fioB == 'x' && fioE == 'x')
            {
                printf("corta c");
            }
            else if (fioB == 'x' && fioF == 'x')
            {
                printf("corta c");
            }
            else if (fioC == 'x' && fioD == 'x')
            {
                printf("corta b");
            }
            else
            {
                printf("corta b");
            }
        }
        else if (fioA == 'x' && fioB == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioA == 'x' && fioC == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioA == 'x' && fioD == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioA == 'x' && fioE == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioB == 'x' && fioC == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioB == 'x' && fioD == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioB == 'x' && fioE == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioC == 'x' && fioD == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioC == 'x' && fioE == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioD == 'x' && fioE == 'x' && fioF == 'b')
        {
            printf("corta f");
        }
        else if (fioA == 'x' && fioF == 'x' && fioE == 'b')
        {
            printf("corta e");
        }
        else if (fioB == 'x' && fioF == 'x' && fioE == 'b')
        {
            printf("corta e");
        }
        else if (fioC == 'x' && fioF == 'x' && fioE == 'b')
        {
            printf("corta e");
        }
        else if (fioD == 'x' && fioF == 'x' && fioE == 'b')
        {
            printf("corta e");
        }
        else if (fioE == 'x' && fioF == 'x' && fioD == 'b')
        {
            printf("corta d");
        }
        else if (fioA != 'x')
        {
            printf("corta a");
        }
        else if (fioB != 'x')
        {
            printf("corta b");
        }
        else if (fioC != 'x')
        {
            printf("corta c");
        }
        else if (fioD != 'x')
        {
            printf("corta d");
        }
        else if (fioE != 'x')
        {
            printf("corta e");
        }
        else if (fioF != 'x')
        {
            printf("corta f");
        }
    }
    else if (fioA == 'x' || fioB == 'x' || fioC == 'x' || fioD == 'x' || fioE == 'x' || fioF == 'x') // Para 5 fios conectados
    {
        if (fioA == 'y' && fioB == 'y')
        {
            printf("corta a");
        }
        else if (fioA == 'y' && fioC == 'y' && fioB == 'x')
        {
            printf("corta a");
        }
        else if (fioB == 'y' && fioC == 'y' && fioA == 'x')
        {
            printf("corta b");
        }
        else if (fioA == 'x')
        {
            printf("corta c");
        }
        else if (fioB == 'x')
        {
            printf("corta c");
        }
        else if (fioC == 'x')
        {
            printf("corta b");
        }
        else
        {
            printf("corta b");
        }
    }
    else if (fioA != 'x' && fioB != 'x' && fioC != 'x' && fioD != 'x' && fioE != 'x' && fioF != 'x') // Para 6 fios conectados
    {
        if (fioA == 'g' && fioB != 'g' && fioC != 'g' && fioD != 'g' && fioE != 'g' && fioF != 'g')
        {
            printf("corta a");
        }
        else if (fioB == 'g' && fioA != 'g' && fioC != 'g' && fioD != 'g' && fioE != 'g' && fioF != 'g')
        {
            printf("corta b");
        }
        else if (fioC == 'g' && fioA != 'g' && fioB != 'g' && fioD != 'g' && fioE != 'g' && fioF != 'g')
        {
            printf("corta c");
        }
        else if (fioD == 'g' && fioA != 'g' && fioB != 'g' && fioC != 'g' && fioE != 'g' && fioF != 'g')
        {
            printf("corta d");
        }
        else if (fioE == 'g' && fioA != 'g' && fioB != 'g' && fioC != 'g' && fioD != 'g' && fioF != 'g')
        {
            printf("corta e");
        }
        else if (fioF == 'g' && fioA != 'g' && fioB != 'g' && fioC != 'g' && fioD != 'g' && fioE != 'g')
        {
            printf("corta f");
        }
        else
        {
            printf("corta e");
        }
    }
    return 0;
}
