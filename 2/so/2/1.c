#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("filho : %d\n pai : %d\n", getpid(), getppid());
}

