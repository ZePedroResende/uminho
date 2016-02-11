#include <stdio.h>
/* 12 , 16
   0  0 
   A 65 e  B 66 2 50 
  100 200
  128 -100
  

  3 6 
  11 66 
  10  34
  " # # # # # # # # # #" ( enquanto for par poem um espaço, se nao poem um cardinal )
  "abcdefg
   bcdefg
   cdefg
   defg
   efg
   fg
   g"
   
*/









/*
void f (int x){

float y;

for (y = x; (y > 0); (y--) )
    for (y = x; (y>0); (y--))
      putchar ('#'); 
  putchar ('\n'); 
}

int main() {

  float x;
  float z;

scanf ("%f", &x);


for (z = x ; (z > 0) ; z-- ) 
  f(x);

return 0;
}
 */










/*
void g (int x){

int y;

for (y = x; (y > 0); (y--) )
    for (y = x; (y>0); (y--))
      if (y%2 == 0) 
        putchar ('_');
      else  putchar ('#');
  putchar ('\n'); 
}

void f (int x){

int y;

for (y = x; (y > 0); (y--) )
    for (y = x; (y>0); (y--))
      if (y%2 == 0) 
        putchar ('#');
      else  putchar ('_');
  putchar ('\n'); 
}

int main() {

  int x;
  int z;

scanf ("%d", &x);


for (z = x ; (z > 0) ; z-- ) 
  if (z%2 == 0)
    f(x);
  else g(x);

return 0;
}

*/





/*
int main() {

int x;
scanf ("%d", &x);


for (int z = 1 ; (z < x) ; z++ ) {
for (int y = z; (y>0); (y--)) 
         putchar ('#');
    putchar ('\n'); 
}

for (int z = x ; (z > 0) ; z-- ) {
for (int y = z; (y>0); (y--)) 
          putchar ('#');
    putchar ('\n'); 
}

return 0;
}

*/

/*
int main() {

int n;
scanf ("%d", &n);



for(int i=0;i<n;i++) { 
   for(int j=0;j<n-i-1;j++)
      putchar(' ');
    for(int j=0;j<i*2+1;j++)
      putchar('#');
    putchar ('\n'); 

}

return 0;
}

*/
/* 3 , 5 ;
 3, 5 , 3 , 5 ; 
 4 , 5 , 4 ,5 ; 
 4 ,9 , 4 , 5  ;
 4, 9, 4 , 4 ; 
 9 + 4 = 13

int main(){
  int i, j, *a, *b;
  
  i=3; j=5;
  a = &i ; b = &j;
  i++;
  j = i + *b;
  b = a;
  j = j + *b;
  printf("%d\n",j);

  return 0 ;
}
*/
/*
void init (int a) {
  a = 0 ;
}

int main(){
  int x;
  

  init (x);
  printf("%d\n", x );
  return 0;
}
*/
/*
void swap (int *x , int *y){
 int a , b;
 a = *y;
 b = *x;
 *x = a;
 *y = b;
}

int main()
{
  int x= 3,  y= 5 ;
  swap (&x, &y);
  printf("%d %d\n",x ,y );
 
  return 0;
}
*/

/*
int mult (int n, int m) {
  int r;
  if (n>0)
    r = m + mult (n-1, m);
  else r = 0;

  return r;
}

*/

int main (){
 int r, n , m; 

  r = n * m
return 0
}

