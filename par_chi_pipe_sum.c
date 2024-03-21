#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int val=1;
	int fd[2];
	
	if(pipe(fd)==-1){
		printf("pipe failed");
		exit(EXIT_FAILURE);
	}
	
	pid_t pid = fork();
	if(pid < 0){
		printf("fork failed");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		close(fd[0]);
		val++; val++;
		int sum=val;
		//open(fd[1]);
		write(fd[1],&sum,sizeof(int));
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else{
		wait(NULL);
		int res;
		close(fd[1]);
		read(fd[0],&res,sizeof(int));
		close(fd[0]);
		printf("sum is: %d",val);
	}
}
