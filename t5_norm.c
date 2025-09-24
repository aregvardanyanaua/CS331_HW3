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
                int status;
                pid_t waited = wait(&status);
                printf("Parent pid= %d wated for the child with the status %d\n", getpid(),  WEXITSTATUS(status));

        }

        return 0;
}
