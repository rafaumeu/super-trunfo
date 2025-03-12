# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -I include/

# Diretórios
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fonte e objeto
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nome do executável
TARGET = $(BIN_DIR)/super_trunfo

# Regra padrão
all: directories $(TARGET)

# Criar diretórios necessários
directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

# Compilar o programa
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compilar arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Executar o programa
run: all
	./$(TARGET)

# Executar os testes
test: all
	./$(TARGET) --test

# Regras que não são arquivos
.PHONY: all clean run test directories 