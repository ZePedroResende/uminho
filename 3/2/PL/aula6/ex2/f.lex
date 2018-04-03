%{
int linha=1, coluna=1;
%}

%%
\n {linha++;coluna=1;}
(\+|-)?[0-9]+ {
printf("INT(%s,l=%d,c=%d)\n", yytext, linha, coluna);
coluna += yyleng;
}
. coluna++;
