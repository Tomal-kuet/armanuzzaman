#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("memory-user <size>, where <size> is the number of bytes to be allocated\n");
        exit(-1);
    }
    unsigned long size = atol(argv[1]);
    unsigned long i;
    int *array;
    printf("allocating %ld bytes\n", size);
    array = (int *)malloc(size);
    if (!array)
    {
        printf("malloc failed\n");
        exit(-1);
    }
    for (i = 0; i < size / 4; i++)
        array[i] = i;
    for (;;)
        for (int i = 0; i < size / 4; i++)
            array[i] += 1;

    return 0;
}
