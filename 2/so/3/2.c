#include <unistd.h>
#include <sys/wait.h>

int main(){
    int p, status;
    p= fork();

    if(p){
        wait(&status);
        _exit(status);
    }
    else
        _exit(execl("/bin/ls","ls","-l",(char *) NULL));
}
