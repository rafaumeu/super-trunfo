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
    printf("\n=== Super Trunfo - Países - Cartas %d ===\n", numCarta);
    printf("| Código: %s                       \n", carta->codigo);
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o código (ex: A1):      ");
    scanf("%s", carta->codigo);
    printf("│ Código: %s                      \n", carta->codigo);
    printf("└─────────────────────────────────┘\n");
    printf("| População: %d                    \n", carta->populacao);
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a população:            ");
    scanf("%d", &carta->populacao);
    printf("│ População: %d                  \n", carta->populacao);
    printf("└─────────────────────────────────┘\n");
    printf("| Área: %.2f                      \n", carta->area);
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a área:                 ");
    scanf("%f", &carta->area);
    printf("│ Área: %.2f                    \n", carta->area);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| PIB: %.2f                       \n", carta->pib);
    printf("| Pontos Turísticos: %d            \n", carta->pontosTuristicos);
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o código (ex: A1):      ");
    scanf("%s", carta->codigo);
    printf("│ Código: %s                      \n", carta->codigo);
    printf("└─────────────────────────────────┘\n");
    printf("│ Pontos Turísticos: %d           \n", carta->pontosTuristicos);
    printf("┌──────────────────────────────────┐\n");
    printf("│ Digite os pontos turísticos:   ");
    scanf("%d", &carta->pontosTuristicos);
    printf("│ Pontos Turísticos: %d           \n", carta->pontosTuristicos);
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
    printf("┌─────────────────────────────────┐\n");
    printf("| POPULAÇÃO                        \n");
    printf("| Carta 1: %d                      \n", carta1.populacao);
    printf("| Carta 2: %d                      \n", carta2.populacao);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("| Area                             \n");
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
