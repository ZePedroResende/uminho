#include <stdio.h>

int main() {

int r ,b, a;
r = b = 0;

scanf("%d",&a);

while (a != 0){
b++;
  r += a;
  scanf("%d",&a );

}
  r  = r / b ;

printf("%d\n", r );
  return 0;
}
