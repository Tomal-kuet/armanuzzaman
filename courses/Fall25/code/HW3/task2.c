#include "kernel/types.h"
#include "user/user.h"

int main(void)
{
    int pid1 = fork();
    if (pid1 == 0)
    {
        setpriority(40); // higher priority
        for (int i = 0 ; i < 5; i ++)
        {
            printf("Child A ran (priority = %d, CPU ticks = %d)\n", getpriority(), uptime());
            sleep(1);
        }
        exit(0);
    }

    int pid2 = fork();
    if (pid2 == 0)
    {
        setpriority(39); // lower priority
        for (int i = 0 ; i < 5; i ++)
        {
            printf("Child B ran (priority = %d, CPU ticks = %d)\n", getpriority(), uptime());
            sleep(1);
        }
        exit(0);
    }
    int pid3 = fork();
     if (pid3 == 0)
    {
        setpriority(40); // lower priority
        for (int i = 0 ; i < 5; i ++)
        {
            printf("Child C ran (priority = %d, CPU ticks = %d)\n", getpriority(), uptime());
            sleep(1);
        }
        exit(0);
    }

    wait(0);
    wait(0);
    exit(0);
}