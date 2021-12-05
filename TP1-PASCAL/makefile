
CC = gcc 
CFLAGS = -Wall -pedantic -ansi
SRC := 
OBJDIR := obj
BINDIR := .
objects = mytee pascal 
all: $(objects)
$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@ $<