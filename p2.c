#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		for(int i=0;i<10;i++){
			printf("i m child proc w pid %d %d\n",getpid(),getppid());
		}
	}
	else if (pid>0){	
		for(int i=0;i<10;i++){
			printf(" i m parent proc w pid %d\n",getpid());}
			
		wait(NULL);
	}
}
