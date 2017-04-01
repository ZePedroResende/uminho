#include <stdio.h>
#include <unistd.h>


int main()
{
	int pfd[2];
	char buf[10];

	pipe(pfd);

	if(fork()==0){
		close(pfd[0]);
		sleep(5);
		write(pfd[1],"ab",2);
		write(pfd[1],"cde",3);
	}else{
		close(pfd[1]);
		//	read(pfd[0],buf,3);
		//		read(pfd[0],buf,2);
		while(read(pfd[0],buf,1)>0){
			printf("%c\n",buf[0]);
			sleep(1);
		}
	}
	printf("%c\n",buf[0]);
}
