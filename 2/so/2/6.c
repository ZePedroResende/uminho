#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BUFFER 2048
#define X 15
#define Y 40

void geraMat(int mat[X][Y]){
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 15; i++)
        for (j = 0; j < 40; j++)
             mat[i][j] = random() % 300;
}

void printM (int M[X][Y]){
     int i, j;
     for(i = 0; i < X; i++){
         for(j=0; j < Y; j++)
            printf("%d ", M[i][j]);
         printf("\n");
     }
}

int main(int argn, char ** argv){
    int i, k = 0, status, j, ret = 0, x = atoi(argv[1]);
    int mat[X][Y];
    pid_t procs[MAX_BUFFER];
    pid_t p;
    geraMat(mat);
    printM(mat);
    
    for( i = 0; i < X; i++){
        p = fork();
        if (p == 0) break;
        procs[i] = p;
    }

    if(p){
       for(i = 0; i < X; i++){
          waitpid(procs[i], &status, 10);
          status = WEXITSTATUS(status);
          if(status)
              printf("linha %d\n", status-1);
       } 
    } else {
       for(j = 0; j < Y; j++){
          if(mat[i][j] == x)
             _exit(i+1); 
       }
       _exit(0);
    }
    return 0;
}

