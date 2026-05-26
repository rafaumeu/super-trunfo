/**
 * @file interface.h
 * @brief Funções de interface com o usuário do Super Trunfo
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include "carta.h"
#include "persistencia.h"
#include "ranking.h"

/**
 * @brief Limpa a tela do terminal
 */
void limparTela(void);

/**
 * @brief Exibe o menu principal do jogo
 */
void exibirMenu(void);

/**
 * @brief Exibe menu dinâmico para seleção de atributos
 * @param atributoExcluido Atributo que não deve aparecer no menu
 */
void exibirMenuDinamico(int atributoExcluido);

/**
 * @brief Realiza entrada de dados para uma carta
 * @param carta Ponteiro para a carta a ser preenchida
 * @param numeroCarta Número da carta (1 ou 2)
 */
void entradaDados(Carta *carta, int numeroCarta);

/**
 * @brief Mostra os dados de uma carta
 * @param carta Ponteiro para a carta a ser mostrada
 * @param numeroCarta Número da carta (1 ou 2)
 */
void mostrarCarta(Carta *carta, int numeroCarta);

/**
 * @brief Exibe o resultado da comparação entre cartas
 * @param resultado Número indicando o vencedor (1, 2 ou 0 para empate)
 * @param atributo Nome do atributo comparado
 */
void exibirResultado(int resultado, const char *atributo);

/**
 * @brief Exibe as instruções do jogo
 */
void exibirInstrucoes(void);

// Funções de interface com usuário
void pausar(void);
void exibirMensagemErro(const char *mensagem);
int lerOpcao(int min, int max);

// Funções de formatação
void desenharLinha(void);
void desenharCabecalho(const char *titulo);

// Adicionar a declaração movida de carta.h
void exibirCarta(const Carta *carta);

/**
 * @brief Exibe menu para alteração de idioma
 */
void alterarIdioma(void);

void exibirMenuCriterios(void);
CriterioRanking
selecionarCriterioRanking(void); // Retorna o critério selecionado
void criarCarta(void);
void exibirUltimaCarta(void);
void carregarUltimaCarta(void);

// Função auxiliar para limpar o buffer de entrada
static void limparBuffer(void);

void aguardarEnter(void);

#endif // INTERFACE_H