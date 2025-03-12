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
            break;
        case 2:
            // Exibir carta
            break;
        case 3:
            // Comparar cartas
            break;
        case 4:
            // Ajuda/Instruções
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