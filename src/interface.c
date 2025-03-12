#include "../include/interface.h"
#include <stdio.h>
#include <stdlib.h>

void exibirMenu(void)
{
    desenharCabecalho("Super Trunfo - Menu Principal");
    printf("1. Criar nova carta\n");
    printf("2. Exibir carta\n");
    printf("3. Comparar cartas\n");
    printf("4. Ajuda/Instruções\n");
    printf("0. Sair\n");
    desenharLinha();
    printf("Escolha uma opção: ");
}

void limparTela(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar(void)
{
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void exibirMensagemErro(const char *mensagem)
{
    printf("\nERRO: %s\n", mensagem);
}

int lerOpcao(int min, int max)
{
    int opcao;
    scanf("%d", &opcao);

    if (opcao < min || opcao > max)
    {
        exibirMensagemErro("Opção inválida!");
        return -1;
    }

    return opcao;
}

void desenharLinha(void)
{
    printf("----------------------------------------\n");
}

void desenharCabecalho(const char *titulo)
{
    limparTela();
    desenharLinha();
    printf("%s\n", titulo);
    desenharLinha();
}