#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
        pid_t pid = fork();

        if(pid<0){
                perror("failed");
                exit(1);
        }
        else if(pid == 0){
                printf("Child with pid : %d\n", getpid());
                exit(0);
        }
        else {
                printf("parent proccess pid: %d\n", getpid());
        }
        return 0;
}
