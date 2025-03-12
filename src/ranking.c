#include "../include/ranking.h"
#include "../include/interface.h"
#include "../include/persistencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar uma carta com seu valor de ranking
typedef struct
{
    Carta carta;
    float valor;
} CartaRanking;

// Função de comparação para qsort
static int compararCartas(const void *a, const void *b)
{
    const CartaRanking *cartaA = (const CartaRanking *)a;
    const CartaRanking *cartaB = (const CartaRanking *)b;

    if (cartaA->valor < cartaB->valor)
        return 1;
    if (cartaA->valor > cartaB->valor)
        return -1;
    return 0;
}

// Função para obter o valor de ranking de uma carta
static float obterValorRanking(const Carta *carta, CriterioRanking criterio)
{
    switch (criterio)
    {
    case RANKING_POPULACAO:
        return (float)carta->populacao;
    case RANKING_AREA:
        return carta->area;
    case RANKING_PIB:
        return carta->pib;
    case RANKING_PONTOS_TURISTICOS:
        return (float)carta->pontosTuristicos;
    case RANKING_DENSIDADE:
        return carta->populacao / carta->area;
    case RANKING_PIB_PER_CAPITA:
        return carta->pib / carta->populacao;
    case RANKING_SUPER_PODER:
        return calcularSuperPoder(carta);
    default:
        return 0.0f;
    }
}

// Função para obter o nome do critério
static const char *obterNomeCriterio(CriterioRanking criterio)
{
    switch (criterio)
    {
    case RANKING_POPULACAO:
        return "População";
    case RANKING_AREA:
        return "Área";
    case RANKING_PIB:
        return "PIB";
    case RANKING_PONTOS_TURISTICOS:
        return "Pontos Turísticos";
    case RANKING_DENSIDADE:
        return "Densidade Populacional";
    case RANKING_PIB_PER_CAPITA:
        return "PIB per Capita";
    case RANKING_SUPER_PODER:
        return "Super Poder";
    default:
        return "Desconhecido";
    }
}

int exibirRanking(CriterioRanking criterio)
{
    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Nenhuma carta salva encontrada!");
        return 0;
    }

    // Contar número de cartas
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    int numCartas = tamanhoArquivo / sizeof(Carta);
    rewind(arquivo);

    // Alocar memória para o array de cartas
    CartaRanking *cartas = malloc(numCartas * sizeof(CartaRanking));
    if (cartas == NULL)
    {
        exibirMensagemErro("Erro ao alocar memória!");
        fclose(arquivo);
        return 0;
    }

    // Ler todas as cartas
    for (int i = 0; i < numCartas; i++)
    {
        fread(&cartas[i].carta, sizeof(Carta), 1, arquivo);
        cartas[i].valor = obterValorRanking(&cartas[i].carta, criterio);
    }
    fclose(arquivo);

    // Ordenar cartas
    qsort(cartas, numCartas, sizeof(CartaRanking), compararCartas);

    // Exibir ranking
    desenharCabecalho("Ranking por ");
    printf("%s\n\n", obterNomeCriterio(criterio));

    for (int i = 0; i < numCartas; i++)
    {
        printf("%dº Lugar:\n", i + 1);
        printf("Cidade: %s (%s)\n", cartas[i].carta.cidade,
               cartas[i].carta.estado);
        printf("Valor: %.2f\n", cartas[i].valor);
        desenharLinha();
    }

    free(cartas);
    return numCartas;
}

CriterioRanking selecionarCriterioRanking(void)
{
    desenharCabecalho("Selecione o Critério de Ranking");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    desenharLinha();

    int opcao;
    do
    {
        opcao = lerOpcao(1, 7);
    } while (opcao < 1 || opcao > 7);

    return (CriterioRanking)(opcao - 1);
}