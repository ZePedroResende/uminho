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
    r = read(fildes,&c[n],1);
    
    while ( n < (nbyte-1) && r> 0 && c[n] != '\n') {
        n++;
        r = read(fildes, &c[n],1);
    }
   c[n+1] = 0;
    return n+1;
}

int nl(int argc, char **argv)
{
   int i = 1;
   char c[1000];
   char line[1000];
   
   
   if(argc==1){
    int r = readln(0,c,1000);
    while(r>0 ){ 
        snprintf(line,1000,"%d\t",i);
        write(1,line,strlen(line));
        write(1,c,r); 
        i++;
        r = readln(0,c,1000);
    }
   }
   
   if(argc==2){
    
   }
}

int main(int argc, char **argv)
{
    int a;
    //    a = mycat(argv[1],O_WRONLY,0600);
    //   a =exe2(argv[1]);
    //  a = catv2(atoi(argv[1]));
    nl(argc,&argv[1]);
    return 0;
}
