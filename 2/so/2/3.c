#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int p, i, status ; 
    for(i =1; i<=10; i++){
        p = fork();
        if(p == 0){
            printf("filho numero %d : %d pai : %d\n", i, getpid(), getppid());
            _exit(p);
        }else {
            wait(&status);
            printf("processo %d com pid %d\n", WEXITSTATUS(status), getpid());
        }
    }
    return 0 ;
}
