%{
  #include "tokens.h"
%}
%%
[ \t\n];
, return VIRG;
\[ return ABRE;
\] return FECHA;
(\+|-)?[0-9]+  return INT;
