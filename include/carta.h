/**
 * @file carta.h
 * @brief Definições e funções relacionadas às cartas do Super Trunfo
 */

#ifndef CARTA_H
#define CARTA_H

#include <stdbool.h>

/**
 * @brief Estrutura que representa uma carta do jogo
 */
typedef struct
{
    char codigo[4];       /**< Código único da carta (3 caracteres + \0) */
    char estado[3];       /**< Sigla do estado (2 caracteres + \0) */
    char cidade[51];      /**< Nome da cidade (50 caracteres + \0) */
    int populacao;        /**< População da cidade */
    float area;           /**< Área da cidade em km² */
    float pib;            /**< PIB da cidade em milhões */
    int pontosTuristicos; /**< Número de pontos turísticos */
} Carta;

/**
 * @brief Inicializa uma carta com valores padrão
 * @param carta Ponteiro para a carta a ser inicializada
 */
void inicializarCarta(Carta *carta);

/**
 * @brief Lê os dados de uma carta do usuário
 * @param carta Ponteiro para a carta a ser preenchida
 */
void lerDadosCarta(Carta *carta);

/**
 * @brief Exibe os dados de uma carta na tela
 * @param carta Ponteiro para a carta a ser exibida
 */
void exibirCarta(const Carta *carta);

/**
 * @brief Calcula e exibe indicadores da carta
 * @param carta Ponteiro para a carta
 *
 * Indicadores calculados:
 * - Densidade populacional (hab/km²)
 * - PIB per capita (R$)
 */
void calcularIndicadores(Carta *carta);

/**
 * @brief Calcula o super poder de uma carta
 * @param carta Ponteiro para a carta
 * @return Valor do super poder
 */
float calcularSuperPoder(const Carta *carta);

/**
 * @brief Obtém o valor de um atributo específico da carta
 * @param carta Ponteiro para a carta
 * @param atributo Número do atributo (1-4)
 * @return Valor do atributo como float
 */
float obterValorAtributo(const Carta *carta, int atributo);

/**
 * @brief Obtém o nome de um atributo específico
 * @param atributo Número do atributo (1-4)
 * @return Nome do atributo
 */
const char *obterNomeAtributo(int atributo);

/**
 * @brief Valida o código da carta
 * @param codigo Código a ser validado
 * @return true se o código é válido, false caso contrário
 */
bool validarCodigo(const char *codigo);

/**
 * @brief Valida o estado da carta
 * @param estado Estado a ser validado
 * @return true se o estado é válido, false caso contrário
 */
bool validarEstado(const char *estado);

/**
 * @brief Valida o nome da cidade
 * @param cidade Nome da cidade a ser validado
 * @return true se o nome é válido, false caso contrário
 */
bool validarCidade(const char *cidade);

/**
 * @brief Valida um valor numérico
 * @param valor Valor a ser validado
 * @return true se o valor é válido, false caso contrário
 */
bool validarValorNumerico(float valor);

#endif // CARTA_H