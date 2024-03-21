#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>  // For isdigit() function

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <integer1> <integer2> ... <integerN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_elements = argc - 1;  // Correctly calculate number of elements

    // Error handling: Check for invalid input (non-digits)
    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                fprintf(stderr, "Error: Invalid integer format in argument %d\n", i);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Efficient memory allocation based on number of elements
    int *data = (int *)malloc(num_elements * sizeof(int));
    if (!data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Convert arguments to integers and store in data array
    for (int i = 1; i < argc; i++) {
        data[i - 1] = atoi(argv[i]);  // Access array elements correctly
    }

    // Create child processes
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {  // Child process 1 (sum)
        int sum = 0;
        for (int i = 0; i < num_elements; i++) {
            sum += data[i];
        }
        printf("Sum is: %d\n", sum);
        exit(EXIT_SUCCESS);
    }

    // Parent process waits for child process 1
    wait(NULL);

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {  // Child process 2 (average)
        double average = 0.0;
        for (int i = 0; i < num_elements; i++) {
            average += data[i];
        }
        average /= num_elements;
        printf("Average is: %.2lf\n", average);
        exit(EXIT_SUCCESS);
    }

    // Parent process waits for child process 2
    wait(NULL);

    // Free allocated memory
    free(data);

    return 0;
}
