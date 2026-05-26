/**
 * @file persistencia.h
 * @brief Funções para persistência de dados do Super Trunfo
 */

#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "carta.h"
#include <stdbool.h>

/**
 * @brief Valida se há espaço em disco suficiente para salvar uma carta
 * @return true se houver espaço suficiente, false caso contrário
 */
bool validarEspacoDisco(void);

/**
 * @brief Valida se um arquivo existe e pode ser acessado
 * @param arquivo Nome do arquivo a ser validado
 * @return true se o arquivo existir e puder ser acessado, false caso contrário
 */
bool validarArquivo(const char *arquivo);

/**
 * @brief Salva uma carta no arquivo
 * @param carta Ponteiro para a carta a ser salva
 * @return true se a carta foi salva com sucesso, false caso contrário
 *
 * Validações:
 * - Verifica se há espaço suficiente em disco
 * - Verifica se o arquivo pode ser aberto para escrita
 * - Verifica se a operação de escrita foi bem sucedida
 */
bool salvarCarta(const Carta *carta);

/**
 * @brief Carrega a última carta salva do arquivo
 * @param carta Ponteiro para onde a carta será carregada
 * @return true se a carta foi carregada com sucesso, false caso contrário
 *
 * Validações:
 * - Verifica se o arquivo existe
 * - Verifica se o arquivo pode ser aberto para leitura
 * - Verifica se a operação de leitura foi bem sucedida
 */
bool carregarCarta(Carta *carta);

/**
 * @brief Lista todas as cartas salvas no arquivo
 * @return true se as cartas foram listadas com sucesso, false caso contrário
 *
 * Validações:
 * - Verifica se o arquivo existe
 * - Verifica se o arquivo pode ser aberto para leitura
 * - Verifica se as operações de leitura foram bem sucedidas
 */
bool listarCartas(void);

int carregarTodasCartas(Carta *cartas);

#endif // PERSISTENCIA_H