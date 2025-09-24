#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
        pid_t pid = fork();

        if (pid < 0) {
                perror("fork failed");
                exit(1);
        }

        if (pid == 0) {
                printf("Child pid %d is exiting\n", getpid());
                exit(0);
        } else {
                printf("Parent pid= %d is sleeping, child may become zombie\n", getpid());
                sleep(30);
                printf("Parent finished sleeping\n");
        }

        return 0;
}
~                
