#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main ()
{

srand (time(NULL));

int moeda, input;

moeda = rand() % 1 + 1  ; 
printf("%d",moeda);

if (moeda == 2){ 
   printf("Cara\n");
}
else 
{
 printf("Coroa\n");
}
}
