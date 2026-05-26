#ifndef CONSTANTES_H
#define CONSTANTES_H

/**
 * @brief Nome do arquivo para armazenamento das cartas
 */
#define ARQUIVO_CARTAS "cartas.dat"

/**
 * @brief Lista de UFs válidas do Brasil
 */
static const char *UFS_VALIDAS[] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF",
                                    "ES", "GO", "MA", "MT", "MS", "MG", "PA",
                                    "PB", "PR", "PE", "PI", "RJ", "RN", "RS",
                                    "RO", "RR", "SC", "SP", "SE", "TO"};

/**
 * @brief Número total de UFs
 */
#define NUM_UFS 27

/**
 * @brief Tamanho mínimo de espaço livre em disco necessário (em bytes)
 */
#define ESPACO_MINIMO_DISCO 1024 // 1KB

#endif // CONSTANTES_H