#include "../include/persistencia.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>

#define ARQUIVO_CARTAS "cartas.dat"

int salvarCarta(const Carta *carta)
{
    FILE *arquivo = fopen(ARQUIVO_CARTAS, "ab");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Erro ao abrir arquivo para salvar carta!");
        return 0;
    }

    size_t escritos = fwrite(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (escritos != 1)
    {
        exibirMensagemErro("Erro ao salvar carta no arquivo!");
        return 0;
    }

    return 1;
}

int carregarCarta(Carta *carta)
{
    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Nenhuma carta salva encontrada!");
        return 0;
    }

    // Posiciona no final do arquivo para ler a última carta
    fseek(arquivo, -((long)sizeof(Carta)), SEEK_END);
    size_t lidos = fread(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (lidos != 1)
    {
        exibirMensagemErro("Erro ao carregar carta do arquivo!");
        return 0;
    }

    return 1;
}

int listarCartas(void)
{
    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Nenhuma carta salva encontrada!");
        return 0;
    }

    Carta carta;
    int numCartas = 0;

    desenharCabecalho("Cartas Salvas");

    while (fread(&carta, sizeof(Carta), 1, arquivo) == 1)
    {
        printf("\nCarta #%d:\n", numCartas + 1);
        printf("Código: %s\n", carta.codigo);
        printf("Estado: %s\n", carta.estado);
        printf("Cidade: %s\n", carta.cidade);
        desenharLinha();
        numCartas++;
    }

    fclose(arquivo);

    if (numCartas == 0)
    {
        printf("Nenhuma carta encontrada!\n");
    }
    else
    {
        printf("\nTotal de cartas: %d\n", numCartas);
    }

    return numCartas;
}