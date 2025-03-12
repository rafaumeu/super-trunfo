#include "../include/persistencia.h"
#include "../include/constantes.h"
#include "../include/interface.h"
#include <stdio.h>
#include <string.h>

#define ARQUIVO_CARTAS "cartas.dat"

// Funções auxiliares de validação (declaradas em carta.c)
extern int validarEspacoDisco(void);
extern int validarArquivo(const char *arquivo, const char *modo);

int salvarCarta(const Carta *carta)
{
    // Verificar espaço em disco
    if (!validarEspacoDisco())
    {
        return 0;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "ab");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Erro ao abrir arquivo para salvar!");
        return 0;
    }

    size_t escritos = fwrite(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (escritos != 1)
    {
        exibirMensagemErro("Erro ao salvar carta!");
        return 0;
    }

    return 1;
}

int carregarCarta(Carta *carta)
{
    // Verificar se o arquivo existe
    if (!validarArquivo(ARQUIVO_CARTAS, "rb"))
    {
        return 0;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Erro ao abrir arquivo para leitura!");
        return 0;
    }

    // Posicionar no final do arquivo
    fseek(arquivo, -(long)sizeof(Carta), SEEK_END);

    size_t lidos = fread(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (lidos != 1)
    {
        exibirMensagemErro("Erro ao carregar carta!");
        return 0;
    }

    return 1;
}

int listarCartas(void)
{
    // Verificar se o arquivo existe
    if (!validarArquivo(ARQUIVO_CARTAS, "rb"))
    {
        return 0;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        exibirMensagemErro("Erro ao abrir arquivo para leitura!");
        return 0;
    }

    // Contar número de cartas
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    int numCartas = tamanhoArquivo / sizeof(Carta);
    rewind(arquivo);

    // Exibir cartas
    desenharCabecalho("Lista de Cartas");
    printf("Total de cartas: %d\n\n", numCartas);

    Carta carta;
    for (int i = 0; i < numCartas; i++)
    {
        if (fread(&carta, sizeof(Carta), 1, arquivo) != 1)
        {
            exibirMensagemErro("Erro ao ler carta!");
            fclose(arquivo);
            return 0;
        }
        printf("Carta %d:\n", i + 1);
        exibirCarta(&carta);
    }

    fclose(arquivo);
    return numCartas;
}