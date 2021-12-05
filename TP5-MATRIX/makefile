TARGET = keygen

CC = gcc 
CFLAGS = -Wall -pedantic -ansi 
CPPFLAGS = -Iinclude -MMD -MP
SRCDIR := src
OBJDIR := obj
BINDIR := .

EXE := $(TARGET)
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)



$(EXE): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(OBJDIR)/code.o -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS)  $(CFLAGS)  -c $< -o $@

$(OBJDIR):
	mkdir -p $@
