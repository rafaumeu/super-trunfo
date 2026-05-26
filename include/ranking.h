/**
 * @file ranking.h
 * @brief Funções para gerenciamento do ranking de cartas do Super Trunfo
 */

#ifndef RANKING_H
#define RANKING_H

#include "carta.h"

/**
 * @brief Critérios de ordenação para o ranking
 */
typedef enum
{
    CRITERIO_POPULACAO,
    CRITERIO_AREA,
    CRITERIO_PIB,
    CRITERIO_PONTOS_TURISTICOS,
    CRITERIO_DENSIDADE,
    CRITERIO_PIB_PER_CAPITA,
    CRITERIO_SUPER_PODER
} CriterioRanking;

#define NUM_CRITERIOS 7
#define MAX_CARTAS 100

/**
 * @brief Exibe o ranking das cartas por um critério específico
 * @param criterio Critério de ordenação
 * @return Número de cartas exibidas
 */
int exibirRanking(CriterioRanking criterio);

void ordenarCartas(Carta *cartas, int numCartas, CriterioRanking criterio);
float obterValorCriterio(const Carta *carta, CriterioRanking criterio);
int carregarTodasCartas(Carta *cartas);

/**
 * @brief Obtém o nome do critério de ranking
 * @param criterio Critério de ranking
 * @return Nome do critério
 */
const char *obterNomeCriterio(CriterioRanking criterio);

#endif // RANKING_H