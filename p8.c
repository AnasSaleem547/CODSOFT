#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <errno.h>
#include<signal.h>


void alarm_handler(int sig) {
  // Handle alarm signal (sig is SIGALRM)
  printf("\nAlarm received! Terminating...\n");
  exit(EXIT_SUCCESS);
}

int main() {
  // Set alarm for 5 seconds
  alarm(5);

  // Install signal handler for SIGALRM (alarm signal)
  signal(SIGALRM, alarm_handler);

  printf("Entering sleep loop (printing every second):\n");

  while (1) {
    printf("  - One second passed\n");
    sleep(1);  // Sleep for one second
  }

  return 0; // This line will not be reached due to the alarm
}
