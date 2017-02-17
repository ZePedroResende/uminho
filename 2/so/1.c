#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

int exe2(char*argv) 
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


int main()
{
   int a;
//   a = mycat(argv[1],O_WRONLY,0600);
   char *argv = "olaman";
   a =exe2(*argv);

   return 0;
}
