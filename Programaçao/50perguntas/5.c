#include <stdio.h>
#include <string.h>
// numero de 1 em binario de um certo numero
int bitsUm (unsigned int n)
{
	int cont = 0;
	int rest;

	while(n != 0)
	{
		rest = n % 2;
		n = n / 2;
		cont = cont + rest;
	}
	return cont;
}


// numero de zeros em binario na representaçao final
int trailingZ (unsigned int n) {

    int r ;
    r = n %2 ;
    n = n / 2;
    int i = 0;


    while (r != 1 ){
    r =n % 2 ;
     n = n /2 ;
     i++;
    }

    return i;
}
//
int qDig (int n) {
    int r = 0;

    while (n > 0){
    n =  n /10;
    r++;
    }

    return r;
}


//
int mystrlen(char str[]) {
	    int c =0;
	    while ( str[c] != '\0'){
	    c++;
	}

	    return c;
	}


<<<<<<< HEAD
char *strcat (char s1[], char s2[]){

=======

char *strcat1 (char s1[], char s2[]){
int i = 0 , j = 0;


for (i = 0; s1[i] != 0; i++);

//while (s1[i] != '\0')
//	i++;

for (j = 0; s2[j] != '\0'; i++, j++) {
      s1[i] = s2[j];
>>>>>>> c23cbd2e929b459385f88d0370a50452be3c28bd
}
/*
while(s2[j] != '\0')
{
	s1[i] = s2[j];
	i++;
	j++;
} */

s1[i] = '\0';

return s1;



}



//
int main() {
<<<<<<< HEAD
int a;
a = mystrlen ("hello");
printf("%d\n",a);
=======

char dest[50] = "dest ";

char src[50] = "lol";

//strcpy(src,  "This is source");
//strcpy(dest, "This is destination");

*strcat1(dest,src);
printf("%s\n",dest);
>>>>>>> c23cbd2e929b459385f88d0370a50452be3c28bd
  return 0;
}
