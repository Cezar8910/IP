#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    float delta;
    float x1, x2;
    
    printf("Digite o valor de a: "); scanf("%f", &a);
    printf("Digite o valor de b: "); scanf("%f", &b);
    printf("Digite o valor de c: "); scanf("%f", &c);


    if(a == 0){
        printf("Se a é igual a 0 então não se trata de uma expressão do 2° grau.");
    } else{
        delta = (b*b) - 4 * a * c;
        if(delta > 0){
        x1 = (-b + sqrt(delta))/ (2*a);
        x2 = (-b - sqrt(delta))/ (2*a);
        printf("As raízes são:\n x1: %.2f\n x2: %.2f\n", x1, x2);
        }
        else if(delta == 0){
            x1 = -b / 2*a;
            printf("A raíz é: %f\n", x1);
        }else if(delta < 0){
            printf("A equação não possui raízes reais.\n");
        }
    }
    return 0;
}