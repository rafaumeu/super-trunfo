#include "../include/carta.h"
#include "../include/interface.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void inicializarCarta(Carta *carta) { memset(carta, 0, sizeof(Carta)); }

// Funções auxiliares de validação
static int validarCodigo(const char *codigo)
{
    if (strlen(codigo) != 2)
        return 0;
    if (!isalpha(codigo[0]) || !isdigit(codigo[1]))
        return 0;
    return 1;
}

static int validarEstado(const char *estado)
{
    if (strlen(estado) != 2)
        return 0;
    if (!isalpha(estado[0]) || !isalpha(estado[1]))
        return 0;
    return 1;
}

static int validarCidade(const char *cidade)
{
    if (strlen(cidade) < 2 || strlen(cidade) >= 50)
        return 0;
    return 1;
}

void lerDadosCarta(Carta *carta)
{
    desenharCabecalho("Cadastro de Carta");

    do
    {
        printf("Digite o código (ex: A1): ");
        scanf("%3s", carta->codigo);
        if (!validarCodigo(carta->codigo))
        {
            exibirMensagemErro(
                "Código inválido! Use uma letra seguida de um número.");
        }
    } while (!validarCodigo(carta->codigo));

    do
    {
        printf("Digite o estado (ex: SP): ");
        scanf("%2s", carta->estado);
        if (!validarEstado(carta->estado))
        {
            exibirMensagemErro("Estado inválido! Use duas letras.");
        }
    } while (!validarEstado(carta->estado));

    do
    {
        printf("Digite a cidade: ");
        getchar(); // Limpar o buffer
        fgets(carta->cidade, sizeof(carta->cidade), stdin);
        carta->cidade[strcspn(carta->cidade, "\n")] = 0;
        if (!validarCidade(carta->cidade))
        {
            exibirMensagemErro("Nome de cidade inválido!");
        }
    } while (!validarCidade(carta->cidade));

    do
    {
        printf("Digite a população: ");
        scanf("%d", &carta->populacao);
        if (carta->populacao <= 0)
        {
            exibirMensagemErro("População deve ser maior que zero!");
        }
    } while (carta->populacao <= 0);

    do
    {
        printf("Digite a área: ");
        scanf("%f", &carta->area);
        if (carta->area <= 0)
        {
            exibirMensagemErro("Área deve ser maior que zero!");
        }
    } while (carta->area <= 0);

    do
    {
        printf("Digite o PIB: ");
        scanf("%f", &carta->pib);
        if (carta->pib < 0)
        {
            exibirMensagemErro("PIB não pode ser negativo!");
        }
    } while (carta->pib < 0);

    do
    {
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &carta->pontosTuristicos);
        if (carta->pontosTuristicos < 0)
        {
            exibirMensagemErro(
                "Número de pontos turísticos não pode ser negativo!");
        }
    } while (carta->pontosTuristicos < 0);
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