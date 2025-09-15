#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p[2]; // p[0] is read end, p[1] is write end
    char *childargV[2];
    childargV[0] = "wc";
    childargV[1] = 0;
    pipe(p);

    if (fork() == 0)
    {
        close(0); // close stdin
        dup(p[0]); // duplicate read end to stdin
        close(p[0]); // close original read end
        close(p[1]); // close write end in child
        exec("wc", childargV);  // execute wc
        fprintf(2, "exec wc failed\n"); // if exec fails
    }
    else
    {
        close(p[0]); // close read end in parent
        write(p[1], "hello world\n", 12); // write to pipe
        write(p[1], "hello UTEP\n", 11);
        write(p[1], "hello CS4375\n", 13);
        write(p[1], "hello OS\n", 9);
        write(p[1], "hello PIPE\n", 11);
        close(p[1]); // close write end to send EOF to wc
        wait(0); // wait for child to finish
        exit(0);
    }
    return 0;
}