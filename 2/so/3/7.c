#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

ssize_t readln(int fildes, void *buf, size_t nbyte)
{
	int r=0, n=0;
	char* c = buf;
	r = read(fildes,&c[n],1);

	while ( n < (nbyte-1) && r> 0 && c[n] != EOF && c[n] != '\n'&& c[n] != '\0') {
		n++;
		r = read(fildes, &c[n],1);
	}
	c[n+1] = '\0';
	return n+1;
}

int main()
{
	pid_t p ;
	int running = 1;
	char buffer[1024];
	char *temp;
	char *arg[16];
	int i;
		while(running) {
			if(readln(0,buffer,1024)==0) {
				running=0;
			} else {
				i = 0;
				arg[i] = strtok(buffer," \n");
				i++;
				/*
				   temp = strtok(buffer, " \n");
				   for (i = 0; temp != NULL; i++) {
				   arg[i] = temp;
				   temp = strtok(NULL, " \n");
				   }
				   */
				for(; arg[i-1]!=NULL; i++) {
					arg[i]=strtok(NULL," \n");
				}

				//arg[i-1] = NULL;
				if(!strcmp(arg[0] ,"exit")) {
					running=0;
				} else {
					if((p = fork())== 0) {
						execvp(arg[1],arg);
					} else {
						if(strcmp(arg[i-2],"&")) {
							wait(NULL);
						}
					}
				}
			}
		}
	return 0;
}
