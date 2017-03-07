#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    int i , p=1 , status;
    for(i=0; i<10 ; i++){
        if(p)
            p = fork();
        else break;
    }

    if(p){
        for(i=1; i<=10; i++){
            wait(&status);
            printf("Filho: %d morreu\n",  WEXITSTATUS(status));
        }
    }else{
            printf("Processo : %d pid: %d  ppid: %d\n", i,  getpid() ,getppid());
            _exit(i);
    }
    if(p >= 1) printf("Pai morreu\n");
    return 0;
}

