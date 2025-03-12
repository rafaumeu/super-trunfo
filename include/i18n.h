#ifndef I18N_H
#define I18N_H

/**
 * @brief Available languages
 */
typedef enum
{
    LANG_PT_BR,
    LANG_EN_US
} Language;

/**
 * @brief Message IDs for internationalization
 */
typedef enum
{
    MSG_MENU_TITLE,
    MSG_MENU_NEW_CARD,
    MSG_MENU_SHOW_LAST,
    MSG_MENU_COMPARE,
    MSG_MENU_LIST,
    MSG_MENU_LOAD,
    MSG_MENU_RANKING,
    MSG_MENU_HELP,
    MSG_MENU_LANGUAGE,
    MSG_MENU_EXIT,
    MSG_MENU_BACK,
    MSG_CARD_NUMBER,
    MSG_CARD_DETAILS,
    MSG_CARD_CODE,
    MSG_CARD_STATE,
    MSG_CARD_CITY,
    MSG_CARD_POPULATION,
    MSG_CARD_AREA,
    MSG_CARD_GDP,
    MSG_CARD_TOURIST,
    MSG_HELP_NEW_CARD,
    MSG_HELP_SHOW_LAST,
    MSG_HELP_COMPARE,
    MSG_HELP_LIST,
    MSG_HELP_LOAD,
    MSG_HELP_RANKING,
    MSG_HELP_HELP,
    MSG_HELP_LANGUAGE,
    MSG_HELP_EXIT,
    MSG_RANKING_BY,
    MSG_RANKING_MENU_TITLE,
    MSG_RANKING_POPULATION,
    MSG_RANKING_AREA,
    MSG_RANKING_GDP,
    MSG_RANKING_TOURIST,
    MSG_RANKING_DENSITY,
    MSG_RANKING_GDP_CAPITA,
    MSG_RANKING_POWER,
    MSG_INVALID_OPTION,
    MSG_INVALID_CARD,
    MSG_CONFIRM_EXIT,
    MSG_YES_NO,
    MSG_THANKS,
    MSG_PRESS_ENTER,
    MSG_SUCCESS_LOAD,
    MSG_ERROR_DISK_SPACE,
    MSG_ERROR_FILE_OPEN,
    MSG_ERROR_FILE_SAVE,
    MSG_ERROR_FILE_READ,
    MSG_SUCCESS_SAVE,
    MSG_CARD_LABEL,
    MSG_TOTAL_MESSAGES
} MessageId;

/**
 * @brief Set the current language
 * @param lang Language to set
 */
void setLanguage(Language lang);

/**
 * @brief Get a message in the current language
 * @param id Message ID
 * @return Message text
 */
const char *getMessage(MessageId id);

/**
 * @brief Get the current language
 * @return Current language
 */
Language getCurrentLanguage(void);

#endif // I18N_H