#include <stdio.h>
#include <math.h>

int main() {
   float peso;
   float altura;
   int idade;
   char genero; 
   float tmb;
   
   printf("Digite o seu peso em kg: "); scanf("%f", &peso);
   printf("Digite a sua altura em cm: "); scanf("%f", &altura);
   printf("Digite a sua idade: "); scanf("%d", &idade);
   printf("Digite o seu gênero (M/F): "); scanf(" %c", &genero);

   if(genero == 77 || genero == 109){
       tmb = 66 + (13.7 * peso) + (5 * altura) - (6.8 * idade);
       printf("Quantidade de calorias que devem ser consumidas: %.2f\n", tmb);
   }else if(genero == 70 || genero == 102){
       tmb = 655 + (9.6 * peso) + (1.8 * altura) - (4.7 * idade);
       printf("Quantidade de calorias que devem ser consumidas: %.2f\n", tmb);
   }else{
       printf("Digite um gênero válido.");
   }

   
    return 0;
}