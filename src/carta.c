#include "../include/carta.h"
#include "../include/constantes.h"
#include "../include/interface.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/statvfs.h>

// Constantes de validação
#define TAMANHO_MAXIMO_CODIGO 3
#define TAMANHO_MAXIMO_ESTADO 2
#define TAMANHO_MAXIMO_CIDADE 50
#define VALOR_MINIMO_NUMERICO 0

// Funções de validação
static int validarCodigo(const char *codigo)
{
    // Verifica tamanho
    if (strlen(codigo) != TAMANHO_MAXIMO_CODIGO)
    {
        exibirMensagemErro("O código deve ter exatamente 3 caracteres!");
        return 0;
    }

    // Verifica se é alfanumérico
    for (int i = 0; codigo[i]; i++)
    {
        if (!isalnum(codigo[i]))
        {
            exibirMensagemErro("O código deve conter apenas letras e números!");
            return 0;
        }
    }

    return 1;
}

static int validarEstado(const char *estado)
{
    // Verifica tamanho
    if (strlen(estado) != TAMANHO_MAXIMO_ESTADO)
    {
        exibirMensagemErro(
            "A sigla do estado deve ter exatamente 2 caracteres!");
        return 0;
    }

    // Verifica se são letras maiúsculas
    for (int i = 0; estado[i]; i++)
    {
        if (!isupper(estado[i]))
        {
            exibirMensagemErro(
                "A sigla do estado deve conter apenas letras maiúsculas!");
            return 0;
        }
    }

    // Verifica se é uma UF válida
    int ufValida = 0;
    for (int i = 0; i < NUM_UFS; i++)
    {
        if (strcmp(estado, UFS_VALIDAS[i]) == 0)
        {
            ufValida = 1;
            break;
        }
    }

    if (!ufValida)
    {
        exibirMensagemErro(
            "UF inválida! Use uma sigla válida de estado brasileiro.");
        return 0;
    }

    return 1;
}

static int validarCidade(const char *cidade)
{
    // Verifica se está vazio
    if (strlen(cidade) == 0)
    {
        exibirMensagemErro("O nome da cidade não pode estar vazio!");
        return 0;
    }

    // Verifica tamanho máximo
    if (strlen(cidade) > TAMANHO_MAXIMO_CIDADE)
    {
        exibirMensagemErro("O nome da cidade é muito longo!");
        return 0;
    }

    // Verifica se começa com letra
    if (!isalpha(cidade[0]))
    {
        exibirMensagemErro("O nome da cidade deve começar com uma letra!");
        return 0;
    }

    return 1;
}

static int validarValorNumerico(const char *campo, float valor)
{
    if (valor <= VALOR_MINIMO_NUMERICO)
    {
        char mensagem[100];
        sprintf(mensagem, "O valor de %s deve ser maior que zero!", campo);
        exibirMensagemErro(mensagem);
        return 0;
    }
    return 1;
}

static int validarEspacoDisco(void)
{
#ifdef _WIN32
    // Implementação para Windows usando GetDiskFreeSpaceEx
    ULARGE_INTEGER espacoLivre;
    if (!GetDiskFreeSpaceEx(NULL, &espacoLivre, NULL, NULL))
    {
        exibirMensagemErro("Erro ao verificar espaço em disco!");
        return 0;
    }
    return espacoLivre.QuadPart >= ESPACO_MINIMO_DISCO;
#else
    // Implementação para sistemas Unix-like
    struct statvfs stat;
    if (statvfs(".", &stat) != 0)
    {
        exibirMensagemErro("Erro ao verificar espaço em disco!");
        return 0;
    }
    unsigned long long espacoLivre = stat.f_bsize * stat.f_bavail;
    if (espacoLivre < ESPACO_MINIMO_DISCO)
    {
        exibirMensagemErro("Espaço insuficiente em disco!");
        return 0;
    }
    return 1;
#endif
}

static int validarArquivo(const char *arquivo, const char *modo)
{
    FILE *fp = fopen(arquivo, modo);
    if (fp == NULL)
    {
        if (strcmp(modo, "rb") == 0)
        {
            exibirMensagemErro("Arquivo não encontrado!");
        }
        else
        {
            exibirMensagemErro("Não foi possível acessar o arquivo!");
        }
        return 0;
    }
    fclose(fp);
    return 1;
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
    char buffer[100];

    // Verificar espaço em disco antes de começar
    if (!validarEspacoDisco())
    {
        return;
    }

    // Ler código
    do
    {
        printf("Digite o código da carta (3 caracteres): ");
        scanf("%s", buffer);
        getchar(); // Limpar o buffer
    } while (!validarCodigo(buffer));
    strcpy(carta->codigo, buffer);

    // Ler estado
    do
    {
        printf("Digite a sigla do estado (2 letras maiúsculas): ");
        scanf("%s", buffer);
        getchar(); // Limpar o buffer
    } while (!validarEstado(buffer));
    strcpy(carta->estado, buffer);

    // Ler cidade
    do
    {
        printf("Digite o nome da cidade: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remover o \n
    } while (!validarCidade(buffer));
    strcpy(carta->cidade, buffer);

    // Ler população
    do
    {
        printf("Digite a população: ");
        scanf("%d", &carta->populacao);
        getchar(); // Limpar o buffer
    } while (!validarValorNumerico("população", carta->populacao));

    // Ler área
    do
    {
        printf("Digite a área (km²): ");
        scanf("%f", &carta->area);
        getchar(); // Limpar o buffer
    } while (!validarValorNumerico("área", carta->area));

    // Ler PIB
    do
    {
        printf("Digite o PIB (em milhões): ");
        scanf("%f", &carta->pib);
        getchar(); // Limpar o buffer
    } while (!validarValorNumerico("PIB", carta->pib));

    // Ler pontos turísticos
    do
    {
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &carta->pontosTuristicos);
        getchar(); // Limpar o buffer
    } while (
        !validarValorNumerico("pontos turísticos", carta->pontosTuristicos));
}

void exibirCarta(const Carta *carta)
{
    desenharLinha();
    printf("Código: %s\n", carta->codigo);
    printf("Cidade: %s (%s)\n", carta->cidade, carta->estado);
    printf("População: %d habitantes\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f milhões\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontosTuristicos);
    desenharLinha();
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
    // Normalização dos valores
    float popNorm = carta->populacao / 1000000.0f;  // Em milhões
    float areaNorm = carta->area / 1000.0f;         // Em milhares de km²
    float pibNorm = carta->pib / 1000.0f;           // Em bilhões
    float ptNorm = carta->pontosTuristicos / 10.0f; // Em dezenas

    // Média ponderada
    return (popNorm * 0.3f + areaNorm * 0.2f + pibNorm * 0.3f + ptNorm * 0.2f);
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