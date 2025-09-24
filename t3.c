#include <stdio.h>
#include <stdlib.h>


void cleanup1(void) {
    printf("function 1 executed\n");
}

void cleanup2(void) {
    printf("function 2 executed\n");
}

int main() {
        if(atexit(cleanup1) != 0) {
                perror("failed cleanup1");
                exit(1);
        }

        if(atexit(cleanup2) != 0) {
                perror("failed cleanup2");
                exit(1);
        }

        printf("Exiting with code 5\n");
        exit(5);

        printf("this will never print\n");
        exit(10);//this will be ignoreed
}
