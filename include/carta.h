/**
 * @file carta.h
 * @brief Definições e funções relacionadas às cartas do Super Trunfo
 */

#ifndef CARTA_H
#define CARTA_H

// Estrutura básica de uma carta
typedef struct
{
    char codigo[4];       // Código da carta (ex: A1)
    char estado[3];       // Sigla do estado (ex: SP)
    char cidade[50];      // Nome da cidade
    int populacao;        // População da cidade
    float area;           // Área da cidade
    float pib;            // PIB da cidade
    int pontosTuristicos; // Quantidade de pontos turísticos
} Carta;

// Funções básicas para manipulação de cartas
void inicializarCarta(Carta *carta);
void lerDadosCarta(Carta *carta);
void exibirCarta(const Carta *carta);

/**
 * @brief Calcula indicadores derivados da carta
 * @param carta Ponteiro para a carta a ser calculada
 */
void calcularIndicadores(Carta *carta);

/**
 * @brief Calcula o super poder da carta
 * @param carta Ponteiro para a carta
 * @return Valor do super poder calculado
 */
float calcularSuperPoder(Carta *carta);

/**
 * @brief Obtém o valor de um atributo específico da carta
 * @param carta Ponteiro para a carta
 * @param atributo Número do atributo (1-7)
 * @return Valor do atributo
 */
float obterValorAtributo(Carta *carta, int atributo);

/**
 * @brief Obtém o nome de um atributo
 * @param atributo Número do atributo (1-7)
 * @return Nome do atributo
 */
const char *obterNomeAtributo(int atributo);

#endif // CARTA_H