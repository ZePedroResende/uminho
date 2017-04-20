#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
/*int main(int argc, char **argv)
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
		execlp(argv[j],argv[j],NULL);
	}
    }
    return 0;
}*/
int main(int argc, char * argv[])
{
    char * prox = argv[1];
    int i, j;
    int fd;
    if(prox == NULL)
        return -1;
    for(j = 1; j < argc; j++) {
        prox = argv[j];
        if(prox[0] == '-') {
            /* se existe um -i ou -o assumo que o caminho é passado, senao da raia*/
            if(prox[1] == 'i') {
                j++;
                fd = open(argv[j], O_RDONLY, 0666);
                if(fd == -1) return -2;
                dup2(fd, 0);
                close(fd);
            } else if(prox[1] == 'o') {
                j++;
                fd = open(argv[j], O_WRONLY|O_CREAT, 0666);
                if(fd == -1) return -2;
                dup2(fd,1);
                close(fd);
            }
        } else
            execlp(prox, prox, NULL);
    }

    return 0;
}
