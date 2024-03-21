#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <errno.h>

int main(int arg, char * argv[]){
	int size= arg-1;
	//printf("%d",size);
	int * data = (int *)malloc(size * sizeof(int));
	for(int i=1;i<arg;i++){
		data[i-1]=atoi(argv[i]);
	}
	//PROC 1
	pid_t pid1 = fork();
	if(pid1<0){
		printf("error in fork");
	}
	else if(pid1==0){
		int sum=0;
		for(int i=0;i<size; i++){
			sum+=data[i];
		}
		printf("sum is: %d",sum);
		exit(EXIT_SUCCESS);
	}
	else 
		wait(NULL);
		
	//PROC 2
	pid_t pid2 = fork();
	if(pid1<0){
		printf("error in fork");
	}
	else if(pid2==0){
		int sum=0;
		for(int i=0;i<size; i++){
			sum+=data[i];
		}
		printf("avg is: %d",sum/size); exit(EXIT_SUCCESS);
	}
	else 
		wait(NULL);
		
}
