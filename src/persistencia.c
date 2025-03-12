#include "../include/persistencia.h"
#include "../include/constantes.h"
#include "../include/i18n.h"
#include "../include/interface.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ARQUIVO_CARTAS "cartas.dat"

bool validarEspacoDisco()
{
    // Tenta criar um arquivo temporário para testar o espaço em disco
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        return false;
    }

    // Tenta escrever 1MB de dados
    char buffer[1024] = {0};
    for (int i = 0; i < 1024; i++)
    {
        if (fwrite(buffer, 1, sizeof(buffer), temp) != sizeof(buffer))
        {
            fclose(temp);
            remove("temp.txt");
            return false;
        }
    }

    fclose(temp);
    remove("temp.txt");
    return true;
}

bool validarArquivo(const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL)
    {
        return false;
    }
    fclose(fp);
    return true;
}

bool salvarCarta(const Carta *carta)
{
    if (!validarEspacoDisco())
    {
        printf("%s\n", getMessage(MSG_ERROR_DISK_SPACE));
        return false;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "ab");
    if (arquivo == NULL)
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        return false;
    }

    size_t escritos = fwrite(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (escritos != 1)
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_SAVE));
        return false;
    }

    printf("%s\n", getMessage(MSG_SUCCESS_SAVE));
    return true;
}

bool carregarCarta(Carta *carta)
{
    if (!validarArquivo(ARQUIVO_CARTAS))
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        return false;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        return false;
    }

    fseek(arquivo, -((long)sizeof(Carta)), SEEK_END);
    size_t lidos = fread(carta, sizeof(Carta), 1, arquivo);
    fclose(arquivo);

    if (lidos != 1)
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_READ));
        return false;
    }

    printf("%s\n", getMessage(MSG_SUCCESS_LOAD));
    return true;
}

bool listarCartas()
{
    if (!validarArquivo(ARQUIVO_CARTAS))
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        return false;
    }

    FILE *arquivo = fopen(ARQUIVO_CARTAS, "rb");
    if (arquivo == NULL)
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        return false;
    }

    Carta carta;
    int contador = 0;

    while (fread(&carta, sizeof(Carta), 1, arquivo) == 1)
    {
        printf("\n=== Carta %d ===\n", ++contador);
        printf("%s: %s\n", getMessage(MSG_CARD_CODE), carta.codigo);
        printf("%s: %s\n", getMessage(MSG_CARD_STATE), carta.estado);
        printf("%s: %s\n", getMessage(MSG_CARD_CITY), carta.cidade);
        printf("%s: %d\n", getMessage(MSG_CARD_POPULATION), carta.populacao);
        printf("%s: %.2f\n", getMessage(MSG_CARD_AREA), carta.area);
        printf("%s: %.2f\n", getMessage(MSG_CARD_GDP), carta.pib);
        printf("%s: %d\n", getMessage(MSG_CARD_TOURIST),
               carta.pontosTuristicos);
    }

    fclose(arquivo);
    return true;
}