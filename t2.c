#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
        pid_t child1, child2;
        int status;

        child1 = fork();
        if (child1 < 0) {
                perror("fork failed");
                exit(1);
        }

        if (child1 == 0) {
                printf("child 1 pid: %d\n", getpid());
                exit(10);
        }

        child2 = fork();

        if(child2 < 0){
                perror("fork failed");
                exit(1);
        }

        if(child2 == 0){
                printf("child 2 pid: %d\n", getpid());
                exit(20);
        }

        pid_t waited = waitpid(child1, &status, 0);
        if(waited > 0){
                if(WIFEXITED(status)){
                        printf("parent, child1: pid %d, status %d\n",
                               waited, WEXITSTATUS(status));
                }
        }

        waited = waitpid(child2, &status, 0);
        if(waited > 0){
        if(WIFEXITED(status)){
                printf("parent, child2: pid %d, status %d\n",
                               waited, WEXITSTATUS(status));
                }
        }

        return 0;

}
