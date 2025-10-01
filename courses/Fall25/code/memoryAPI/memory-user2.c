#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: memory-user2 <start> <limit> <increment>\n, to allocate from <start> to <limit> number of megabytes by steps of size <increment>\n");
        exit(-1);
    }
    unsigned long start = atol(argv[1]);
    unsigned long limit = atol(argv[2]);
    unsigned long increment = atol(argv[3]);
    unsigned long i, j;
    int *array;
    for (i = start; i <= limit; i += increment)
    {
        printf("allocating %ld megabytes\n", i);
        array = (int *)malloc(i * 1024 * 1024);
        if (!array)
        {
            printf("malloc failed\n");
            exit(-1);
        }
        /*for (j = 0; j <= i*1024*1024/4; j++)
            array[j] = j;
            */
        sleep(5);
        printf("freeing %ld megabytes\n", i);
        free(array);
        sleep(5);
    }

    return 0;
}
