#include "../include/jogo.h"
#include "../include/interface.h"
#include <stdio.h>

// Variáveis globais do jogo
static Carta cartaAtual;

void iniciarJogo(void)
{
    desenharCabecalho("Bem-vindo ao Super Trunfo!");
    inicializarCarta(&cartaAtual);
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