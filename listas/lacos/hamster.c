#include <stdio.h>

int main()
{
    int r1, div1, r2, div2, r3, div3;

    scanf("%d %d", &r1, &div1);
    scanf("%d %d", &r2, &div2);
    scanf("%d %d", &r3, &div3);

    int x = 0;
    int entrou = 0;

    while (entrou == 0)
    {
        if ((x - r1) % div1 == 0 && (x - r2) % div2 == 0 && (x - r3) % div3 == 0)
        {
            printf("%d", x);
            entrou = 1;
        }
        x++;
    }

    return 0;
}
