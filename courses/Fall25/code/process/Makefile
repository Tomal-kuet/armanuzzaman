# Makefile

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -g

BINDIR = bin

# Executables
PROG1 = $(BINDIR)/fork
PROG2 = $(BINDIR)/exec
PROG3 = $(BINDIR)/Test1

# Sources
SRC1 = fork.c
SRC2 = exec.c
SRC3 = Test1.c

# Default rule: build all
all: $(PROG1) $(PROG2) $(PROG3)

# Ensure bin directory exists before building
$(BINDIR):
	mkdir -p $(BINDIR)

# Build prog1
$(PROG1): $(SRC1) | $(BINDIR)
	$(CC) $(CFLAGS) -o $(PROG1) $(SRC1)

# Build prog2
$(PROG2): $(SRC2) | $(BINDIR)
	$(CC) $(CFLAGS) -o $(PROG2) $(SRC2)

# Build prog3
$(PROG3): $(SRC3) | $(BINDIR)
	$(CC) $(CFLAGS) -o $(PROG3) $(SRC3)

# Clean up
clean:
	rm -f $(PROG1) $(PROG2) $(PROG3)