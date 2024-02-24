   
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 1;
    int i;
    for (i = 0; i < 2; i++) {
        if (fork() == 0) {
        // block 1
        x++;
        printf("loop %d, x=%d\n", i, x);
    } else {
        wait(NULL);
        // block 2
        x--;
        printf("loop %d, x=%d\n", i, x);
        }
    }
 return 0;
}