#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <errno.h>

int main(){
	pid_t pid;
	pid = fork();
	if(pid<0){
		printf("failed");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		execlp("ls","ls",NULL);
		exit(EXIT_SUCCESS);
	}
	else{
		wait(NULL);
	}
}
