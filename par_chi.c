#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int value = 10;  // Change this to your desired value
    int fd[2];  // Pipe file descriptors (read, write)

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    pid_t child_pid = fork();
    if (child_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {  // Child process
        close(fd[0]);  // Close read end in child (not used)
        int sum = value + 5;  // Add 5 to the value
        write(fd[1], &sum, sizeof(int));  // Write sum to pipe
        close(fd[1]);  // Close write end after writing
        exit(EXIT_SUCCESS);
    } else {  // Parent process
        close(fd[1]);  // Close write end in parent (not used)
        int result;
        read(fd[0], &result, sizeof(int));  // Read sum from pipe
        close(fd[0]);  // Close read end after reading
        wait(NULL);  // Wait for child to finish
        printf("Sum from child: %d\n", result);
    }

    return 0;
}
