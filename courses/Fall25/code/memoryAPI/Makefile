CC = gcc
CFLAGS = -Wall -Wextra -O2

# Targets
all: address_space memory-user memory-user2 memory-user3

address_space: address_space.c
	$(CC) $(CFLAGS) -o address_space address_space.c

memory-user: memory-user.c
	$(CC) $(CFLAGS) -o memory-user memory-user.c

memory-user2: memory-user2.c
	$(CC) $(CFLAGS) -o memory-user2 memory-user2.c

memory-user3: memory-user3.c
	$(CC) $(CFLAGS) -o memory-user3 memory-user3.c

# Clean up compiled binaries
clean:
	rm -f address_space memory-user memory-user2 memory-user3
