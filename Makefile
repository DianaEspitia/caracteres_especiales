# Compile the test file for trying the characters

# Compiler
CC = gcc

# Banderas
CFLAGS = -std=c99 -Wall -Wextra -O3

# Dependencias
DEPS = caracteres_especiales.h

prueba: prueba.o
	$(CC) -o prueba prueba.o $(CFLAGS)

prueba.o: prueba_caracteres_especiales.c $(DEPS)
	$(CC) -c -o prueba.o prueba_caracteres_especiales.c $(CFLAGS)

# Install requiere de sudo
install:
	ln -n caracteres_especiales.h /usr/local/include/
