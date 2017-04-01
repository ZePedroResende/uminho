#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    execv("./a.out",argv);
    return 0;
}
