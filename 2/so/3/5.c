#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int buffer[argc-1];
	pid_t p;
	int i, status;
	for(i = 1; i< argc; i++) {
		if( (p=fork())== 0){
			buffer[i]= p;
			break;
		}
	}

	if(p){
		for(i=0; i<argc;i++)
			waitpid(buffer[i],&status,0);
			printf("id pai %d meu id %d",getpid(),getppid() );
	}else{
		_exit(execlp(argv[i],argv[i],NULL));

	}
	return 0;
}
