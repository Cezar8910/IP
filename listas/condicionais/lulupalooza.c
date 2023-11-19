#include <stdio.h>

int main()
{

    int quantidadeAdultos;  // >= 1 && <= 10000
    int quantidadeCriancas; // >= 1 && <= 10000
    int maximoPessoasMesa;  // >= 1 && <=20

    scanf("%d %d %d", &quantidadeAdultos, &quantidadeCriancas, &maximoPessoasMesa);

    int adultosSobram = (quantidadeAdultos % maximoPessoasMesa);
    int criancasSobram = (quantidadeCriancas % maximoPessoasMesa);

    int adultosNaMesa = (quantidadeAdultos / maximoPessoasMesa);
    int criancasNaMesa = (quantidadeCriancas / maximoPessoasMesa);

    int valorAdultos = (3 * adultosNaMesa * maximoPessoasMesa);
    int valorCriancas = (2 * criancasNaMesa * maximoPessoasMesa);
    int mesaMista = 0;
    int valorMesaMista;

    int mesaAdultoMaisUm, mesaCriancaMaisUm;
    int valorAdultoMais, valorCriancaMais;
    if ((adultosSobram == 0) && (criancasSobram == 0))
    {
        printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
        printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
    }
    else if ((adultosSobram > 0) || (criancasSobram > 0))
    {
        if (adultosSobram + criancasSobram == maximoPessoasMesa)
        {
            mesaMista += 1;
            valorMesaMista = (2 * mesaMista * maximoPessoasMesa);
            printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
            printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
            printf("%d mesas mistas: R$%d\n", mesaMista, valorMesaMista);
        }
        else if ((adultosSobram % 2 == 0) && (criancasSobram % 2 == 0) && ((adultosSobram + criancasSobram) > maximoPessoasMesa))
        {
            mesaMista += 2;
            valorMesaMista = (2 * mesaMista * maximoPessoasMesa);
            printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
            printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
            printf("%d mesas mistas: R$%d\n", mesaMista, valorMesaMista);
        }
        else if ((adultosSobram % 2 == 0) && (criancasSobram % 2 == 0) && ((adultosSobram + criancasSobram) < maximoPessoasMesa))
        {
            mesaMista += 1;
            valorMesaMista = (2 * mesaMista * maximoPessoasMesa);
            printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
            printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
            printf("%d mesas mistas: R$%d\n", mesaMista, valorMesaMista);
        }
        else
        {
            if (adultosSobram < 4 && criancasSobram < 4)
            {
                mesaAdultoMaisUm = adultosSobram;
                adultosNaMesa = (quantidadeAdultos / maximoPessoasMesa) - mesaAdultoMaisUm;
                valorAdultoMais = 4 * (maximoPessoasMesa + 1) * mesaAdultoMaisUm;

                mesaCriancaMaisUm = criancasSobram;
                criancasNaMesa = (quantidadeCriancas / maximoPessoasMesa) - mesaCriancaMaisUm;
                valorCriancaMais = 3 * (maximoPessoasMesa + 1) * mesaCriancaMaisUm;

                valorAdultos = (3 * adultosNaMesa * maximoPessoasMesa);
                valorCriancas = (2 * criancasNaMesa * maximoPessoasMesa);

                printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
                printf("%d mesas com adultos+1: R$%d\n", adultosSobram, valorAdultoMais);
                printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
                printf("%d mesas com criancas+1: R$%d\n", criancasSobram, valorCriancaMais);
            }
            else if (adultosSobram < 4)
            {
                mesaAdultoMaisUm = adultosSobram;
                adultosNaMesa = (quantidadeAdultos / maximoPessoasMesa) - mesaAdultoMaisUm;
                valorAdultoMais = 4 * (maximoPessoasMesa + 1) * mesaAdultoMaisUm;

                valorAdultos = (3 * adultosNaMesa * maximoPessoasMesa);
                valorCriancas = (2 * criancasNaMesa * maximoPessoasMesa);

                printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
                printf("%d mesas com adultos+1: R$%d\n", adultosSobram, valorAdultoMais);
                printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
            }

            else if (criancasSobram < 4)
            {
                mesaCriancaMaisUm = criancasSobram;
                criancasNaMesa = (quantidadeCriancas / maximoPessoasMesa) - mesaCriancaMaisUm;
                valorCriancaMais = 3 * (maximoPessoasMesa + 1) * mesaCriancaMaisUm;

                printf("%d mesas com criancas+1: R$%d\n", criancasSobram, valorCriancaMais);
            }
            if (adultosSobram >= 4)
            {
                adultosNaMesa = (quantidadeAdultos / maximoPessoasMesa) + 1;
                valorAdultos = (3 * adultosNaMesa * maximoPessoasMesa);

                printf("%d mesas com adultos: R$%d\n", adultosNaMesa, valorAdultos);
            }
            if (criancasSobram >= 4)
            {

                criancasNaMesa = (quantidadeCriancas / maximoPessoasMesa) + 1;
                valorCriancas = (2 * criancasNaMesa * maximoPessoasMesa);

                printf("%d mesas com criancas: R$%d\n", criancasNaMesa, valorCriancas);
            }
        }

        return 0;
    }
}