#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    printf("Process pid is %d\n", getpid());
    return 0;
}





