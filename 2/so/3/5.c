#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv){
  pid_t p;
  int i, status;
  for(i = 1; i< argc; i++){
    p =  fork();
    if(!p)
    _exit((execlp(argv[i],argv[i],NULL)));
        }
  for(i =1; i< argc ; i++)
    wait(&status);
  return 0;
}
