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



char *strcat1 (char s1[], char s2[]){
int i = 0 , j = 0;


for (i = 0; s1[i] != 0; i++);

//while (s1[i] != '\0')
//	i++;

 for (j = 0; s2[j] != '\0'; s1[i] = s2[j],i++, j++) {
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
char *mystrcpy(char s1[], const char s2[]) {
  int i = 0;
  int j = 0;

  for(j; s2[j] != '\0'; j++);

  for(i , j; i<j ; s1[i]=s2[i] , i++ );

  s1[j] = '\0';
  return s1;
}

int strcmp1 (char s1[], char s2[]){
  int i = 0;

    for(i;((s1[i]==s2[i]) && (s1[i] != '\0') && (s2[i] != '\0' ) ); i++);

  return (s1[i] - s2[i]);
}

 char *strtr (char s1[], char s2[]){
   int i = 0;

}


void strrev (char s[]){
  int l= 0,  i = 0,v;
  char a;

  for (l; s[l] != '\0' ; l++);

  v= l-1;

  while (i<v){
      a = s[i];
      s[i]=s[v];
      s[v]= a;
      i++;
      v--;
  }
  /*for(i,v; i<v; i++, v--){
  a= s[i];
s[i] = s[v];
s[v]=a;
}
  */
}


int vogal1 (char x){
  switch(x){
  case 'a':
  case 'A':
  case 'e':
  case 'E':
  case 'i':
  case 'I':
  case 'o':
  case 'O':
  case 'u':
  case 'U':
    return 1 ;
  default:
    return 0;
  }
}


void strnoV (char s[]){
  int j= 0, i=0;

  while (s[j] != '\0'){

      while (vogal1 (s[j]) ){
      j++;
      }
    s[i] = s[j];

    if(s[i] != '\0'){
        i++;
        j++;
    }
  }
 s[i] = '\0';

}

void truncw (char t[], int n)
{
	int i, j = 0, x;
	for(i = 0; t[i] != '\0'; i++, j++)
    {
      for(x = n;(x > 0) && (t[i] != ' ') && (t[i] != '\0'); x--, i++, j++)
        t[j] = t[i];
      while((t[i] != '\0') && (t[i] != ' '))
        i++;
      t[j] = t[i];
    }
	t[j] = '\0';
  }
/*
void truncw (char t[], int n){
  int i, x , j=0 ;
  for(x=n; (x>0) && (t[i] != ' ') && (t[i] != '\0'); x--, i++, j++){
      t[j]=t[i];
  }
  while ((t[i] != '\0') && (t[i] != ' ')){
      i++;
  }
    t[j] = t[i];

    t[j]= '\0';
}*/
//void truncW (char s[]){ 
//}

int main() {
  int a ;

char dest[50] = "dest ";

char src[50] = "lol";

//strcpy(src,  "This is source");
//strcpy(dest, "This is destination");

truncw(dest, 2);
 printf("%s\n",dest);
  return 0;
}
