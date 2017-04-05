#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
int main()
{

	int fdin, fderror, fdout;
	int lido;
	int status;
	int buffer[1024];
	fdin = open("./password.txt",O_RDONLY,0666);
	fderror = open("./errors.txt",O_CREAT|O_WRONLY,0666);
	fdout = open("./saida.txt",O_CREAT|O_WRONLY,0666);

	close(0);
	dup(fdin);
	close(fdin);

	close(1);
	dup(fdout);
	close(fdout);

	close(2);
	dup(fderror);
	close(fderror);

	pid_t p = fork();
	if(!p){
		while(lido = read(0,buffer,1024))
			write(1,buffer,lido);
		_exit(0);
	}
	return 0;
}
