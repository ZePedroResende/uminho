#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;


LInt newLInt(int n, LInt l){
  LInt new;
  new=(LInt) malloc(sizeof(LInt));
  new->valor = n;
  new->prox = l;
  return new;
}

/*
LInt newLInt(int n, LInt l){
  LInt new;
  LInt aux=l;
  new=(LInt) malloc(sizeof(LInt));

  new->valor=n;
  new->prox=NULL;

  if(l==NULL){
      return NULL;
  }

  for(aux=l; aux->prox!= NULL ; aux = aux->prox);

  aux->prox=new;
  return aux;
}
*/


//////////////////////////////////////////////////////////////
int length (LInt l) {
  int a=1;
  LInt aux = l;
if(l==NULL)return -1;
 while(aux->prox != NULL ){
   a++;
   aux = aux-> prox;
 }
  return a;
}




/////////////////////////////////////////////////////
//temos de libertar apontador a apontador 
void freeL (LInt l){
  LInt aux = l;
  while(l!=NULL){
    l=l->prox;
    free(aux);
    aux=l;
  }
}

///////////////////////////////////////////////////////
void imprimeL (LInt l){
  while(l != NULL){
    printf("%d\n",l->valor);
    l=l->prox;
  }
}

LInt reverseL(LInt l){
  int x =length(l);
  int i=0;
  while(i<x){
    
  }
}



int main(){

  LInt a = newLInt(40,NULL);
	LInt b = newLInt(30,a);
	LInt c = newLInt(20,b);
	LInt d = newLInt(10,c);
	LInt e = newLInt(80,d);
	LInt f = newLInt(10,e);
	LInt g = newLInt(5,f);
	LInt h = newLInt(20,g);

  imprimeL(h);
  return 0;
}

