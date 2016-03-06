#include <stdio.h>
#include <string.h>
//5 numero de 1 em binario de um certo numero
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


// 6numero de zeros em binario na representaçao final
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
//7
int qDig (int n) {
    int r = 0;

    while (n > 0){
    n =  n /10;
    r++;
    }

    return r;
}


//8
int mystrlen(char str[]) {
	    int c =0;
	    while ( str[c] != '\0'){
	    c++;
	}

	    return c;
	}


//9
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



}//10
char *mystrcpy(char s1[], const char s2[]) {
  int i = 0;
  int j = 0;

  for(j; s2[j] != '\0'; j++);

  for(i , j; i<j ; s1[i]=s2[i] , i++ );

  s1[j] = '\0';
  return s1;
}
//11
int strcmp1 (char s1[], char s2[]){
  int i = 0;

    for(i;((s1[i]==s2[i]) && (s1[i] != '\0') && (s2[i] != '\0' ) ); i++);

  return (s1[i] - s2[i]);
}
//12
 char *strtr (char s1[], char s2[]){
   int i = 0;

}

//13
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

//14
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
//15
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

//16esta mal esta 9 em 10 
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
//17
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




//18esta mal 7 - 10 
int difConsecutivos (char s[]) {
  int i = 0, g=1,m=0;
  while (s[i]!='\0'){
    if (s[i]!=s[i+1]) {
      if (g>m)
        m=g;++g;
    }
    else {
      if (g>m) m=g;
      g=1;
    }
    ++i;
  }
  return m;
}
//19
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
//20
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
//21esta mal 
int sufPref (char s1[], char s2[]){
  int l = 0, i=0,v,t,a,b,c,k=0;
  char j;

  for(t=0; s2[t]!='\0'; t++);
  t = t-1;

  for(i=0 , v; i<v; i++, v--){
    j= s2[i];
    s2[i] = s2[v];
    s2[v] = j;
  }

  for(a=0; s1[a] != '\0' ; a++){
    for(a, b= t, c=0 ; s1[a]== s2[b] ; a++, b--, c++){
      if(k<c) k =c;
  }
  }
  return k;
}
//22 8 de 10 
int contaPal (char s[]){
  int a, c ;

  for (a=0, c=1 ; s[a] != '\0'; a++){
    if ((s[a] == ' ') && (s[a+1] != '\0' ) && (s[a+1] != ' ' ) )
          c++;
  }

  if (a == 0)
          return 0;
 else return c; 

}

int vogal2 (char x){
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

//23
int contaVogais (char s[]){
  int j, i=0;

  for(j= 0; s[j] != '\0'; j++){
    if ((vogal2( s[j]) == 1))
      i++;
      
    }
  return i;
  
}
//24 8 de 10 nao esta bem. nao sei porque 
int contida (char a[], char b[]){
  int y, c=0, z=0, t;

  for(t=0; a[t] != '\0'; t++);
  
    for(y=0; a[y] != '\0' ; y++){
      while ( b[c]!= '\0' && b[c] != a[y] && a[y] != ' '){
        c++;
      }
      if (a[y] == ' ') z++;
      else if (b[c] == a[y]) z++;
    }
    if (t==z)
    return 1 ;
    else return 0;
}
//25
int palindroma (char s[]){
  int t, l, i = 0,v;
  

  for (l=0; s[l] != '\0' ; l++);
  v = l/2;
  t= l -1 ;
  
  while(i<t && s[i] == s[t]){
 

    i++;
    t--;
  }
 if (v == i ) return 1;
 else return 0;
}
//26
int remRep (char t[]){
  int j= 0, i=0,l ;

  while (t[j] != '\0'){

    while ( (t[j+1])  == (t[j]))  {
      j++;
    }
    t[i] = t[j];

    if(t[i] != '\0'){
      i++;
      j++;
    }
  }
  t[i] = '\0';

  for (l=0; t[l]!='\0';l++);
  return l;
}
//27
int limpaEspacos (char t[]){
  int j= 0, i=0,l ;

    while (t[j] != '\0'){

      while ( (t[j]) == ' ' &&  (t[j+1]  == ' ')  ){
        j++;
      }
      t[i] = t[j];

      if(t[i] != '\0'){
        i++;
        j++;
      }
    }
    t[i] = '\0';

       for (l=0; t[l]!='\0';l++);
   return l;
  }
//completamente mal
//28 nem percebo a pergunta !!
void insere (int v[],int N, int x){
  int t ;
  char temp, a ;
  for(t=0; v[t] != '\0' ; t++);
  temp = v[N];
  v[N] = x;
  while ((N+1)<(t+1)){
      a = v[N+1];
      v[N+1] = temp;
      temp = a;
      N++;
    }
      v[t+1] = '\0';
      }



//29
void merge (int r [], int a[], int b[], int na, int nb){
  int i, j, k;
  i = 0; j = 0; k = 0;
 
  while (i<na && j<nb ){
    if (a [i] < b [j]){
      r [k] = a [i];
      i++;
        
    }
    else {
      r [ k ] = b [ j ];
      j++;
    
    }
    
    k++;
  }
    
  if (j>= nb){
    while (i<(na)){
      r[k] = a[i];
      i++;
      k++;
    }
  }
  if (i>=na){
    while (j<(nb)){
      r[k] = b[j];
      j++;
      k++;
    }
  }
}
/*
int retiraNeg (int v[], int N){
  int j= 0, i=0 ;

  while (j<N){

    while ( (v[j]) <0  ){
      j++;
    }
    v[i] = v[j];

    if(i < N ){
      i++;
      j++;
    }
  }
  return i;
}
*/
//30 
int crescente (int a[], int i, int j){
  
}




// 31  so da 7-10 nao sei porque 
int retiraNeg (int v[], int N){
  int j= 0, i=0 ,l=0;

  while (j<(N)){

    while ( (v[j]) <0  ){
      j++;
    }
    v[i] = v[j];

    if ( j >= N){
      j++;
    }
    else{
      i++;
      j++;
    }
  }
  
  return i;
}





/*
  1 charMaisfreq (9-10 )
  2 difConsecutivos (7-10)
  3 sufPref (totalmente mal 2-10)
  4 contaPal (8-10)
  5 contida (8-10)
  6 insere(completamente mal a pergunta e toda esquecida)

*/




int main() {
  int a;
  int v[1] = {9};
  int c[9] = {0,-1,3,4,5,9,10,-2,-2};
char dest[50] = "1,2,3";

char src[50] = "lol";

//strcpy(src,  "This is source");
//strcpy(dest, "This is destination");

a = retiraNeg(c,9);
 printf("%d\n",a/*,a[5],a[6],a[7]*/);
  return 0;
}
