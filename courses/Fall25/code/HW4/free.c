#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    uint64 divisor = 1;
    const char *unit = "bytes";

    // Optional argument: -k or -m for KB / MB display
    if (argc == 2 && argv[1][0] == '-') {
        switch (argv[1][1]) {
        case 'k':
            divisor = 1024;
            unit = "KB";
            break;
        case 'm':
            divisor = 1024 * 1024;
            unit = "MB";
            break;
        default:
            fprintf(2, "Usage: free [-k | -m]\n");
            exit(1);
        }
    } else if (argc > 2) {
        fprintf(2, "Usage: free [-k | -m]\n");
        exit(1);
    }

    uint64 free_bytes = freepmem();
    printf("Free memory: %l %s\n", free_bytes / divisor, unit);

    exit(0);
}
