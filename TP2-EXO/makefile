
CC = gcc 
CFLAGS = -Wall -pedantic -ansi
SRC := 
OBJDIR := obj
BINDIR := .
objects = exo1 exo2 miroir blasay
all: $(objects)
$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<