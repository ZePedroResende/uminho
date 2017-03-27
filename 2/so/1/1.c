#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int mycat()
{
    int a = 0;
    char c;
    int r= read(0,&c,1);
    while(r!= -1){
        int a = write(1,&c,1);
        if (a != 1) exit(1);
        r = read(0,&c,1);
    }
    return a;
}

int exe2(char *argv) 
{
    int o, a;
    open(argv,O_CREAT,0600);
    o = open(argv,O_WRONLY,0600);
    char novo = 'a';
    for(int t=0;t<10000000;t++){
        a = write(o,&novo,1);
        if(a != 1) exit(1);
    }
    return 1;
}

int catv2(int N)
{
    char c[N];
    int a ; 
    int r= read(0,&c,N);
    while(r > 0){
       a =  write(1,&c,r);
       if(a != r) exit(1);
        r = read(0,&c,N);
    }
    return 1;
}


ssize_t readln(int fildes, void *buf, size_t nbyte)
{
    int r=0, n=0;
    char* c = buf;
    r = read(fildes,&c[n],1);

    while ( n < (nbyte-1) && r> 0 && c[n] != EOF && c[n] != '\n'&& c[n] != '\0') {
        n++;
        r = read(fildes, &c[n],1);
    }
    c[n+1] = 0;
    return n+1;
}

int nl(int argc, char *argv)
{
    int i = 1, r=0, a;
    char c[1000];
    char line[1000];


    if(argc==1){
        r = readln(0,c,1000);
        while(r>1 || c[r-1]== '\n'){ 
            snprintf(line,1000,"%d\t",i);
            a = write(1,line,strlen(line));
            if(a != strlen(line)) exit(1);
            a = write(1,c,r); 
            if(a != r) exit(1);
            i++;
            r = readln(0,c,1000);
        }
    }

    if(argc==2){
        int ficheiro = open(argv,O_RDONLY);
        if(ficheiro < 0) 
            perror("FILE DOESN'T EXIST\n"), exit(-1);
        r = readln(ficheiro,c,1000);
        while(r>1 || c[r-1]== '\n'){ 
            snprintf(line,1000,"%d\t",i);
            a = write(1,line,strlen(line));
            if(a != strlen(line)) exit(1);
            a = write(1,c,r); 
            if(a != r) exit(1);
            i++;
            r = readln(ficheiro,c,1000);
        }
    }
    exit(r);
}

int cat_v3(int argc , char **argv)
{
    char c[1024];
    int a,h,r, i=1;

    while(i < argc ){
       h = open((argv[i]),O_RDONLY); 
       r = read(h,&c,1024);
        while(r > 0){
            a = write(1,&c,r);
            if(a!= r) exit(1);
            r = read(h,&c,1024);
        }
       i++;
    }
    return 1;
}


int main(int argc, char **argv)
{
        int a;
    //   char c[1000];
        a = mycat();
        //a = mycat(argv[1],O_WRONLY,0600);
    //   a =exe2(argv[1]);
    //  a = catv2(atoi(argv[1]));
    //nl(argc,argv[1]);
    //a =    readln(0,c,1000);
    //    write(1,c,a);
//k    cat_v3(argc,argv);
    return 0;
}
