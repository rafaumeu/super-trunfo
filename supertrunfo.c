#include <stdio.h>
typedef struct
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

Carta carta1, carta2;
void entradaDados(int numCarta)
{
    Carta *carta = numCarta == 1 ? &carta1 : &carta2;
    printf("\n=== Super Trunfo - Países - Carta %d ===\n", numCarta);
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite o código (ex: A1):          ");
    scanf("%s", carta->codigo);
    printf("│ Código: %s                        \n", carta->codigo);
    printf("└──────────────────────────────────┘\n");
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite a população:                 ");
    scanf("%d", &carta->populacao);
    printf("│ População: %d                     \n", carta->populacao);
    printf("└──────────────────────────────────┘\n");
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite a área:                 ");
    scanf("%f", &carta->area);
    printf("│ Área: %.2f                        \n", carta->area);
    printf("└──────────────────────────────────┘\n");
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite o PIB:                       ");
    scanf("%f", &carta->pib);
    printf("│ PIB: %.2f US$                     \n", carta->pib);
    printf("└──────────────────────────────────┘\n");
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite os pontos turísticos:        ");
    scanf("%d", &carta->pontosTuristicos);
    printf("│ Pontos Turísticos: %d              \n", carta->pontosTuristicos);
    printf("└──────────────────────────────────┘\n");
}

void mostrarCarta(int numCarta)
{
    Carta *carta = numCarta == 1 ? &carta1 : &carta2;
    printf("\n┌───────────────────────────────────┐\n");
    printf("│ CARTA CADASTRADA                  \n");
    printf("│ Código: %s                        \n", carta->codigo);
    printf("│ População: %d                    \n", carta->populacao);
    printf("│ Área: %.2f                      \n", carta->area);
    printf("│ PIB: %.2f                       \n", carta->pib);
    printf("│ Pontos Turísticos: %d            \n", carta->pontosTuristicos);
    printf("└───────────────────────────────────┘\n");
}
void calcularDensidadePopulacional(int numCarta)
{
    Carta *carta = numCarta == 1 ? &carta1 : &carta2;
    float densidade = carta->populacao / carta->area;
    printf("\n┌─────────────────────────────────┐\n");
    printf("| DENSIDADE POPULACIONAL          \n");
    printf("| %.2f hab/km²                    \n", densidade);
    printf("└─────────────────────────────────┘\n");
}

void calcularPIBperCapita(int numCarta)
{
    Carta *carta = numCarta == 1 ? &carta1 : &carta2;
    float pibPerCapita = carta->pib / carta->populacao;
    printf("\n┌─────────────────────────────────┐\n");
    printf("| PIB PER CAPITA                  \n");
    printf("| %.2f US$                        \n", pibPerCapita);
    printf("└─────────────────────────────────┘\n");
}
void compararCartas()
{
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    float superPoder1 = calcularSuperPoder(1);
    float superPoder2 = calcularSuperPoder(2);

    printf("┌─────────────────────────────────┐\n");
    printf("| POPULAÇÃO                        \n");
    printf("| Carta 1: %d                      \n", carta1.populacao);
    printf("| Carta 2: %d                      \n", carta2.populacao);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| Área                             \n");
    printf("| Carta 1: %.2f                    \n", carta1.area);
    printf("| Carta 2: %.2f                    \n", carta2.area);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| PIB                              \n");
    printf("| Carta 1: %.2f US$                \n", carta1.pib);
    printf("| Carta 2: %.2f US$                \n", carta2.pib);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| PONTOS TURÍSTICOS                  \n");
    printf("| Carta 1: %d                      \n", carta1.pontosTuristicos);
    printf("| Carta 2: %d                      \n", carta2.pontosTuristicos);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| SUPER PODER                      \n");
    printf("| Carta 1: %.2f                    \n", superPoder1);
    printf("| Carta 2: %.2f                    \n", superPoder2);
    if (superPoder1 > superPoder2)
    {
        printf("| VENCEDOR: Carta 1!        \n");
    }
    else if (superPoder2 > superPoder1)
    {
        printf("| VENCEDOR: Carta 2!        \n");
    }
    else
    {
        printf("| EMPATE!        \n");
    }
    printf("└─────────────────────────────────┘\n");
}
float calcularSuperPoder(int numCarta)
{
    Carta *carta = numCarta == 1 ? &carta1 : &carta2;
    float superPoder =
        ((carta->populacao / 1000000.0) * 3) + ((carta->area / 1000.0) * 2) +
        ((carta->pib / 1000000.0) * 3) + (carta->pontosTuristicos * 2);
    printf("┌─────────────────────────────────┐\n");
    printf("| SUPER PODER                      \n");
    printf("| Carta %d %.2f                            \n", numCarta,
           superPoder);
    printf("└─────────────────────────────────┘\n");
    return superPoder;
}
int main()
{
    entradaDados(1);
    entradaDados(2);
    mostrarCarta(1);
    calcularDensidadePopulacional(1);
    calcularPIBperCapita(1);
    mostrarCarta(2);
    calcularDensidadePopulacional(2);
    calcularPIBperCapita(2);
    compararCartas();
    return 0;
}
