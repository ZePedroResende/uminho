%x formato
%%
[ \t\n] ;
printf printf("PRINTF");
\( printf("PABRE");
\) printf("PFECHA");
,  printf("VIRG");
;  printf("PVIRG");
\& printf("OP_END");
[_A-Za-z][A-Za-z0-9]* printf("ID");

\"  BEGIN formato;
.   printf("ERRO");

<formato>\" BEGIN 0;
<formato>\%[dxfsc] printf("MOD ");
