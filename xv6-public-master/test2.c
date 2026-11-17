#include "types.h"
#include "stat.h"
#include "user.h"

#define VIC_OUTER 4000
#define VIC_INNER 20000
#define NOISE     15
#define NOISE_WORK 20000

int main(void) {
    int victim;

    printf(1, "test 2: priority boost and aging\n");

    victim = fork();
    if (victim == 0) {
        volatile int x = 0;

        for (int a = 0; a < VIC_OUTER; a++) {
            for (int b = 0; b < VIC_INNER; b++) {
                x = x + b;
            }
        }
        getpinfo(getpid());
        exit();
    }

    for (int n = 0; n < NOISE; n++) {
        int pid = fork();
        if (pid == 0) {
            volatile int y = 0;

            for (int j = 0; j < NOISE_WORK; j++) {
                y = y + j;

            }
            exit();
        }
        sleep(2);
    }

    while (wait() > 0);

    printf(1, "test2: done\n");
    exit();
}