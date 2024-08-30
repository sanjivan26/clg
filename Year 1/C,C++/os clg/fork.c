#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 


int main() 
{ 
	pid_t p; 
	int depth = 1;
	for(int i=1;i<=2;i++) {
		p = fork();
		if(p<0) { 
			perror("fork fail"); 
			exit(1); 
		} 
		else if ( p == 0) 
			printf("Child created with pid %d at depth %d\n",getpid(),depth++); 

		else
			printf("Parent with pid %d forked to create child with pid %d at depth %d\n",getpid(),p,depth++); 
		}
		return 0; 
} 
