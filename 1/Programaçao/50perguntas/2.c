#include <stdio.h>
int main(){
  int a;
  int b;
  b = 0;

  scanf("%d", &a );

  if (a != 0) {

  while  (a !=0) {
    if (a > b){
    b = a;
    scanf("%d", &a);
  }
    else  scanf("%d", &a );
  }
  printf("%d\n", b);
  }
  else printf("%d\n", b);

  return 0;
  }
