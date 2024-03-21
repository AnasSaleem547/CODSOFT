#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main() {
    pid_t child_pid;
    int status;


    // Fork a child process

    for(int i=0;i<2;i++){
    child_pid = fork();
    if (child_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (child_pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        printf("Child process: PPID = %d\n", getppid());
        exit(0);
    } 
    else {
        printf("Parent process: PID = %d\n", getpid());
        wait(&status);
    }
}

    return 0;
}
