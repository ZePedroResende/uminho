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

//esta mal esta 
char charMaisfreq (char s[]){
  int x, y=0, z=0,k=0,i;
  char a;

  for (x=0; s[x] != '\0'; x++);

  if (x == 0)
    return 0 ;

  else{
    for(y=0; s[y] != '\0'; y++){
      for (z=0, i=0; s[z] != '\0'; z++){
        if (s[y] == s[z])
          i++;

      }
      if ((k< i) && (s[y] != ' ') ){
        k= i;
        a = s[y];
      }
          }
    return a;
  }
}

int iguaisConsecutivos (char s[]) {
  int  y=0, z, a=0, x=0 ;
  for(y=0; s[y] != '\0'; y++){
    for (z=0 , x=y  ; s[x] == s[y];x++, z++);
    if (a< (z) ){
      a = (z) ;
    }
  }
  return a;
  
}




//esta mal
// esta mal 
int difConsecutivos (char s[]){
  int  y=0, z, a=0, x=0 ;
  for(y=0; s[y] != '\0'; y++){
    for (z=0 , x=y+1  ; s[x] != s[y]; y++, z++);
    if (a< (z) ){
      a = (z) ;
    }
  }
 

  }

int maiorPrefixo (char s1 [], char s2 []) {

  int a = 0;
  int b = 0;
  int c = 0;

  while (s1[b] == s2[c]){
    a++;
    b++;
    c++;
  }
  return a;
}

int maiorSufixo (char s1[], char s2[]){
  int i= 0;
  int o = 0;
  int a = 0;

  for(i=0; s1[i] != '\0'; i++);

  for(o=0; s2[o] != '\0'; o++);

  i--;
  o--;

  while (s1[i] == s2[o]){
    a++;
    i--;
    o--;
  }
  
  return a; 
}

int sufPref (char s1[], char s2[]){
  
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

 a = difConsecutivos("oola");
 printf("%d\n",a);
  return 0;
}
