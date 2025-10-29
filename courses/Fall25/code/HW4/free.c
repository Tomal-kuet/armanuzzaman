#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    uint64 divisor = 1;

    if (argc == 2) {
        switch (argv[1][1]) {
	case 'k':	
	    divisor = 1024;
	    break;
	case 'm':
	    divisor = 1024*1024;
	    break;
	}
    }

    printf("%l\n", freepmem()/divisor);

    exit(0);
}
