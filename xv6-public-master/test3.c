#include "types.h"
#include "stat.h"
#include "user.h"

#define ROUNDS 60

int main (void) {
    int pid = fork();
    if (pid == 0){
        for (int k = 0; k < ROUNDS; k++) {
            volatile int x = 0;
            for (int j = 0; j <1000; j++) {
                x = x + j;
            }
            sleep(1);
        }
        getpinfo(getpid());
        exit();
    }
    wait();
    printf(1, "test3: done\n");
    exit();
}