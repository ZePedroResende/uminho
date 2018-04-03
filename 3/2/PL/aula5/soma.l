%{
#include <stdlib.h>
int total = 0;
%}
%%
[0-9]+  total+=atoi(yytext);
.|\n  ;
%%
int yywrap(){
  printf("soma %d\n",total);
}
