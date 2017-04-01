#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main()
{
	int pfd[2];
	char buf[10];

	pipe(pfd);

	if(fork()==0){
		close(pfd[0]);
		dup2(pfd[1],1);
		close(pfd[1]);

		execlp("ls","ls",NULL);
		perror("ls");
		_exit(1);

	}else{
		close(pfd[1]);
		//	read(pfd[0],buf,3);
		//		read(pfd[0],buf,2);
		while(read(pfd[0],buf,1)>0){
			printf("%c\n",toupper(buf[0]));//toupper certeza sai do pai 
			sleep(1);
		}
		wait(NULL);
	}
	printf("%c\n",buf[0]);
}
