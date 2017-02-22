#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int mycat()
{
    char c;
    int r= read(0,&c,1);
    while(r!= -1){
        write(1,&c,1);
        r = read(0,&c,1);
    }
    return 1;
}

int exe2(char *argv) 
{
    int o;
    open(argv,O_CREAT,0600);
    o = open(argv,O_WRONLY,0600);
    char novo = 'a';
    for(int t=0;t<10000000;t++){
        write(o,&novo,1);
    }
    return 1;
}

int catv2(int N)
{
    char c[N];

    int r= read(0,&c,N);
    while(r > 0){
        write(1,&c,r);
        r = read(0,&c,N);
    }
    return 1;
}


ssize_t readln(int fildes, void *buf, size_t nbyte)
{
    int r=0, n=0;
    char* c = buf;
    r = read(fildes,c + n,1);
    
    for (n = 1; n < nbyte && c[n] != '\n' && r> 0 ; n++) {
        r = read(fildes, c + n,1);
    }
    
    return n;
}

int main(int argc, char **argv)
{
    int a;
    //    a = mycat(argv[1],O_WRONLY,0600);
    //   a =exe2(argv[1]);
    //  a = catv2(atoi(argv[1]));
    char c[7];
    a = readln(0,&c,7);
    write(1,&c,a);
    return a;
}
