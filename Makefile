# Makefile para Sistema de Controle Financeiro
CC = gcc
CFLAGS = -Wall -I include -I db -D_WIN32_WINNT=0x0501
SRC = src
DB = db
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(SRC)/main.c $(SRC)/*.c $(DB)/db.c $(DB)/sqlite3.c
	$(CC) -o $@ $^ $(CFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) financeiro.db