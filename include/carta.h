/**
 * @file carta.h
 * @brief Definições e funções relacionadas às cartas do Super Trunfo
 */

#ifndef CARTA_H
#define CARTA_H

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
 * @brief Lê os dados de uma carta do usuário com validações
 * @param carta Ponteiro para a carta a ser preenchida
 *
 * Validações:
 * - Código: 3 caracteres alfanuméricos
 * - Estado: 2 letras maiúsculas
 * - Cidade: Nome não vazio, máximo 50 caracteres, começa com letra
 * - Valores numéricos: Devem ser maiores que zero
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
 * @brief Calcula o super poder da carta
 * @param carta Ponteiro para a carta
 * @return Valor do super poder
 *
 * O super poder é calculado como uma média ponderada dos atributos
 * normalizados:
 * - População (30%): dividida por 1 milhão
 * - Área (20%): dividida por 1000 km²
 * - PIB (30%): dividido por 1 bilhão
 * - Pontos turísticos (20%): dividido por 10
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

#endif // CARTA_H