#include <unistd.h>

int main(){
    _exit(execl("/bin/ls","ls","-l",(char*) NULL));
}
