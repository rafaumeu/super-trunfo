#include "../include/carta.h"
#include "../include/constantes.h"
#include "../include/i18n.h"
#include "../include/interface.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Constantes de validação
#define TAMANHO_MAXIMO_CODIGO 3
#define TAMANHO_MAXIMO_ESTADO 2
#define TAMANHO_MAXIMO_CIDADE 50
#define VALOR_MINIMO_NUMERICO 0

// Funções de validação
bool validarCodigo(const char *codigo)
{
    if (strlen(codigo) != TAMANHO_MAXIMO_CODIGO)
    {
        exibirMensagemErro("O código deve ter exatamente 3 caracteres!");
        return false;
    }

    for (int i = 0; codigo[i]; i++)
    {
        if (!isalnum(codigo[i]))
        {
            exibirMensagemErro("O código deve conter apenas letras e números!");
            return false;
        }
    }

    return true;
}

bool validarEstado(const char *estado)
{
    if (strlen(estado) != TAMANHO_MAXIMO_ESTADO)
    {
        exibirMensagemErro(
            "A sigla do estado deve ter exatamente 2 caracteres!");
        return false;
    }

    for (int i = 0; estado[i]; i++)
    {
        if (!isupper(estado[i]))
        {
            exibirMensagemErro(
                "A sigla do estado deve conter apenas letras maiúsculas!");
            return false;
        }
    }

    // Verifica se é uma UF válida
    for (int i = 0; i < NUM_UFS; i++)
    {
        if (strcmp(estado, UFS_VALIDAS[i]) == 0)
        {
            return true;
        }
    }

    exibirMensagemErro(
        "UF inválida! Use uma sigla válida de estado brasileiro.");
    return false;
}

bool validarCidade(const char *cidade)
{
    if (strlen(cidade) == 0)
    {
        exibirMensagemErro("O nome da cidade não pode estar vazio!");
        return false;
    }

    if (strlen(cidade) > TAMANHO_MAXIMO_CIDADE)
    {
        exibirMensagemErro("O nome da cidade é muito longo!");
        return false;
    }

    if (!isalpha(cidade[0]))
    {
        exibirMensagemErro("O nome da cidade deve começar com uma letra!");
        return false;
    }

    return true;
}

bool validarValorNumerico(float valor)
{
    if (valor <= VALOR_MINIMO_NUMERICO)
    {
        char mensagem[100];
        sprintf(mensagem, "O valor deve ser maior que zero!");
        exibirMensagemErro(mensagem);
        return false;
    }
    return true;
}

void inicializarCarta(Carta *carta)
{
    carta->codigo[0] = '\0';
    carta->estado[0] = '\0';
    carta->cidade[0] = '\0';
    carta->populacao = 0;
    carta->area = 0.0f;
    carta->pib = 0.0f;
    carta->pontosTuristicos = 0;
}

void lerDadosCarta(Carta *carta)
{
    printf("\n=== %s ===\n", getMessage(MSG_MENU_NEW_CARD));

    do
    {
        printf("%s (3 caracteres): ", getMessage(MSG_CARD_CODE));
        scanf("%3s", carta->codigo);
        getchar(); // Limpa o buffer
    } while (!validarCodigo(carta->codigo));

    do
    {
        printf("%s (2 letras): ", getMessage(MSG_CARD_STATE));
        scanf("%2s", carta->estado);
        getchar(); // Limpa o buffer
    } while (!validarEstado(carta->estado));

    do
    {
        printf("%s (max 50 caracteres): ", getMessage(MSG_CARD_CITY));
        fgets(carta->cidade, sizeof(carta->cidade), stdin);
        carta->cidade[strcspn(carta->cidade, "\n")] = 0; // Remove o \n
    } while (!validarCidade(carta->cidade));

    do
    {
        printf("%s: ", getMessage(MSG_CARD_POPULATION));
        scanf("%d", &carta->populacao);
        getchar(); // Limpa o buffer
    } while (!validarValorNumerico(carta->populacao));

    do
    {
        printf("%s: ", getMessage(MSG_CARD_AREA));
        scanf("%f", &carta->area);
        getchar(); // Limpa o buffer
    } while (!validarValorNumerico(carta->area));

    do
    {
        printf("%s: ", getMessage(MSG_CARD_GDP));
        scanf("%f", &carta->pib);
        getchar(); // Limpa o buffer
    } while (!validarValorNumerico(carta->pib));

    do
    {
        printf("%s: ", getMessage(MSG_CARD_TOURIST));
        scanf("%d", &carta->pontosTuristicos);
        getchar(); // Limpa o buffer
    } while (!validarValorNumerico(carta->pontosTuristicos));
}

void calcularIndicadores(Carta *carta)
{
    // Densidade populacional (hab/km²)
    float densidade = carta->populacao / carta->area;

    // PIB per capita
    float pibPerCapita = (carta->pib * 1000000.0f) / carta->populacao;

    printf("\nIndicadores calculados:\n");
    printf("Densidade populacional: %.2f hab/km²\n", densidade);
    printf("PIB per capita: R$ %.2f\n", pibPerCapita);
}

float calcularSuperPoder(const Carta *carta)
{
    return (carta->populacao * 0.45f + carta->area * 0.35f +
            carta->pib * 0.15f + carta->pontosTuristicos * 0.05f) /
           1000.0f;
}

float obterValorAtributo(const Carta *carta, int atributo)
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
        default:
            return "Desconhecido";
    }
}