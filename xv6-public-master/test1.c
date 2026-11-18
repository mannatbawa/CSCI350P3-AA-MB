#include "types.h"
#include "stat.h"
#include "user.h"

#define CPU_WORK  30000000
#define IO_ROUNDS 20

int main(void) {
    int pid_cpu;
    // fork
    pid_cpu = fork();
    // If (pid > 0)
    // Do I/O instensive job
    // wait();
    // getpinfo(getpid());
    if (pid_cpu > 0) {
        for (int k = 0; k < IO_ROUNDS; k++) {
            volatile int y = 0;
            for (int j = 0; j < 1000; j++) {
                y = y + j;
            }
        sleep(1);
        }
        wait();
        getpinfo(getpid());
        printf(1, "test1: done\n");
    }
    else {
        //Do CPU intensive job
        // exit()
        volatile int x = 0;
        for (int i = 0; i < CPU_WORK; i++) {
            x = x + 1;
        }
        getpinfo(getpid());
    }
    exit();
}