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
    RANKING_POPULACAO,
    RANKING_AREA,
    RANKING_PIB,
    RANKING_PONTOS_TURISTICOS,
    RANKING_DENSIDADE,
    RANKING_PIB_PER_CAPITA,
    RANKING_SUPER_PODER
} CriterioRanking;

/**
 * @brief Exibe o ranking das cartas por um critério específico
 * @param criterio Critério de ordenação
 * @return Número de cartas exibidas
 */
int exibirRanking(CriterioRanking criterio);

/**
 * @brief Exibe o menu de seleção de critério para ranking
 * @return Critério selecionado
 */
CriterioRanking selecionarCriterioRanking(void);

#endif // RANKING_H