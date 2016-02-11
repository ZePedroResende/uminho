#include <stdio.h>
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