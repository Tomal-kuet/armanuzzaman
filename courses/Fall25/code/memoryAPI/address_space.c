#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Location of code: %p\n", (void *) main);
	printf("Location of heap: %p\n", (void *) malloc(1));
	int stack_var = 0x42;
	printf("Location of stack: %p\n", (void *) &stack_var);
	printf("Value of stack variable: 0x%x\n", stack_var);
	return 0;
}

