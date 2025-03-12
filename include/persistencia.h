/**
 * @file persistencia.h
 * @brief Funções para persistência de dados do Super Trunfo
 */

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "carta.h"

/**
 * @brief Salva uma carta em arquivo
 * @param carta Ponteiro para a carta a ser salva
 * @return 1 se sucesso, 0 se erro
 */
int salvarCarta(const Carta *carta);

/**
 * @brief Carrega uma carta do arquivo
 * @param carta Ponteiro para onde a carta será carregada
 * @return 1 se sucesso, 0 se erro
 */
int carregarCarta(Carta *carta);

/**
 * @brief Lista todas as cartas salvas
 * @return Número de cartas listadas
 */
int listarCartas(void);

#endif // PERSISTENCIA_H