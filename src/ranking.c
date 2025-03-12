#include "../include/ranking.h"
#include "../include/constantes.h"
#include "../include/i18n.h"
#include "../include/interface.h"
#include "../include/persistencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar uma carta com seu valor de ranking
typedef struct
{
    Carta carta;
    float valor;
} CartaRanking;

int exibirRanking(CriterioRanking criterio)
{
    Carta cartas[MAX_CARTAS];
    int numCartas = carregarTodasCartas(cartas);

    if (numCartas <= 0)
    {
        return 0;
    }

    MessageId msgId;
    switch (criterio)
    {
    case CRITERIO_POPULACAO:
        msgId = MSG_RANKING_POPULATION;
        break;
    case CRITERIO_AREA:
        msgId = MSG_RANKING_AREA;
        break;
    case CRITERIO_PIB:
        msgId = MSG_RANKING_GDP;
        break;
    case CRITERIO_PONTOS_TURISTICOS:
        msgId = MSG_RANKING_TOURIST;
        break;
    case CRITERIO_DENSIDADE:
        msgId = MSG_RANKING_DENSITY;
        break;
    case CRITERIO_PIB_PER_CAPITA:
        msgId = MSG_RANKING_GDP_CAPITA;
        break;
    case CRITERIO_SUPER_PODER:
        msgId = MSG_RANKING_POWER;
        break;
    default:
        return 0;
    }

    limparTela();
    printf("\n=== %s %s ===\n", getMessage(MSG_RANKING_BY), getMessage(msgId));

    // Ordenar cartas pelo critério selecionado
    for (int i = 0; i < numCartas - 1; i++)
    {
        for (int j = 0; j < numCartas - i - 1; j++)
        {
            float valor1 = 0, valor2 = 0;

            switch (criterio)
            {
            case CRITERIO_POPULACAO:
                valor1 = cartas[j].populacao;
                valor2 = cartas[j + 1].populacao;
                break;
            case CRITERIO_AREA:
                valor1 = cartas[j].area;
                valor2 = cartas[j + 1].area;
                break;
            case CRITERIO_PIB:
                valor1 = cartas[j].pib;
                valor2 = cartas[j + 1].pib;
                break;
            case CRITERIO_PONTOS_TURISTICOS:
                valor1 = cartas[j].pontosTuristicos;
                valor2 = cartas[j + 1].pontosTuristicos;
                break;
            case CRITERIO_DENSIDADE:
                valor1 = cartas[j].populacao / cartas[j].area;
                valor2 = cartas[j + 1].populacao / cartas[j + 1].area;
                break;
            case CRITERIO_PIB_PER_CAPITA:
                valor1 = cartas[j].pib / cartas[j].populacao;
                valor2 = cartas[j + 1].pib / cartas[j + 1].populacao;
                break;
            case CRITERIO_SUPER_PODER:
                valor1 = (cartas[j].populacao * cartas[j].pib) / cartas[j].area;
                valor2 = (cartas[j + 1].populacao * cartas[j + 1].pib) /
                         cartas[j + 1].area;
                break;
            }

            if (valor1 < valor2)
            {
                Carta temp = cartas[j];
                cartas[j] = cartas[j + 1];
                cartas[j + 1] = temp;
            }
        }
    }

    // Exibir ranking
    for (int i = 0; i < numCartas; i++)
    {
        float valor = 0;
        switch (criterio)
        {
        case CRITERIO_DENSIDADE:
            valor = cartas[i].populacao / cartas[i].area;
            break;
        case CRITERIO_PIB_PER_CAPITA:
            valor = cartas[i].pib / cartas[i].populacao;
            break;
        case CRITERIO_SUPER_PODER:
            valor = (cartas[i].populacao * cartas[i].pib) / cartas[i].area;
            break;
        case CRITERIO_POPULACAO:
            valor = cartas[i].populacao;
            break;
        case CRITERIO_PONTOS_TURISTICOS:
            valor = cartas[i].pontosTuristicos;
            break;
        case CRITERIO_AREA:
            valor = cartas[i].area;
            break;
        case CRITERIO_PIB:
            valor = cartas[i].pib;
            break;
        }
        printf("%d. %s (%s): %.2f\n", i + 1, cartas[i].cidade, cartas[i].estado,
               valor);
    }

    // Não chama aguardarEnter() aqui, deixa o controle para a função chamadora
    return 1;
}

int carregarTodasCartas(Carta *cartas)
{
    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        return 0;
    }

    int numCartas = 0;
    while (numCartas < MAX_CARTAS &&
           fread(&cartas[numCartas], sizeof(Carta), 1, arquivo) == 1)
    {
        numCartas++;
    }

    fclose(arquivo);
    return numCartas;
}

void ordenarCartas(Carta *cartas, int numCartas, CriterioRanking criterio)
{
    for (int i = 0; i < numCartas - 1; i++)
    {
        for (int j = 0; j < numCartas - i - 1; j++)
        {
            float valor1 = obterValorCriterio(&cartas[j], criterio);
            float valor2 = obterValorCriterio(&cartas[j + 1], criterio);

            if (valor1 < valor2)
            {
                Carta temp = cartas[j];
                cartas[j] = cartas[j + 1];
                cartas[j + 1] = temp;
            }
        }
    }
}

float obterValorCriterio(const Carta *carta, CriterioRanking criterio)
{
    switch (criterio)
    {
    case CRITERIO_POPULACAO:
        return (float)carta->populacao;
    case CRITERIO_AREA:
        return carta->area;
    case CRITERIO_PIB:
        return carta->pib;
    case CRITERIO_PONTOS_TURISTICOS:
        return (float)carta->pontosTuristicos;
    case CRITERIO_DENSIDADE:
        return carta->populacao / carta->area;
    case CRITERIO_PIB_PER_CAPITA:
        return (carta->pib * 1000000.0f) / carta->populacao;
    case CRITERIO_SUPER_PODER:
        return calcularSuperPoder(carta);
    default:
        return 0.0f;
    }
}