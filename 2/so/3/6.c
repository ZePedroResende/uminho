#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
/*
   int systemSimplesi(char *command)
   {
   int i= 0;
   char *cmd[1024];
   cmd[i]  = strtok(command," ");
   for(++i; cmd[i-1]!=NULL; i++) {
   cmd[i]= strtok(NULL," ");
   }
   return execvp(cmd[0],cmd);
   }


   int main(int argc, char **argv)
   {
   int posicao=0, i,j;
   char c[1024];
   printf("%d",argc);
   for(i = 1; i < argc; i++) {

   int length = strlen(argv[i]);

   for(j = 0; j <= length; j++,posicao++) {
   c[posicao] = argv[i][j];
   }
   c[posicao++] =' ';
   printf("%d",argc);
   }

   c[posicao] ='\0';
   printf("%s",c);
//	char c[100]="ls -l ";
//systemSimplesi(c);
return 0;
}
*/

int main (int argc, char ** argv)
{
	if (argc < 2) {
		printf("Pelo menos 2 argumentos devem ser passados!");
		return 1;
	}

	execvp(argv[1], &argv[1]);
	return 0;
}
