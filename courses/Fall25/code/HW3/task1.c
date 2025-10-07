#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    printf("parent initial priority: %d\n", getpriority());
    if (setpriority(17) < 0)
        printf("setpriority failed\n");
    printf("parent after set: %d\n", getpriority());

    int pid = fork();
    if (pid == 0)
    {
        printf("child inherited priority: %d\n", getpriority()); // expect 17
        printf("\nExec ps to print all process info\n\n");
        exec("ps", (char *[]){"ps", 0});
        printf("exec ps failed\n");
        exit(0);
    }
    wait(0);
    exit(0);
}