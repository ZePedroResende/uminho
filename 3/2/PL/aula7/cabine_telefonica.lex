/*http://www4.di.uminho.pt/~jcr/AULAS/pl-lei-2015/fichas/pl2015-ficha2.xml.html*/
%x  interacao  moedas
%{
#include <stdlib.h>
float saldo=0;
%}
%%
<*>[ \t\n]                          ;
LEVANTAR                            {BEGIN interacao;printf("maq: INTRODUZIR MOEDAS");};
<interacao>POUSAR                   BEGIN 0;
<interacao>T=6[04]1[0-9]{6,}         {printf("cabine");};
<interacao>T=00[0-9]{6,}            {if(saldo>=1.5){
                                        saldo = saldo -1.5;
                                        printf("cabine = saldo é igual %f", saldo);
                                     }else{
                                        printf("saldo insuficiente");
                                     }}
<interacao>T=2[0-9]{8}              {if(saldo>=0.25){
                                        saldo = saldo -0.25;
                                        printf("cabine = saldo é igual %f", saldo);
                                     }else{
                                        printf("saldo insuficiente");
                                     }}
<interacao>T=800[0-9]{6}            {printf("cabine = saldo é igual %f", saldo);};
<interacao>T=808[0-9]{6}            {if(saldo>=0.10){
                                        saldo = saldo -0.10;
                                        printf("cabine = saldo é igual %f", saldo);
                                     }else{
                                        printf("saldo insuficiente");
                                     }}
<interacao>T=.*                     {printf("cabine: Numero invalido");};
<interacao>MOEDA                    BEGIN moedas;
<moedas>[125]0?c                    { yytext[strlen(yytext)-1] = '\0';
                                      saldo += atof(yytext)/100;};
<moedas>[12]e                       { yytext[yyleng-1] = '\0';
                                      saldo += atof(yytext);
                                    }
<moedas>\.                          { printf("saldo %f\n", saldo);
                                    BEGIN interacao; }
<moedas>,                           ;
<moedas>.                           {printf("MOEDA invalida");};
