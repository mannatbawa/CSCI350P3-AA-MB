#include "types.h"
#include "stat.h"
#include "user.h"

#define VIC_OUTER 4000
#define VIC_INNER 20000
#define NOISE     15



int main(void) {
    //fork() In
    // parent:
    // Fork multiple times — Like 10 times
    for (int n = 0; n < NOISE; n++) {
        int pid = fork();
        // In child:
        // Do CPU or I/O intensive job in each task
        // getpinfo()
        if (pid == 0) {
            volatile int y = 0;

            for (int a = 0; a < VIC_OUTER; a++){
                for (int b = 0; b < VIC_INNER; b++){
                    y = y + b;
                }
            }
            getpinfo(getpid());
            exit();
        }
    }
    // Do CPU or I/O intensive job
    // getpinfo()
    volatile int x = 0;
    for (int a = 0; a < VIC_OUTER; a++) {
        for (int b = 0; b < VIC_INNER; b++) {
            x = x + b;
        }
    }
    //parent
    getpinfo(getpid());
    //parent waiting for children
    while (wait() > 0);

    printf(1, "test2: done\n");
    exit();
}