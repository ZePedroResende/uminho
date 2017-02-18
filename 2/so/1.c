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
        int w = write(1,&c,1);
        r = read(0,&c,1);
    }
    return 1;
}

int exe2(char *argv) 
{
    int o,c;
    c = open(argv,O_CREAT,0600);
    o = open(argv,O_WRONLY,0600);
    char novo = 'a';
    for(int t=0;t<10000000;t++){
        write(o,&novo,1);
    }
    return 1;
}

int catv2(int N)
{
    char c;
    int r= read(0,&c,N);
    while(r!= -1){
        int w = write(1,&c,N);
        r = read(0,&c,N);
    }
    return 1;
}

int main(int argc, char **argv)
{
   int a;
//    a = mycat(argv[1],O_WRONLY,0600);
//   a =exe2(argv[1]);
  a = catv2(atoi(argv[1]));
   return 0;
}
