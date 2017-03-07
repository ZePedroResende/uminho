#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main()
{
    pid_t p = fork();
    printf("filho : %d\n pai : %d\n", getpid(), getppid());
    if(p > 0 ) 
       printf("filho : %d\n", p);
    return 0 ;
}

