#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
using namespace std;
int main(){
	
	cout<<"proc id is: "<<getpid()<<"\nproc pid is: "<<getppid()<<"\nuser id is: "<<getuid();
}
