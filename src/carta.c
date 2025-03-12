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

void calcularIndicadores(Carta *carta)
{
    // Para o nível beginner, vamos apenas exibir algumas classificações básicas
    float densidadePopulacional = carta->populacao / carta->area;
    float pibPerCapita = carta->pib / carta->populacao;

    printf("\nIndicadores calculados:\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita);
}

float calcularSuperPoder(Carta *carta)
{
    // Para o nível beginner, vamos usar uma fórmula simples
    float superPoder = (carta->populacao / 1000000.0f) + // População em milhões
                       (carta->area / 1000.0f) +   // Área em milhares de km²
                       (carta->pib / 1000000.0f) + // PIB em milhões
                       (float)carta->pontosTuristicos; // Pontos turísticos

    return superPoder;
}

float obterValorAtributo(Carta *carta, int atributo)
{
    switch (atributo)
    {
    case 1:
        return (float)carta->populacao;
    case 2:
        return carta->area;
    case 3:
        return carta->pib;
    case 4:
        return (float)carta->pontosTuristicos;
    case 5:
        return carta->populacao / carta->area; // Densidade populacional
    case 6:
        return carta->pib / carta->populacao; // PIB per capita
    case 7:
        return calcularSuperPoder(carta);
    default:
        return 0.0f;
    }
}

const char *obterNomeAtributo(int atributo)
{
    switch (atributo)
    {
    case 1:
        return "População";
    case 2:
        return "Área";
    case 3:
        return "PIB";
    case 4:
        return "Pontos Turísticos";
    case 5:
        return "Densidade Populacional";
    case 6:
        return "PIB per capita";
    case 7:
        return "Super Poder";
    default:
        return "Desconhecido";
    }
}