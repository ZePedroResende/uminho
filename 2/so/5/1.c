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
		read(pfd[0],buf,5);
		//read(pfd[0],&buf[2],3);
		//write(1,buf,5);
		sleep(2);
	write(1,buf,5);
	}
	return 0 ;
}
