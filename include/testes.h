#ifndef TESTES_H
#define TESTES_H

// Funções de teste
void testarInicializacao(void);
void testarComparacao(void);
void testarSuperPoder(void);
void testarPersistencia(void);
void testarRanking(void);

/**
 * @brief Executa todos os testes do sistema
 * @return 0 se todos os testes passaram, diferente de 0 se algum falhou
 */
int executarTestes(void);

#endif // TESTES_H