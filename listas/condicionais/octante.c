#include <stdio.h>
// Dado que: -100 < x, y, z < 100 e x != y != z.
int main()
{
    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);
    // caso x = 1, y = 2, z = 3
    if (x > 0 && y > 0 && z > 0) // Octante 1
    {

        if (x < y && x < z)
        {
            printf("2");
        }
        else if (y < x && y < z)
        {
            printf("4");
        }
        else if (z < x && z < y)
        {
            printf("5");
        }
    }
    else if (x < 0 && y < 0 && z < 0) // Octante 7
    {
        x *= -1;
        y *= -1;
        z *= -1;

        if (x < y && x < z)
        {
            printf("8");
        }
        else if (y < x && y < z)
        {
            printf("6");
        }
        else if (z < x && z < y)
        {
            printf("3");
        }

        return 0;
    }
    else if (x < 0 && y < 0 && z > 0) // Octante 3
    {
        x *= -1;
        y *= -1;
        if (x < y && x < z) 
        {
            printf("4");
        }
        else if (y < x && y < z) 
        {
            printf("2");
        }
        else if (z < x && z < y)
        {
            printf("7");
        }
    }
    else if (x < 0 && y > 0 && z < 0) // Octante 6
    {
        x *= -1;
        z *= -1;
        if (x < y && x < z) 
        {
            printf("5");
        }
        else if (y < x && y < z) 
        {
            printf("7");
        }
        else if (z < x && z < y)
        {
            printf("2");
        }
    }
    else if (x < 0 && y > 0 && z > 0) // Octante 2
    {
        x *= -1;
        if (x < y && x < z)
        {
            printf("1");
        }
        else if (y < x && y < z)
        {
            printf("3");
        }
        else if (z < x && z < y)
        {
            printf("6");
        }
    }
    else if (x > 0 && y < 0 && z < 0) // Octante 8
    {
        y *= -1;
        z *= -1;
        if (x < y && x < z)
        {
            printf("7");
        }
        else if (y < x && y < z)
        {
            printf("5");
        }
        else if (z < x && z < y)
        {
            printf("4");
        }
    }
    else if (x > 0 && y < 0 && z > 0) // Octante 4
    {
        y *= -1;
        if (x < y && x < z)
        {
            printf("3");
        }
        else if (y < x && y < z)
        {
            printf("1");
        }
        else if (z < x && z < y)
        {
            printf("8");
        }
    }
    else if (x > 0 && y > 0 && z < 0) // Octante 5
    {
        z *= -1;
        if (x < y && x < z)
        {
            printf("6");
        }
        else if (y < x && y < z)
        {
            printf("8");
        }
        else if (z < x && z < y)
        {
            printf("1");
        }
    }
}
