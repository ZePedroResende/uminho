#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(){
    int i, status; 
    pid_t p = 0; 
    for(i = 0; i < 10;){
        if(!p){
            printf(" processo numero %d pid: %d, ppid: %d \n",i, getpid(), getppid());
            i++;
            p = fork(); 
        }else
            break;
    }
    wait(&status);
    _exit(status);
}
