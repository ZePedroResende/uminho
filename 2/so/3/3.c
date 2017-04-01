#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
    execvp("/bin/echo",argv);
    return 0;
}
