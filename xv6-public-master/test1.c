#include "types.h"
#include "stat.h"
#include "user.h"

#define CPU_WORK  30000000
#define IO_ROUNDS 20

void cpu_intensive(void) {
    volatile int x = 0;
    for (int i = 0; i < CPU_WORK; i++) {
        x = x + 1;
    }

    getpinfo(getpid());
    exit();
}

void io_intensive(void) {
    for (int k = 0; k < IO_ROUNDS; k++) {
        volatile int y = 0;
        for (int j = 0; j < 1000; j++) {
            y = y + j;
        }
        sleep(1);
    }

    getpinfo(getpid());
    exit();
}

int main(void) {
    int pid_cpu;
    int pid_io;

    printf(1, "test 1: mixed cpu and I/O workload\n");

    pid_cpu = fork();
    if (pid_cpu == 0) {
        cpu_intensive();
    }

    pid_io = fork();
    if (pid_io == 0) {
        io_intensive();
    }

    wait();
    wait();

    printf(1, "test1: done\n");
    exit();

}