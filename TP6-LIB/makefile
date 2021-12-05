TARGET = lib_img.so

CC = gcc 
CFLAGS = -Wall -pedantic -ansi -fpic
CPPFLAGS = -Iinclude -MMD -MP 
LDFLAGS = -lm -O2 -g
LBFLAGS = -shared -g
SRCDIR := src
OBJDIR := obj
BINDIR := .
LIBDIR = lib

EXE := $(TARGET)
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIB =  $(LIB_PATH)$(EXEC)


$(EXE): $(OBJ) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(OBJDIR) -o $@ 

$(LIB):	$(OBJ)
	$(CC) $(LBFLAGS) -o $@ $<


$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPPFLAGS)  $(CFLAGS)  -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(LIBDIR):
	mkdir -p $@