#include "kernel/param.h"
#include "kernel/types.h"
#include "user/user.h"
#define MAXARGS 16

int 
main(int argc, char *argv[])
{
    int i, rc;
    char *newargv[MAXARGS];
    int priority;

    if(argc < 3){
        printf("Usage: pexec <priority> <comm> [args...]\n");
        exit(-1);
    }

    priority = atoi(argv[1]);
    setpriority(priority);
    for(i=2; i<argc; i++)
        newargv[i-2] = argv[i];
    newargv[argc-2] = 0;

    rc = fork();
    if (rc == 0)
        exec(newargv[0], newargv);
    wait(0);
    exit(0);
}
    
