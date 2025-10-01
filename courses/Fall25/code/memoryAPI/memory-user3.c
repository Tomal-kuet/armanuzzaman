#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: memory-user3 <start>, where <start> is initial megabytes to alocate\n");
        exit(-1);
    }
    unsigned long start = atol(argv[1]);
    //    unsigned long limit = atol(argv[2]);
    //    unsigned long increment = atol(argv[2]);
    unsigned long i, j;
    int *array;
    i = start;
    for (;;)
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
        //	sleep(5);
        printf("freeing %ld megabytes\n", i);
        free(array);
        //	sleep(5);
        //	i += increment;
        i *= 2;
    }

    return 0;
}
