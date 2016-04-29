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

////////////////////////////////////////////////////////
LInt reverseL(LInt l){

LInt atual, anterior, proxima;
atual = l;
anterior = NULL;

while(atual != NULL){
	proxima = atual->prox;
	atual->prox = anterior;
	anterior = atual;
	atual = proxima;
}


l = anterior;
return l;

}

////////////////////////////////////////////////////////

void insertOrd (LInt *l, int x){
LInt *aux;

aux = l;

while((*aux != NULL) && (*aux)->valor < x )
	aux = &(*aux)->prox;

*aux = newLInt (x,*aux);

}

////////////////////////////////////////////////////////
int removeOneOrd (LInt *l, int x){
LInt* aux = l;

while(*aux != NULL && (*aux)->valor < x)
	aux = &(*aux)->prox;

if (*aux == NULL) return 1;

LInt novo = *aux;
*aux = novo->prox;
novo->prox = NULL;

return 0;
}

////////////////////////////////////////////////////////
LInt clone(LInt l) {
  LInt res = NULL;
  LInt *aux = &res;


  while (l != NULL) {
    *aux = newLInt(l->valor, NULL);
    l = l->prox;
    aux = &((*aux)->prox);
  }

  return res;

}



/*LInt clone(LInt l){
   if(l == NULL ) return NULL;

    LInt aux = newLInt(l->valor,NULL);
   LInt a =&(aux);
   l = l->prox;

   while(l != NULL){
    aux->prox = newLInt(aux->valor,NULL);
    l = l->prox;
   }

return a;
}
*/


////////////////////////////////////////////////////////
int main(){

  LInt a = newLInt(40,NULL);
	LInt b = newLInt(30,a);
	LInt c = newLInt(20,b);
	LInt d = newLInt(10,c);
	LInt e = newLInt(80,d);
	LInt f = newLInt(10,e);
	LInt g = newLInt(5,f);
	LInt h = newLInt(20,g);
  h = reverseL(h);
  imprimeL(h);
  return 0;
}

