TARGET = lib_img.so

CC = gcc 
CFLAGS = -Wall -pedantic -ansi -fpic
LDFLAGS = -lm -O2 -g
LBFLAGS = -shared -g
SRCDIR := src
OBJDIR := obj
BINDIR := .
LIBDIR = lib

EXE := $(TARGET)
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIB :=  $(LIBDIR)/$(EXE)




$(LIB):	$(OBJ)
	mkdir -p $(LIBDIR)
	$(CC) $(LBFLAGS) -o $@ $<

$(EXE): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^  -o $@ 
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC)   $(CFLAGS)  -c $< -o $@

$(OBJDIR):
	mkdir -p $@


