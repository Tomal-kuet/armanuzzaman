#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: memory-user <start> <limit> <increment>, where <start> is initial mebibytes to allocate which is then incremented up to limit mebibytes\n");
        exit(-1);
    }
    uint start = atoi(argv[1]);
    uint limit = atoi(argv[2]);
    uint increment = atoi(argv[3]);
    uint i, j;

    int *array;
    for (i = start; i <= limit; i += increment)
    {
        printf("allocating %p mebibytes\n", i);
        array = (int *)malloc(i * 1024 * 1024);
        printf("malloc returned %p\n", array);
        if (!array)
        {
            printf("malloc failed\n");
            exit(-1);
        }
        // ----------------------------------------------------------
        // CASE 1: Default (lazy) — allocate and free without touching
        // ----------------------------------------------------------
        // This verifies that no physical pages are allocated
        // until the memory is actually accessed.

        // ----------------------------------------------------------
        // CASE 2: Touch every page (uncomment to test)
        // ----------------------------------------------------------
        
        /*uint bytes = i * 1024 * 1024;
        for (j = 0; j < bytes / sizeof(int); j += 1024) {
            // write once roughly every 4 KB (one int per page)
            array[j] = j;
        }
        printf("Touched all pages in %d MiB\n", i);*/
        

        // ----------------------------------------------------------
        // CASE 3: Touch some pages only (uncomment to test)
        // ----------------------------------------------------------
        
        /*uint bytes = i * 1024 * 1024;
        for (j = 0; j < bytes / sizeof(int); j += 1024 * 16) {
            // touch 1 out of every 16 pages (~6 % of total)
            array[j] = j;
        }
        printf("Touched ~1/16 of pages in %d MiB\n", i);*/
        
                
        sleep(50);
        printf("freeing %p mebibytes\n", i);
        free(array);
        sleep(50);
    }

    exit(0);
}
