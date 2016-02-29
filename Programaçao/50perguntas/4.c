#include <stdio.h>

int main ()
{
  int a ;
  int b = 0;
  int c = 0;
  int d = 0;
  scanf("%d",&a);


while(a != 0){
  if ((b >= a) && (a >= c)){
          c = a;

     scanf("%d",&a);
    }
  else ((b <= a) && (a >= c));{
      b = a;
      scanf("%d",&a);
  }
 }
  printf("%d\n",b);

  return 0;
}
