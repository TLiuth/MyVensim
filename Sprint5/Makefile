# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -fPIC

# Diretórios
BIN_DIR = bin
SRC_DIR = src
TEST_DIR = test
LIB_DIR = lib

# Nome da biblioteca compartilhada
LIB_NAME = libmyvensim.so

# Arquivos fonte para a biblioteca
LIB_SRCS = $(SRC_DIR)/model.cpp $(SRC_DIR)/system.cpp $(SRC_DIR)/flow.cpp
LIB_OBJS = $(LIB_SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Arquivos fonte dos testes
FUNCTIONAL_SRC = $(TEST_DIR)/functional/main.cpp $(TEST_DIR)/functional/functional_tests.cpp
UNIT_SRC = $(TEST_DIR)/unit/main.cpp $(TEST_DIR)/unit/unit_tests.cpp $(TEST_DIR)/unit/unit_flow.cpp $(TEST_DIR)/unit/unit_model.cpp $(TEST_DIR)/unit/unit_system.cpp

# Alvo padrão
all: $(LIB_DIR)/$(LIB_NAME) functional unit

# Criar diretórios se não existirem
$(BIN_DIR) $(LIB_DIR):
	mkdir -p $@

# Compilação dos objetos da biblioteca
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criando a biblioteca compartilhada
$(LIB_DIR)/$(LIB_NAME): $(LIB_OBJS) | $(LIB_DIR)
	$(CXX) -shared -o $@ $(LIB_OBJS)

# Compilação dos testes funcionais (sem recompilar os arquivos da biblioteca)
functional: $(LIB_DIR)/$(LIB_NAME)
	$(CXX) $(CXXFLAGS) -L$(LIB_DIR) $(FUNCTIONAL_SRC) -lmyvensim -o $(BIN_DIR)/functional

# Compilação dos testes unitários (sem recompilar os arquivos da biblioteca)
unit: $(LIB_DIR)/$(LIB_NAME)
	$(CXX) $(CXXFLAGS) -L$(LIB_DIR) $(UNIT_SRC) -lmyvensim -o $(BIN_DIR)/unit

# Execução dos testes
run_functional: functional
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(BIN_DIR)/functional

run_unit: unit
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(BIN_DIR)/unit

# Limpeza dos arquivos gerados
clean:
	rm -rf $(LIB_DIR) $(BIN_DIR)
