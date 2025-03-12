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
    printf("Testando funções de ranking...\n");

    // Criar algumas cartas para testar
    Carta carta1 = {"SP1", "SP", "São Paulo", 12000000, 1521.11f, 600.0f, 50};
    Carta carta2 = {"RJ1",  "RJ", "Rio de Janeiro", 6700000, 1200.27f,
                    350.0f, 40};

    // Salvar as cartas
    assert(salvarCarta(&carta1));
    assert(salvarCarta(&carta2));

    // Testar exibição do ranking com diferentes critérios
    assert(exibirRanking(CRITERIO_POPULACAO) > 0);
    assert(exibirRanking(CRITERIO_AREA) > 0);
    assert(exibirRanking(CRITERIO_PIB) > 0);
    assert(exibirRanking(CRITERIO_PONTOS_TURISTICOS) > 0);
    assert(exibirRanking(CRITERIO_DENSIDADE) > 0);
    assert(exibirRanking(CRITERIO_PIB_PER_CAPITA) > 0);
    assert(exibirRanking(CRITERIO_SUPER_PODER) > 0);

    printf("Testes de ranking concluídos com sucesso!\n");
}

// Função principal de testes
int executarTestes(void)
{
    int falhas = 0;

    desenharCabecalho("Executando Testes");

    testarInicializacao();
    testarComparacao();
    testarSuperPoder();
    testarPersistencia();
    testarRanking();

    desenharLinha();

    printf("\nResultado dos testes: ");
    if (falhas == 0)
    {
        printf("Todos os testes passaram!\n");
        return 0;
    }
    else
    {
        printf("%d teste(s) falharam.\n", falhas);
        return 1;
    }
}