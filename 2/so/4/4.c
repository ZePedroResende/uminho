#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char **argv)
{
    int fdin, fdout;
    for(int j=1; j<argc; j++) {
        if(strcmp(argv[j],"-o") || strcmp(argv[j],"-i")) {
            if(strcmp(argv[j],"-i")) {
                close(0);
                fdin= open(argv[j], O_RDONLY, 0666);
                dup(fdin);
                close(fdin);
            }
            if(strcmp(argv[j],"-o")) {
                close(1);
                fdout = open(argv[j], O_WRONLY|O_CREAT, 0666);
                dup(fdout);
                close(fdout);
            }
        }else{
		execvp(argv[j],&argv[j]);
	}
    }
    return 0;
}
