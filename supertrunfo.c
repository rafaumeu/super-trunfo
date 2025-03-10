#include <stdio.h>
#include <string.h>
typedef struct
{
    char codigo[4];
    char estado[3];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;
Carta carta1, carta2;
void calcularIndicadores(Carta *carta)
{
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    if (carta->densidadePopulacional > 1000)
    {
        printf("\nAlta densidade populacional!");
    }
    if (carta->pibPerCapita > 50000)
    {
        printf("\nCidade com alto desenvolvimento econômico!");
    }
    else if (carta->pibPerCapita > 25000)
    {
        printf("\nCidade com médio desenvolvimento econômico!");
    }
    else
    {
        printf("\nCidade em desenvolvimento econômico!");
    }
}
void entradaDados(Carta *carta, int numeroCarta)
{
    printf("\n=== Super Trunfo - Países - Carta %d ===\n", numeroCarta);

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o código (ex: A1):      ");
    scanf("%s", carta->codigo);
    printf("│ Código: %s                      \n", carta->codigo);
    printf("└─────────────────────────────────┘\n");
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o estado (ex: SP):      ");
    scanf("%s", carta->estado);
    printf("│ Estado: %s                      \n", carta->estado);
    printf("└─────────────────────────────────┘\n");
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a cidade:              ");
    while (getchar() != '\n')
        ;
    fgets(carta->cidade, 50, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;
    printf("│ Cidade: %s                      \n", carta->cidade);
    printf("└─────────────────────────────────┘\n");
    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a população:            ");
    scanf("%d", &carta->populacao);
    printf("│ População: %d                   \n", carta->populacao);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite a área:                 ");
    scanf("%f", &carta->area);
    printf("│ Área: %.2f                      \n", carta->area);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite o PIB:                  ");
    scanf("%f", &carta->pib);
    printf("│ PIB: %.2f                       \n", carta->pib);
    printf("└─────────────────────────────────┘\n");

    printf("┌─────────────────────────────────┐\n");
    printf("│ Digite os pontos turísticos:   ");
    scanf("%d", &carta->pontosTuristicos);
    printf("│ Pontos Turísticos: %d           \n", carta->pontosTuristicos);
    printf("└─────────────────────────────────┘\n");
}

void mostrarCarta(Carta *carta, int numeroCarta)
{
    printf("\n┌─────────────────────────────────┐\n");
    printf("│ CARTA CADASTRADA                \n");
    printf("│ Carta: %d                      \n", numeroCarta);
    printf("│ Código: %s                      \n", carta->codigo);
    printf("│ Cidade: %s                      \n", carta->cidade);
    printf("│ Estado: %s                      \n", carta->estado);
    printf("│ População: %d                   \n", carta->populacao);
    printf("│ Área: %.2f                      \n", carta->area);
    printf("│ PIB: %.2f                       \n", carta->pib);
    printf("│ Densidade Populacional: %.2f    \n",
           carta->densidadePopulacional);
    printf("│ PIB Per Capita: %.2f            \n", carta->pibPerCapita);
    printf("│ Pontos Turísticos: %d           \n", carta->pontosTuristicos);
    printf("└─────────────────────────────────┘\n");
}
// Add these constants for normalization and weights
#define POPULACAO_NORMALIZER 1000000.0
#define DENSIDADE_NORMALIZER 100.0
#define AREA_NORMALIZER 1000.0
#define PIB_NORMALIZER 1000000.0

#define PESO_POPULACAO 3
#define PESO_AREA 2
#define PESO_PIB 3
#define PESO_PONTOS_TURISTICOS 2
#define PESO_DENSIDADE_INVERSA 2

// Add prototype for Super Power calculation
float calcularSuperPoder(Carta *carta);

// Update the obterValorAtributo function to include Super Power calculation
float obterValorAtributo(Carta *carta, int atributo)
{
    switch (atributo)
    {
        case 1:
            return (float)carta->populacao;
        case 2:
            return carta->area;
        case 3:
            return carta->pib;
        case 4:
            return (float)carta->pontosTuristicos;
        case 5:
            return carta->densidadePopulacional;
        case 6:
            return carta->pibPerCapita;
        case 7:
            return calcularSuperPoder(carta); // Add Super Power option
        default:
            return 0;
    }
}

// Update obterNomeAtributo to include Super Power
const char *obterNomeAtributo(int atributo)
{
    switch (atributo)
    {
        case 1:
            return "População";
        case 2:
            return "Área";
        case 3:
            return "PIB";
        case 4:
            return "Pontos Turísticos";
        case 5:
            return "Densidade Populacional";
        case 6:
            return "PIB per Capita";
        case 7:
            return "Super Poder";
        default:
            return "Desconhecido";
    }
}

// Add function to display dynamic menu for second attribute
void exibirMenuDinamico(int atributoExcluido)
{
    printf("\n┌─────────────────────────────────┐\n");
    printf("│ MENU DE COMPARAÇÃO              \n");
    printf("│                                 \n");
    printf("│ Escolha o segundo atributo:     \n");

    if (atributoExcluido != 1)
        printf("│ 1. População                    \n");
    if (atributoExcluido != 2)
        printf("│ 2. Área                         \n");
    if (atributoExcluido != 3)
        printf("│ 3. PIB                          \n");
    if (atributoExcluido != 4)
        printf("│ 4. Pontos Turísticos            \n");
    if (atributoExcluido != 5)
        printf("│ 5. Densidade Populacional       \n");
    if (atributoExcluido != 6)
        printf("│ 6. PIB per Capita               \n");
    if (atributoExcluido != 7)
        printf("│ 7. Super Poder                  \n");

    printf("│                                 \n");
    printf("└─────────────────────────────────┘\n");
    printf("Digite sua escolha (1-7, exceto %d): ", atributoExcluido);
}

// Add function to compare attributes with special handling for density
int compararAtributo(int atributo, Carta *carta1, Carta *carta2)
{
    float valor1 = obterValorAtributo(carta1, atributo);
    float valor2 = obterValorAtributo(carta2, atributo);

    // Para densidade populacional, menor valor vence
    if (atributo == 5)
    {
        if (valor1 < valor2)
            return 1;
        if (valor1 > valor2)
            return 2;
        return 0; // Empate
    }
    else
    {
        // Para os demais atributos, maior valor vence
        if (valor1 > valor2)
            return 1;
        if (valor1 < valor2)
            return 2;
        return 0; // Empate
    }
}

// Add Super Power calculation function
float calcularSuperPoder(Carta *carta)
{
    float densidadeInversa =
        DENSIDADE_NORMALIZER / carta->densidadePopulacional;
    float superPoder =
        ((carta->populacao / POPULACAO_NORMALIZER) * PESO_POPULACAO) +
        ((carta->area / AREA_NORMALIZER) * PESO_AREA) +
        ((carta->pib / PIB_NORMALIZER) * PESO_PIB) +
        (carta->pontosTuristicos * PESO_PONTOS_TURISTICOS) +
        (densidadeInversa * PESO_DENSIDADE_INVERSA);

    return superPoder;
}

// Update the exibirMenu function to include Super Power
void exibirMenu()
{
    printf("\n┌─────────────────────────────────┐\n");
    printf("│ MENU DE COMPARAÇÃO              \n");
    printf("│                                 \n");
    printf("│ Escolha um atributo:            \n");
    printf("│ 1. População                    \n");
    printf("│ 2. Área                         \n");
    printf("│ 3. PIB                          \n");
    printf("│ 4. Pontos Turísticos            \n");
    printf("│ 5. Densidade Populacional       \n");
    printf("│ 6. PIB per Capita               \n");
    printf("│ 7. Super Poder                  \n");
    printf("│ 8. Comparação Multi-Atributo    \n");
    printf("│                                 \n");
    printf("└─────────────────────────────────┘\n");
    printf("Digite sua escolha (1-8): ");
}

// Replace the compararCartas function with the enhanced version
void compararCartas()
{
    int opcao;
    exibirMenu();
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 8)
    {
        printf("\n┌─────────────────────────────────┐\n");
        printf("│ Opção inválida! Tente novamente.\n");
        printf("└─────────────────────────────────┘\n");
        return;
    }

    if (opcao == 8)
    {
        // Multi-attribute comparison
        int opcao1, opcao2;

        // Escolha do primeiro atributo
        printf("\n┌─────────────────────────────────┐\n");
        printf("│ COMPARAÇÃO MULTI-ATRIBUTO       \n");
        printf("│ Escolha o primeiro atributo:    \n");
        for (int i = 1; i <= 7; i++)
        {
            printf("│ %d. %s\n", i, obterNomeAtributo(i));
        }
        printf("└─────────────────────────────────┘\n");
        printf("Digite sua escolha (1-7): ");
        scanf("%d", &opcao1);

        // Validação da primeira escolha
        if (opcao1 < 1 || opcao1 > 7)
        {
            printf("\n┌─────────────────────────────────┐\n");
            printf("│ Opção inválida! Tente novamente.\n");
            printf("└─────────────────────────────────┘\n");
            return;
        }

        // Escolha do segundo atributo (menu dinâmico)
        exibirMenuDinamico(opcao1);
        scanf("%d", &opcao2);

        // Validação da segunda escolha
        if (opcao2 < 1 || opcao2 > 7 || opcao2 == opcao1)
        {
            printf("\n┌─────────────────────────────────┐\n");
            printf("│ Opção inválida! Tente novamente.\n");
            printf("└─────────────────────────────────┘\n");
            return;
        }

        // Obter valores dos atributos
        float valor1_carta1 = obterValorAtributo(&carta1, opcao1);
        float valor1_carta2 = obterValorAtributo(&carta2, opcao1);
        float valor2_carta1 = obterValorAtributo(&carta1, opcao2);
        float valor2_carta2 = obterValorAtributo(&carta2, opcao2);

        // Comparar atributos individualmente
        int resultado1 = compararAtributo(opcao1, &carta1, &carta2);
        int resultado2 = compararAtributo(opcao2, &carta1, &carta2);

        // Calcular soma dos atributos (normalizada para comparação justa)
        float soma1, soma2;

        // Para densidade populacional, usamos o inverso para a soma
        if (opcao1 == 5 && opcao2 != 5)
        {
            soma1 = (DENSIDADE_NORMALIZER / valor1_carta1) + valor2_carta1;
            soma2 = (DENSIDADE_NORMALIZER / valor1_carta2) + valor2_carta2;
        }
        else if (opcao1 != 5 && opcao2 == 5)
        {
            soma1 = valor1_carta1 + (DENSIDADE_NORMALIZER / valor2_carta1);
            soma2 = valor1_carta2 + (DENSIDADE_NORMALIZER / valor2_carta2);
        }
        else if (opcao1 == 5 && opcao2 == 5)
        {
            soma1 = (DENSIDADE_NORMALIZER / valor1_carta1) +
                    (DENSIDADE_NORMALIZER / valor2_carta1);
            soma2 = (DENSIDADE_NORMALIZER / valor1_carta2) +
                    (DENSIDADE_NORMALIZER / valor2_carta2);
        }
        else
        {
            soma1 = valor1_carta1 + valor2_carta1;
            soma2 = valor1_carta2 + valor2_carta2;
        }

        // Exibir resultado
        printf("\n┌─────────────────────────────────┐\n");
        printf("│ COMPARAÇÃO DE CARTAS            \n");
        printf("│                                 \n");
        printf("│ Cidades: %s vs %s               \n", carta1.cidade,
               carta2.cidade);
        printf("│                                 \n");
        printf("│ Atributo 1: %s                  \n",
               obterNomeAtributo(opcao1));
        printf("│ %s: %.2f                        \n", carta1.cidade,
               valor1_carta1);
        printf("│ %s: %.2f                        \n", carta2.cidade,
               valor1_carta2);
        printf("│ Resultado: %s                   \n",
               resultado1 == 1
                   ? "Carta 1 vence"
                   : (resultado1 == 2 ? "Carta 2 vence" : "Empate"));
        printf("│                                 \n");
        printf("│ Atributo 2: %s                  \n",
               obterNomeAtributo(opcao2));
        printf("│ %s: %.2f                        \n", carta1.cidade,
               valor2_carta1);
        printf("│ %s: %.2f                        \n", carta2.cidade,
               valor2_carta2);
        printf("│ Resultado: %s                   \n",
               resultado2 == 1
                   ? "Carta 1 vence"
                   : (resultado2 == 2 ? "Carta 2 vence" : "Empate"));
        printf("│                                 \n");
        printf("│ SOMA DOS ATRIBUTOS:             \n");
        printf("│ %s: %.2f                        \n", carta1.cidade, soma1);
        printf("│ %s: %.2f                        \n", carta2.cidade, soma2);
        printf("│                                 \n");

        // Determinar vencedor final
        if (soma1 > soma2)
        {
            printf("│ VENCEDOR FINAL: %s!           \n", carta1.cidade);
        }
        else if (soma1 < soma2)
        {
            printf("│ VENCEDOR FINAL: %s!           \n", carta2.cidade);
        }
        else
        {
            printf("│ RESULTADO FINAL: EMPATE!      \n");
        }

        printf("└─────────────────────────────────┘\n");
        return;
    }

    // Single attribute comparison (existing code)
    printf("\n┌─────────────────────────────────┐\n");
    printf("│ COMPARAÇÃO DE CARTAS            \n");
    printf("│ Atributo: %s                    \n", obterNomeAtributo(opcao));
    printf("│                                 \n");

    float valor1 = obterValorAtributo(&carta1, opcao);
    float valor2 = obterValorAtributo(&carta2, opcao);

    printf("│ Carta 1 - %s (%s): %.2f         \n", carta1.cidade, carta1.estado,
           valor1);
    printf("│ Carta 2 - %s (%s): %.2f         \n", carta2.cidade, carta2.estado,
           valor2);
    printf("│                                 \n");

    int resultado = compararAtributo(opcao, &carta1, &carta2);

    if (resultado == 1)
    {
        printf("│ Carta 1 é a melhor!            \n");
    }
    else if (resultado == 2)
    {
        printf("│ Carta 2 é a melhor!            \n");
    }
    else
    {
        printf("│ Empate!                        \n");
    }

    printf("└─────────────────────────────────┘\n");
}

int main()
{
    entradaDados(&carta1, 1);
    calcularIndicadores(&carta1);
    mostrarCarta(&carta1, 1);

    entradaDados(&carta2, 2);
    calcularIndicadores(&carta2);
    mostrarCarta(&carta2, 2);

    compararCartas();
    return 0;
}
