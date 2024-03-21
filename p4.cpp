#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIMITER '$'  // Define the delimiter for separating integers

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <integer1>$<integer2>...$<integerN>" << endl;
    exit(EXIT_FAILURE);
  }

  // Extract integer array from command line argument
  vector<int> data;
  string argument(argv[1]);  // Use string for command line argument
  stringstream ss(argument);
  string token;

  // Use getline to handle potential spaces or leading/trailing delimiters
  getline(ss, token, DELIMITER);  // Skip leading delimiter (if present)
  while (getline(ss, token, DELIMITER)) {
    int value;
    if (stringstream(token) >> value) {
      data.push_back(value);
    } else {
      cerr << "Error: Invalid integer format" << endl;
      exit(EXIT_FAILURE);
    }
  }

  // Create child processes
  pid_t child_pids[3];
  for (int i = 0; i < 3; i++) {
    child_pids[i] = fork();
    if (child_pids[i] < 0) {
      perror("fork failed");
      exit(EXIT_FAILURE);
    } else if (child_pids[i] == 0) {  // Child process
      switch (i) {
        case 0:  // Child 1: Add and print sum
          int sum = 0;
          for (int value : data) {
            sum += value;
          }
          cout << "Sum: " << sum << endl;
          exit(EXIT_SUCCESS);
        case 1:  // Child 2: Calculate and print average
          double average = 0.0;
          for (int value : data) {
            average += value;
          }
          average /= data.size();
          cout << fixed << setprecision(2);
          cout << "Average: " << average << endl;
          exit(EXIT_SUCCESS);
        case 2:  // Child 3: Find and print maximum
          int max = data[0];
          for (int value : data) {
            if (value > max) {
              max = value;
            }
          }
          cout << "Maximum: " << max << endl;
          exit(EXIT_SUCCESS);
      }
    }
  }

  // Parent process waits for child processes to finish
  for (int i = 0; i < 3; i++) {
    wait(NULL);
  }

  return 0;
}
