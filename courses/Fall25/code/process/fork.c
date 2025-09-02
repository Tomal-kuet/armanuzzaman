#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret_from_fork, mypid;
    mypid = getpid(); /* who am I? */
    printf("Before: my pid is %d\n", mypid); /* tell pid */

    ret_from_fork = fork();
    sleep(1);
    printf("After: my fork returns pid : %d, said %d\n",
                                ret_from_fork, getpid());
}






