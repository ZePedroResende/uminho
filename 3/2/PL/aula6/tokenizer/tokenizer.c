#include "tokens.h"
#include "stdio.h"

extern int yylex();

int main(){
int prox_simb;

while((prox_simb = yylex())){
  switch(prox_simb){
    case ABRE: printf("ABRE");
               break;
    case FECHA: printf("FECHA");
               break;
    case VIRG: printf("VIRGULA");
               break;
    case INT: printf("INT");
               break;
    default: printf("ERRO");
  }
}


}
