#include <stdio.h>
#include <stdlib.h>

struct Carta
{
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void lerCarta(struct Carta *carta, char estado, int cidade)
{
    sprintf(carta->codigo, "%c%02d", estado, cidade);
    printf("\nDigite os dados da carta %s:\n", carta->codigo);
    printf("\nEstado %c, Cidade %d\n", estado, cidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área: ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Número de pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void mostrarCarta(struct Carta carta)
{
    printf("\n=== Carta %s ===\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB:  %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("=================\n");
}

int main()
{
    struct Carta cartas[32];
    int numCartas = 0;
    char continuar;

    printf("=== Super Trunfo - Países ===\n");

    for (char estado = 'A'; estado <= 'H' && numCartas < 32; estado++)
    {
        for (int cidade = 1; cidade <= 4 && numCartas < 32; cidade++)
        {

            sprintf(cartas[numCartas].codigo, "%c%02d", 'A' + (numCartas / 4), (numCartas % 4) + 1);
            lerCarta(&cartas[numCartas], estado, cidade);
            mostrarCarta(cartas[numCartas]);
            numCartas++;
            if (numCartas < 32)
            {
                printf("\nDeseja continuar cadastrando? (S/n): ");
                scanf(" %c", &continuar);
                if (continuar != 'S' && continuar != 's')
                {
                    break;
                }
            }
        }
        if (continuar != 'S' && continuar != 's')
        {
            break;
        }
    }

    printf("\nTotal de cartas cadastradas: %d\n", numCartas);
    return 0;
}
