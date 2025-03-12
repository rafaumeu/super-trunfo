#include "../include/interface.h"
#include "../include/i18n.h"
#include "../include/ranking.h"
#include <stdio.h>
#include <stdlib.h>

void exibirMenu(void)
{
    printf("\n");
    desenharCabecalho(getMessage(MSG_MENU_TITLE));
    printf("1. %s\n", getMessage(MSG_MENU_NEW_CARD));
    printf("2. %s\n", getMessage(MSG_MENU_SHOW_LAST));
    printf("3. %s\n", getMessage(MSG_MENU_COMPARE));
    printf("4. %s\n", getMessage(MSG_MENU_LIST));
    printf("5. %s\n", getMessage(MSG_MENU_LOAD));
    printf("6. %s\n", getMessage(MSG_MENU_RANKING));
    printf("7. %s\n", getMessage(MSG_MENU_HELP));
    printf("8. %s\n", getMessage(MSG_MENU_LANGUAGE));
    printf("9. %s\n", getMessage(MSG_MENU_EXIT));
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
    desenharLinha();
    printf("%s\n", titulo);
    desenharLinha();
}

void exibirCarta(const Carta *carta)
{
    if (carta == NULL)
    {
        printf("%s\n", getMessage(MSG_INVALID_CARD));
        return;
    }

    printf("\n=== %s ===\n", getMessage(MSG_CARD_DETAILS));
    printf("%s: %s\n", getMessage(MSG_CARD_CODE), carta->codigo);
    printf("%s: %s\n", getMessage(MSG_CARD_STATE), carta->estado);
    printf("%s: %s\n", getMessage(MSG_CARD_CITY), carta->cidade);
    printf("%s: %d\n", getMessage(MSG_CARD_POPULATION), carta->populacao);
    printf("%s: %.2f\n", getMessage(MSG_CARD_AREA), carta->area);
    printf("%s: %.2f\n", getMessage(MSG_CARD_GDP), carta->pib);
    printf("%s: %d\n", getMessage(MSG_CARD_TOURIST), carta->pontosTuristicos);
}

void exibirInstrucoes(void)
{
    limparTela();
    printf("----------------------------------------\n");
    printf("%s\n", getMessage(MSG_MENU_HELP));
    printf("----------------------------------------\n\n");

    printf("1. %s - %s\n", getMessage(MSG_MENU_NEW_CARD),
           getMessage(MSG_HELP_NEW_CARD));
    printf("2. %s - %s\n", getMessage(MSG_MENU_SHOW_LAST),
           getMessage(MSG_HELP_SHOW_LAST));
    printf("3. %s - %s\n", getMessage(MSG_MENU_COMPARE),
           getMessage(MSG_HELP_COMPARE));
    printf("4. %s - %s\n", getMessage(MSG_MENU_LIST),
           getMessage(MSG_HELP_LIST));
    printf("5. %s - %s\n", getMessage(MSG_MENU_LOAD),
           getMessage(MSG_HELP_LOAD));
    printf("6. %s - %s\n", getMessage(MSG_MENU_RANKING),
           getMessage(MSG_HELP_RANKING));
    printf("7. %s - %s\n", getMessage(MSG_MENU_HELP),
           getMessage(MSG_HELP_HELP));
    printf("8. %s - %s\n", getMessage(MSG_MENU_LANGUAGE),
           getMessage(MSG_HELP_LANGUAGE));
    printf("9. %s - %s\n", getMessage(MSG_MENU_EXIT),
           getMessage(MSG_HELP_EXIT));
    printf("----------------------------------------\n");

    printf("\n%s", getMessage(MSG_PRESS_ENTER));
    getchar();
}

void alterarIdioma(void)
{
    limparTela();
    desenharCabecalho(getMessage(MSG_MENU_LANGUAGE));
    printf("1. Português (Brasil)\n");
    printf("2. English (US)\n");
    printf("3. %s\n", getMessage(MSG_MENU_BACK));
    desenharLinha();
    printf("Escolha/Choose: ");

    int opcao;
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer

    switch (opcao)
    {
        case 1:
            setLanguage(LANG_PT_BR);
            printf("\nIdioma alterado para Português!\n");
            break;
        case 2:
            setLanguage(LANG_EN_US);
            printf("\nLanguage changed to English!\n");
            break;
        case 3:
            break;
        default:
            printf("Opção inválida!/Invalid option!\n");
    }
}

void exibirMenuCriterios(void)
{
    limparTela();
    printf("----------------------------------------\n");
    printf("%s\n", getMessage(MSG_RANKING_MENU_TITLE));
    printf("----------------------------------------\n");
    printf("1. %s\n", getMessage(MSG_RANKING_POPULATION));
    printf("2. %s\n", getMessage(MSG_RANKING_AREA));
    printf("3. %s\n", getMessage(MSG_RANKING_GDP));
    printf("4. %s\n", getMessage(MSG_RANKING_TOURIST));
    printf("5. %s\n", getMessage(MSG_RANKING_DENSITY));
    printf("6. %s\n", getMessage(MSG_RANKING_GDP_CAPITA));
    printf("7. %s\n", getMessage(MSG_RANKING_POWER));
    printf("8. %s\n", getMessage(MSG_MENU_BACK));
    printf("----------------------------------------\n");
}

CriterioRanking selecionarCriterioRanking(void)
{
    int opcao;
    do
    {
        exibirMenuCriterios();
        if (scanf("%d", &opcao) != 1)
        {
            limparBuffer();
            continue;
        }
        limparBuffer(); // Limpar o buffer logo após o scanf

        if (opcao >= 1 && opcao <= 7)
        {
            CriterioRanking criterio = (CriterioRanking)(opcao - 1);
            exibirRanking(criterio);
            return criterio; // Retorna imediatamente após exibir o ranking
        }
        else if (opcao == 8)
        {
            return CRITERIO_POPULACAO; // Retorna imediatamente ao selecionar
                                       // voltar
        }
        else
        {
            printf("%s\n", getMessage(MSG_INVALID_OPTION));
            aguardarEnter();
        }
    } while (1);
}

static void limparBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void aguardarEnter(void)
{
    printf("\n%s", getMessage(MSG_PRESS_ENTER));
    limparBuffer();
    limparBuffer(); // Remove o segundo ENTER que está ficando no buffer
}

void criarCarta(void)
{
    Carta novaCarta;
    lerDadosCarta(&novaCarta);
    salvarCarta(&novaCarta);
    printf("\n%s", getMessage(MSG_PRESS_ENTER));
    getchar();
    getchar();
}

void exibirUltimaCarta(void)
{
    Carta carta;
    if (carregarCarta(&carta))
    {
        exibirCarta(&carta);
    }
    printf("\n%s", getMessage(MSG_PRESS_ENTER));
    getchar();
    getchar();
}

void carregarUltimaCarta(void)
{
    Carta carta;
    if (!carregarCarta(&carta))
    {
        printf("%s\n", getMessage(MSG_ERROR_FILE_OPEN));
        aguardarEnter();
        return;
    }

    printf("%s\n", getMessage(MSG_SUCCESS_LOAD));
    exibirCarta(&carta);
    aguardarEnter();
}

void exibirListaCartas(void)
{
    Carta cartas[MAX_CARTAS];
    int numCartas = carregarTodasCartas(cartas);

    for (int i = 0; i < numCartas; i++)
    {
        printf("\n=== %s %d ===\n",
               getCurrentLanguage() == LANG_PT_BR ? "Carta" : "Card", i + 1);
        exibirCarta(&cartas[i]);
    }
    aguardarEnter();
}
