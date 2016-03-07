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

char *strstr_1 (char s1[], char s2[])
{
  int i = 0;
  char *res = NULL;
  int len = strlen (s2);
  
  while((s1[i] != '\0') && (res == NULL))
  {
    if((s1[i] == s2[0]) && (strncmp (&s1[i], s2, len) == 0))
      res = &s1[i];
    i++;
  }
  return res;
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

//esta mal esta 9 em 10 
char charMaisfreq (char s[])
{
  int i;
  int aux[256] = {0};
  char res = 0;
  
  for(i = 0; s[i] != '\0'; i++)
    aux[(int) s[i]] += 1;

  for(i = 0; i < 256; i++)
    if(aux[i] > aux[(int) res])
      res = i;
  
  return res;
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




//esta mal 7 - 10 
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

int sufPref (char s1[], char s2[])
{
  int size = strlen(s1);
  int i = 0, j, aux1, res = 0, flag = 0;
  
  while((s1[i] != '\0') && (!flag))
  {
    res = 0;
    if(s1[i] == s2[0])
    {
      aux1 = i;
      j = 0;
      while((s1[aux1] != '\0') && (s2[j] != '\0') && (s1[aux1] == s2[j]))
      {
        aux1++;
        j++;
        res++;
      }
      if(res == (size - i))
        flag = 1;
    }
    i++;
  }
  return res;
}

// 8 de 10 
int contaPal (char s[])
{
  int res = 0, i = 0, flag;
  
  while(s[i] != '\0')
  {
    flag = 0;
    while((s[i] != '\0') && (s[i] == ' '))
      i++;
    while((s[i] != '\0') && (s[i] != ' '))
    {
      i++;
      flag = 1;
    }
    if(flag == 1)
      res++;
  }
  return res;
}

int contaVogais (char s[])
{
  int i, res = 0;
  for(i = 0; s[i] != '\0'; i++)
  {
    switch (s[i])
    {
      case 'a' :
      case 'e' :
      case 'i' :
      case 'o' :
      case 'u' :
      case 'A' :
      case 'E' :
      case 'I' :
      case 'O' :
      case 'U' : res++;
    }
  }
  return res;
}
  
}
// 8 de 10 nao esta bem. nao sei porque 
int contida (char a[], char b[])
{
  int flag = 1, i = 0, j;
  while((a[i] != '\0') && (flag == 1))
  {
    j = 0;
    flag = 0;
    while((!flag) && (b[j] != '\0'))
    {
      if(b[j] == a[i])
        flag = 1;
      j++;
    }
    i++;
  }
  return flag; /* se lista vazia retorna Verdadeiro */
}

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


void insere (int v[], int N, int x)
{
  int i = 0;
  if(N > 0)
  {
    if(v[0] <= v[N-1])
    {
      while((i < N) && (v[i] < x))
        i++;
    }
    else
    {
      while((i < N) && (v[i] > x))
        i++;
    }
    while(N > i)
    {
      v[N] = v[N-1];
      N--;
    }
  }
  v[i] = x;
}


// da 0-10 deve tar certa !!!
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

int crescente (int a[], int i, int j)
{
  int res = 1;
  while((res == 1) && (i < j))
  {
    if(a[i] > a[i++])
      res = 0;
    i++;
  }
  return res;
}



// so da 7-10 nao sei porque 
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
  2 difConsecutivos (7-10) ( pode ser da codeboard)
  merge 
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
