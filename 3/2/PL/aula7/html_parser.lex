%%
/<\/[a-z0-9]+\>         { yytext[yyleng -1] = '\0';
                          printf(")%s\n", yytext+2);
                        }
/<\/[a-z0-9]+           { printf("(%s\n", yytext+1);
                          BEGIN intag;
                        }
<intag>\>               BEGIN conteudo;
<intag>\/\>             BEGIN 0;
<intag>[a-z]+=\"[^"]+\" printf("A %s\n", yytext);
<conteudo[^<]+          { printf("- %s\n", yytext);
                          BEGIN 0;
                        }
