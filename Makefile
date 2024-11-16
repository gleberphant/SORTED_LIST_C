# Nome do executável
EXECUTAVEL = main

# Arquivos com fonte
FONTES = $(wildcard *.c)

# Flags do compilador
CFLAGS = -Wall -g

# # Bibliotecas
# LIBS = -lmingw32 
# LIBS_PATH =  

# Regra padrão
all: $(EXECUTAVEL)

# Regra para compilar o executável
$(EXECUTAVEL): $(FONTES)
	gcc $(CFLAGS) $(FONTES) -o $(EXECUTAVEL) $(LIBS_PATH) $(LIBS)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(EXECUTAVEL)

# Regra para executar o programa
run: all
	./$(EXECUTAVEL) 11 5 50 10 88 74 83 6 71 9 2 33 22 12 11 58 58 8 23 84 