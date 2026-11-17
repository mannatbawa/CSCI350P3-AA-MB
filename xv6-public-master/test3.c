#include "types.h"
#include "stat.h"
#include "user.h"

#define ROUNDS 60

int main (void) {
    printf(1, "test 3: gaming the scheduler (should stay at priority 0) \n");

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