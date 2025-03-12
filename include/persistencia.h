/**
 * @file persistencia.h
 * @brief Funções para persistência de dados do Super Trunfo
 */

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "carta.h"

/**
 * @brief Salva uma carta no arquivo
 * @param carta Ponteiro para a carta a ser salva
 * @return 1 se sucesso, 0 se erro
 *
 * Validações:
 * - Verifica se há espaço suficiente em disco
 * - Verifica se o arquivo pode ser aberto para escrita
 * - Verifica se a operação de escrita foi bem sucedida
 */
int salvarCarta(const Carta *carta);

/**
 * @brief Carrega a última carta salva do arquivo
 * @param carta Ponteiro para onde a carta será carregada
 * @return 1 se sucesso, 0 se erro
 *
 * Validações:
 * - Verifica se o arquivo existe
 * - Verifica se o arquivo pode ser aberto para leitura
 * - Verifica se a operação de leitura foi bem sucedida
 */
int carregarCarta(Carta *carta);

/**
 * @brief Lista todas as cartas salvas no arquivo
 * @return Número de cartas listadas, 0 se erro
 *
 * Validações:
 * - Verifica se o arquivo existe
 * - Verifica se o arquivo pode ser aberto para leitura
 * - Verifica se as operações de leitura foram bem sucedidas
 */
int listarCartas(void);

#endif // PERSISTENCIA_H