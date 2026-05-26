#include "../include/jogo.h"
#include "../include/interface.h"
#include <stdio.h>

// Variáveis globais do jogo
static Carta cartaJogador1;
static Carta cartaJogador2;

void iniciarJogo(void)
{
    desenharCabecalho("Bem-vindo ao Super Trunfo!");
    inicializarCarta(&cartaJogador1);
    inicializarCarta(&cartaJogador2);
}

void finalizarJogo(void)
{
    desenharCabecalho("Fim do Jogo");
    printf("Obrigado por jogar!\n");
    desenharLinha();
}

int compararPopulacao(const Carta *carta1, const Carta *carta2)
{
    if (carta1->populacao > carta2->populacao)
        return 1;
    if (carta1->populacao < carta2->populacao)
        return -1;
    return 0;
}

int compararArea(const Carta *carta1, const Carta *carta2)
{
    if (carta1->area > carta2->area)
        return 1;
    if (carta1->area < carta2->area)
        return -1;
    return 0;
}

int compararPIB(const Carta *carta1, const Carta *carta2)
{
    if (carta1->pib > carta2->pib)
        return 1;
    if (carta1->pib < carta2->pib)
        return -1;
    return 0;
}

int compararPontosTuristicos(const Carta *carta1, const Carta *carta2)
{
    if (carta1->pontosTuristicos > carta2->pontosTuristicos)
        return 1;
    if (carta1->pontosTuristicos < carta2->pontosTuristicos)
        return -1;
    return 0;
}

void compararCartas(void)
{
    desenharCabecalho("Comparação de Cartas");

    // Entrada das cartas
    printf("Dados da primeira carta:\n");
    lerDadosCarta(&cartaJogador1);

    printf("\nDados da segunda carta:\n");
    lerDadosCarta(&cartaJogador2);

    // Menu de atributos
    printf("\nEscolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");

    int atributo = lerOpcao(1, 4);
    if (atributo == -1)
        return;

    // Comparação
    float valor1 = obterValorAtributo(&cartaJogador1, atributo);
    float valor2 = obterValorAtributo(&cartaJogador2, atributo);
    const char *nomeAtributo = obterNomeAtributo(atributo);

    // Exibição dos resultados
    desenharCabecalho("Resultado da Comparação");
    printf("Carta 1 - %s: %.2f\n", nomeAtributo, valor1);
    printf("Carta 2 - %s: %.2f\n", nomeAtributo, valor2);
    desenharLinha();

    if (valor1 > valor2)
    {
        printf("Carta 1 venceu!\n");
    }
    else if (valor2 > valor1)
    {
        printf("Carta 2 venceu!\n");
    }
    else
    {
        printf("Empate!\n");
    }

    pausar();
}