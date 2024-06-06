# Variables creadas 
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main

# Archivos fuente
SRC = main.c double_list.c

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Se crea regla principal
all: $(TARGET)

# Se crea regla para compilar el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Se crea regla para compilar archivos fuente
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Se crea regla para limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJ)

# PHONY targets
.PHONY: all clean