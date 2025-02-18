#include <stdio.h>

char codigo[4];
int populacao;
float area;
float pib;
int pontosTuristicos;

void entradaDados()
{
    printf("\n=== Super Trunfo - Países ===\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o código (ex: A1):      ");
    scanf("%s", codigo);
    printf("│ Código: %s                      │\n", codigo);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a população:            ");
    scanf("%d", &populacao);
    printf("│ População: %d                   │\n", populacao);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a área:                 ");
    scanf("%f", &area);
    printf("│ Área: %.2f                      │\n", area);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o PIB:                  ");
    scanf("%f", &pib);
    printf("│ PIB: %.2f                       │\n", pib);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite os pontos turísticos:   ");
    scanf("%d", &pontosTuristicos);
    printf("│ Pontos Turísticos: %d           │\n", pontosTuristicos);
    printf("└─────────────────────────────────┘\n");
}

void mostrarCarta()
{
    printf("\n┌─────────────────────────────────┐\n");
    printf("│ CARTA CADASTRADA                │\n");
    printf("│ Código: %s                      │\n", codigo);
    printf("│ População: %d                   │\n", populacao);
    printf("│ Área: %.2f                      │\n", area);
    printf("│ PIB: %.2f                       │\n", pib);
    printf("│ Pontos Turísticos: %d           │\n", pontosTuristicos);
    printf("└─────────────────────────────────┘\n");
}

int main()
{
    entradaDados();
    mostrarCarta();
    return 0;
}
