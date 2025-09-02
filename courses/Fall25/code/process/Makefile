# Makefile

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -g

BINDIR = bin

# Executables
PROG1 = $(BINDIR)/fork
PROG2 = $(BINDIR)/exec

# Sources
SRC1 = fork.c
SRC2 = exec.c

# Default rule: build both
all: $(PROG1) $(PROG2)

# Ensure bin directory exists before building
$(BINDIR):
	mkdir -p $(BINDIR)

# Build prog1
$(PROG1): $(SRC1) | $(BINDIR)
	$(CC) $(CFLAGS) -o $(PROG1) $(SRC1)

# Build prog2
$(PROG2): $(SRC2) | $(BINDIR)
	$(CC) $(CFLAGS) -o $(PROG2) $(SRC2)

# Clean up
clean:
	rm -f $(PROG1) $(PROG2)