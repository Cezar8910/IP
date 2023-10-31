#include <stdio.h>
#define media(notas) ((nota1 + nota2 + nota3)/3)

int main() {
    float nota1, nota2, nota3;

    printf("Digite a nota 1: ", nota1); scanf("%f", &nota1);
    printf("Digite a nota 2: ", nota2); scanf("%f", &nota2);
    printf("Digite a nota 3: ", nota3); scanf("%f", &nota3);

    if(nota1, nota2, nota3 >= 0 && nota1, nota2, nota3 <= 10){
        if(media(notas) >= 7) {
            printf("Aprovado por média.");
        } else if(media(notas) >=3 && media(notas) < 7) {
            printf("Continue estudando, a final será em breve!");
        }else {
            printf("Reprovado.");
        }
    } else {
        printf("Nota inválida!");
    }



    return 0;
}