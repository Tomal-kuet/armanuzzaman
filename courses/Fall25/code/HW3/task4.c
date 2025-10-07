#include "kernel/types.h"
#include "user/user.h"

static void hog(void){ volatile int x=0; for(;;) x++; }

int main(void){
  // Spawn a high-priority CPU hog (inherits 49)
  setpriority(49);
  int hogpid = fork();
  if (hogpid == 0) { hog(); exit(0); }

  // Spawn a low-priority child that should eventually run due to aging
  setpriority(0);                  // parent prio -> low child inherits 0
  int start = uptime();
  int lowpid = fork();
  if (lowpid == 0) {
    int t = uptime();
    printf("[LOW] first scheduled at tick %d (wait = %d ticks, base = 0)\n",
           t, t - start);
    exit(0);
  }

  // Wait for the low child to finally run and exit (aging should make this happen)
  wait(0);

  // Cleanup hog so test returns to shell
  kill(hogpid);
  wait(0);
  exit(0);
}
