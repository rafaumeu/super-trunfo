/**
 * @file main.c
 * @brief Programa principal do Super Trunfo
 */

#include "../include/carta.h"
#include "../include/interface.h"
#include "../include/jogo.h"
#include <stdio.h>

int main()
{
    // Inicialização do jogo
    iniciarJogo();

    // Variáveis do jogo
    Carta cartaAtual;
    inicializarCarta(&cartaAtual);

    // Loop principal
    int opcao;
    do
    {
        exibirMenu();
        opcao = lerOpcao(0, 4); // 0 para sair, 1-4 para opções do jogo

        switch (opcao)
        {
        case 1:
            // Criar nova carta
            lerDadosCarta(&cartaAtual);
            calcularIndicadores(&cartaAtual);
            pausar();
            break;
        case 2:
            // Exibir carta
            exibirCarta(&cartaAtual);
            printf("\nSuper Poder: %.2f\n", calcularSuperPoder(&cartaAtual));
            pausar();
            break;
        case 3:
            // Comparar cartas
            // Será implementado na próxima issue
            exibirMensagemErro("Função ainda não implementada!");
            pausar();
            break;
        case 4:
            // Ajuda/Instruções
            desenharCabecalho("Ajuda");
            printf("Este é o Super Trunfo de Cidades!\n\n");
            printf("1. Crie uma carta com dados da cidade\n");
            printf("2. Visualize os dados da carta\n");
            printf("3. Compare cartas (em breve!)\n");
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