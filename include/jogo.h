/**
 * @file jogo.h
 * @brief Funções principais do jogo Super Trunfo
 */

#ifndef JOGO_H
#define JOGO_H

#include "carta.h"

// Constantes para normalização
#define POPULACAO_NORMALIZER 1000000.0
#define DENSIDADE_NORMALIZER 100.0
#define AREA_NORMALIZER 1000.0
#define PIB_NORMALIZER 1000000.0

// Pesos para cálculo do super poder
#define PESO_POPULACAO 3
#define PESO_AREA 2
#define PESO_PIB 3
#define PESO_PONTOS_TURISTICOS 2
#define PESO_DENSIDADE_INVERSA 2

// Funções básicas do jogo
void iniciarJogo(void);
void finalizarJogo(void);

// Funções de comparação
int compararPopulacao(const Carta *carta1, const Carta *carta2);
int compararArea(const Carta *carta1, const Carta *carta2);
int compararPIB(const Carta *carta1, const Carta *carta2);
int compararPontosTuristicos(const Carta *carta1, const Carta *carta2);

/**
 * @brief Compara duas cartas com base em um atributo
 * @param atributo Número do atributo a ser comparado
 * @param carta1 Primeira carta
 * @param carta2 Segunda carta
 * @return 1 se carta1 vence, 2 se carta2 vence, 0 se empate
 */
int compararAtributo(int atributo, Carta *carta1, Carta *carta2);

/**
 * @brief Realiza uma rodada de comparação entre cartas
 */
void compararCartas(void);

/**
 * @brief Realiza uma comparação multi-atributo entre cartas
 */
void compararMultiAtributo(void);

/**
 * @brief Inicializa o jogo
 * @return 0 se sucesso, diferente de 0 se erro
 */
int inicializarJogo(void);

#endif // JOGO_H