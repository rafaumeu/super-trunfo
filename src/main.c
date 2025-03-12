/**
 * @file main.c
 * @brief Programa principal do Super Trunfo
 */

#include "../include/carta.h"
#include "../include/interface.h"
#include "../include/jogo.h"
#include "../include/persistencia.h"
#include "../include/testes.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Verifica se é modo teste
    if (argc > 1 && strcmp(argv[1], "--test") == 0)
    {
        executarTestes();
        return 0;
    }

    // Inicialização do jogo
    iniciarJogo();

    // Loop principal
    int opcao;
    do
    {
        exibirMenu();
        opcao = lerOpcao(0, 7); // 0 para sair, 1-7 para opções do jogo

        switch (opcao)
        {
        case 1:
            // Criar nova carta
            {
                Carta novaCarta;
                inicializarCarta(&novaCarta);
                lerDadosCarta(&novaCarta);
                calcularIndicadores(&novaCarta);
                exibirCarta(&novaCarta);
                if (salvarCarta(&novaCarta))
                {
                    printf("\nCarta salva com sucesso!\n");
                }
                pausar();
            }
            break;
        case 2:
            // Exibir última carta
            {
                Carta carta;
                if (carregarCarta(&carta))
                {
                    exibirCarta(&carta);
                    printf("\nSuper Poder: %.2f\n", calcularSuperPoder(&carta));
                }
                pausar();
            }
            break;
        case 3:
            // Comparar cartas
            compararCartas();
            break;
        case 4:
            // Listar cartas salvas
            listarCartas();
            pausar();
            break;
        case 5:
            // Carregar última carta
            {
                Carta carta;
                if (carregarCarta(&carta))
                {
                    printf("\nCarta carregada com sucesso!\n");
                    exibirCarta(&carta);
                }
                pausar();
            }
            break;
        case 6:
            // Executar testes
            executarTestes();
            break;
        case 7:
            // Ajuda/Instruções
            desenharCabecalho("Ajuda");
            printf("Este é o Super Trunfo de Cidades!\n\n");
            printf("1. Crie uma carta com dados da cidade\n");
            printf("2. Visualize os dados da carta\n");
            printf("3. Compare duas cartas pelos atributos\n");
            printf("4. Liste todas as cartas salvas\n");
            printf("5. Carregue a última carta salva\n");
            printf("6. Execute os testes do sistema\n");
            desenharLinha();
            pausar();
            break;
        case 0:
            // Sair
            break;
        }
    } while (opcao != 0);

    // Finalização do jogo
    finalizarJogo();
    return 0;
}