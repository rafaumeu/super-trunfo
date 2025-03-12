/**
 * @file main.c
 * @brief Programa principal do Super Trunfo
 */

#include "../include/carta.h"
#include "../include/i18n.h"
#include "../include/interface.h"
#include "../include/jogo.h"
#include "../include/persistencia.h"
#include "../include/ranking.h"
#include "../include/testes.h"
#include <ctype.h> // Para toupper()
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    // Define o idioma com base no argumento de linha de comando
    if (argc > 1 && strcmp(argv[1], "en") == 0)
    {
        setLanguage(LANG_EN_US);
    }
    else
    {
        setLanguage(LANG_PT_BR);
    }

    // Executa os testes se solicitado
    if (argc > 1 && strcmp(argv[1], "test") == 0)
    {
        limparTela();
        return executarTestes();
    }

    // Inicialização do jogo
    limparTela();
    iniciarJogo();

    // Loop principal
    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao)
        {
            case 1:
                limparTela();
                criarCarta();
                break;
            case 2:
                limparTela();
                exibirUltimaCarta();
                break;
            case 3:
                limparTela();
                compararCartas();
                break;
            case 4:
                limparTela();
                listarCartas();
                break;
            case 5:
                limparTela();
                carregarUltimaCarta();
                break;
            case 6:
                limparTela();
                {
                    CriterioRanking criterio = selecionarCriterioRanking();
                    if (criterio != CRITERIO_POPULACAO || opcao != 8)
                    {
                        aguardarEnter(); // Aguarda ENTER apenas se não estiver
                                         // voltando
                    }
                }
                break;
            case 7:
                limparTela();
                exibirInstrucoes();
                break;
            case 8:
                limparTela();
                alterarIdioma();
                break;
            case 9:
                limparTela();
                printf("%s\n", getMessage(MSG_CONFIRM_EXIT));
                printf("%s ", getMessage(MSG_YES_NO));
                char confirmacao;
                scanf(" %c", &confirmacao);
                confirmacao = toupper(confirmacao);
                if (confirmacao == 'S' || confirmacao == 'Y')
                {
                    limparTela();
                    printf("%s\n", getMessage(MSG_THANKS));
                    return 0;
                }
                break;
            default:
                printf("%s\n", getMessage(MSG_INVALID_OPTION));
                break;
        }

        if (opcao != 9)
        {
            printf("\nPressione ENTER para continuar...");
            getchar();
            limparTela();
        }
    } while (opcao != 9);

    // Finalização do jogo
    finalizarJogo();
    return 0;
}