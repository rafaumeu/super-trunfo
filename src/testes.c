#include "../include/carta.h"
#include "../include/interface.h"
#include "../include/jogo.h"
#include "../include/persistencia.h"
#include "../include/ranking.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// Função auxiliar para criar uma carta de teste
static Carta criarCartaTeste(const char *codigo, const char *estado,
                             const char *cidade, int populacao, float area,
                             float pib, int pontosTuristicos)
{
    Carta carta;
    strcpy(carta.codigo, codigo);
    strcpy(carta.estado, estado);
    strcpy(carta.cidade, cidade);
    carta.populacao = populacao;
    carta.area = area;
    carta.pib = pib;
    carta.pontosTuristicos = pontosTuristicos;
    return carta;
}

// Testes básicos
void testarInicializacao(void)
{
    Carta carta;
    inicializarCarta(&carta);

    assert(carta.codigo[0] == '\0');
    assert(carta.estado[0] == '\0');
    assert(carta.cidade[0] == '\0');
    assert(carta.populacao == 0);
    assert(carta.area == 0.0f);
    assert(carta.pib == 0.0f);
    assert(carta.pontosTuristicos == 0);

    printf("Teste de inicialização: OK\n");
}

void testarComparacao(void)
{
    Carta carta1 = criarCartaTeste("A1", "SP", "São Paulo", 1000000, 1000.0f,
                                   1000000.0f, 10);
    Carta carta2 =
        criarCartaTeste("A2", "RJ", "Rio", 500000, 500.0f, 500000.0f, 5);

    assert(compararPopulacao(&carta1, &carta2) == 1);
    assert(compararArea(&carta1, &carta2) == 1);
    assert(compararPIB(&carta1, &carta2) == 1);
    assert(compararPontosTuristicos(&carta1, &carta2) == 1);

    printf("Teste de comparação: OK\n");
}

void testarSuperPoder(void)
{
    Carta carta = criarCartaTeste("A1", "SP", "São Paulo", 1000000, 1000.0f,
                                  1000000.0f, 10);
    float superPoder = calcularSuperPoder(&carta);

    assert(superPoder > 0.0f);
    printf("Teste de super poder: OK\n");
}

void testarPersistencia(void)
{
    // Criar uma carta para teste
    Carta cartaOriginal =
        criarCartaTeste("T1", "TS", "Teste", 100000, 100.0f, 100000.0f, 5);

    // Salvar a carta
    assert(salvarCarta(&cartaOriginal) == 1);
    printf("Teste de salvamento: OK\n");

    // Carregar a carta
    Carta cartaCarregada;
    assert(carregarCarta(&cartaCarregada) == 1);

    // Verificar se os dados são iguais
    assert(strcmp(cartaCarregada.codigo, cartaOriginal.codigo) == 0);
    assert(strcmp(cartaCarregada.estado, cartaOriginal.estado) == 0);
    assert(strcmp(cartaCarregada.cidade, cartaOriginal.cidade) == 0);
    assert(cartaCarregada.populacao == cartaOriginal.populacao);
    assert(cartaCarregada.area == cartaOriginal.area);
    assert(cartaCarregada.pib == cartaOriginal.pib);
    assert(cartaCarregada.pontosTuristicos == cartaOriginal.pontosTuristicos);

    printf("Teste de carregamento: OK\n");

    // Testar listagem
    int numCartas = listarCartas();
    assert(numCartas > 0);
    printf("Teste de listagem: OK\n");
}

void testarRanking(void)
{
    // Criar e salvar algumas cartas para teste
    Carta carta1 = criarCartaTeste("R1", "SP", "São Paulo", 1000000, 1000.0f,
                                   1000000.0f, 10);
    Carta carta2 =
        criarCartaTeste("R2", "RJ", "Rio", 500000, 500.0f, 500000.0f, 5);
    Carta carta3 =
        criarCartaTeste("R3", "MG", "BH", 250000, 250.0f, 250000.0f, 3);

    assert(salvarCarta(&carta1) == 1);
    assert(salvarCarta(&carta2) == 1);
    assert(salvarCarta(&carta3) == 1);

    // Testar ranking por diferentes critérios
    assert(exibirRanking(RANKING_POPULACAO) > 0);
    assert(exibirRanking(RANKING_AREA) > 0);
    assert(exibirRanking(RANKING_PIB) > 0);
    assert(exibirRanking(RANKING_PONTOS_TURISTICOS) > 0);
    assert(exibirRanking(RANKING_DENSIDADE) > 0);
    assert(exibirRanking(RANKING_PIB_PER_CAPITA) > 0);
    assert(exibirRanking(RANKING_SUPER_PODER) > 0);

    printf("Teste de ranking: OK\n");
}

// Função principal de testes
void executarTestes(void)
{
    desenharCabecalho("Executando Testes");

    testarInicializacao();
    testarComparacao();
    testarSuperPoder();
    testarPersistencia();
    testarRanking();

    desenharLinha();
    printf("Todos os testes passaram!\n");
    pausar();
}