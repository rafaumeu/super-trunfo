#include "../include/carta.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>

void inicializarCarta(Carta *carta) { memset(carta, 0, sizeof(Carta)); }

void lerDadosCarta(Carta *carta)
{
    desenharCabecalho("Cadastro de Carta");

    printf("Digite o código (ex: A1): ");
    scanf("%3s", carta->codigo);

    printf("Digite o estado (ex: SP): ");
    scanf("%2s", carta->estado);

    printf("Digite a cidade: ");
    getchar(); // Limpar o buffer
    fgets(carta->cidade, sizeof(carta->cidade), stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área: ");
    scanf("%f", &carta->area);

    printf("Digite o PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirCarta(const Carta *carta)
{
    desenharCabecalho("Dados da Carta");
    printf("Código: %s\n", carta->codigo);
    printf("Estado: %s\n", carta->estado);
    printf("Cidade: %s\n", carta->cidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
    desenharLinha();
}