#include "../include/i18n.h"

static Language currentLanguage = LANG_PT_BR;

// Portuguese (Brazil) messages
static const char *pt_BR[] = {
    // Menu principal
    "Menu Principal", "Criar nova carta", "Exibir última carta",
    "Comparar cartas", "Listar cartas salvas", "Carregar última carta",
    "Exibir ranking", "Ajuda/Instruções", "Alterar idioma", "Sair", "Voltar",

    // Carta
    "Carta", "Detalhes da Carta", "Código", "Estado", "Cidade", "População",
    "Área (km²)", "PIB (milhões)", "Pontos Turísticos",

    // Ajuda
    "Crie uma nova carta com dados de uma cidade", "Veja a última carta criada",
    "Compare duas cartas", "Veja todas as cartas salvas",
    "Carregue a última carta salva", "Veja o ranking das cartas",
    "Veja as instruções do jogo", "Altere o idioma do jogo", "Saia do jogo",

    // Ranking
    "Ranking por", "Selecione o Critério de Ranking", "População", "Área",
    "PIB", "Pontos Turísticos", "Densidade Populacional", "PIB per Capita",
    "Super Poder",

    // Outras mensagens
    "Opção inválida", "Carta inválida", "Tem certeza que deseja sair?", "(S/N)",
    "Obrigado por jogar!", "Pressione ENTER para continuar...",
    "Carta carregada com sucesso!",

    // Mensagens de erro e sucesso
    "Erro: Espaço insuficiente em disco",     // MSG_ERROR_DISK_SPACE
    "Erro: Não foi possível abrir o arquivo", // MSG_ERROR_FILE_OPEN
    "Erro: Falha ao salvar no arquivo",       // MSG_ERROR_FILE_SAVE
    "Erro: Falha ao ler do arquivo",          // MSG_ERROR_FILE_READ
    "Carta salva com sucesso!",               // MSG_SUCCESS_SAVE

    // Carta
    "Carta",             // MSG_CARD_LABEL
    "Detalhes da Carta", // MSG_CARD_DETAILS
};

// English (US) messages
static const char *en_US[] = {
    // Menu principal
    "Main Menu", "Create new card", "Show last card", "Compare cards",
    "List saved cards", "Load last card", "Show ranking", "Help/Instructions",
    "Change language", "Exit", "Back",

    // Carta
    "Card", "Card Details", "Code", "State", "City", "Population", "Area (km²)",
    "GDP (millions)", "Tourist Attractions",

    // Ajuda
    "Create a new card with city data", "View the last created card",
    "Compare two cards", "View all saved cards", "Load the last saved card",
    "View cards ranking", "View game instructions", "Change game language",
    "Exit game",

    // Ranking
    "Ranking by", "Select Ranking Criterion", "Population", "Area", "GDP",
    "Tourist Attractions", "Population Density", "GDP per Capita",
    "Super Power",

    // Outras mensagens
    "Invalid option", "Invalid card", "Are you sure you want to exit?", "(Y/N)",
    "Thanks for playing!", "Press ENTER to continue...",
    "Card loaded successfully!", "Card saved successfully!",

    // Carta
    "Card",         // MSG_CARD_LABEL
    "Card Details", // MSG_CARD_DETAILS
};

Language getCurrentLanguage(void) { return currentLanguage; }

void setLanguage(Language lang) { currentLanguage = lang; }

const char *getMessage(MessageId id)
{
    if (id < 0 || id >= MSG_TOTAL_MESSAGES)
    {
        return "Erro: Mensagem não encontrada";
    }

    const char **messages = currentLanguage == LANG_PT_BR ? pt_BR : en_US;
    return messages[id];
}