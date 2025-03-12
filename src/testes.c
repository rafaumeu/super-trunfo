#include "../include/carta.h"
#include "../include/interface.h"
#include "../include/jogo.h"
#include <assert.h>
#include <stdio.h>

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

// Função principal de testes
void executarTestes(void)
{
    desenharCabecalho("Executando Testes");

    testarInicializacao();
    testarComparacao();
    testarSuperPoder();

    desenharLinha();
    printf("Todos os testes passaram!\n");
    pausar();
}