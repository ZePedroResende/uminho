# include <stdio.h>

int main(){
  int a, b ;
  b = 0 ;
 
  scanf("%d",&a );
  
  if (a !=0){

  while (a != 0){
    b += a;
    scanf("%d",&a);
  }
  printf("%d\n",b);  
  }
  else  printf("%d",b);

  return 0; 
}
