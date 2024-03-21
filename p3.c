#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
	
	printf("proc id is: %d\nproc prent id is: %d\nuser using is: %d",getpid(),getppid(), getuid());
}
