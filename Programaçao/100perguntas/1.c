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
/* 1 2 NULL
 *
 * atual = 1
 * anteior = NULL
 *
 * proxima = 2 
 * atual->prox = NULL
 * anteiror = 1
 * atual = 2 
 *
 *
 *
 * proxima = NULL 
 * atual->prox = 1
 * anterior = 2 
 * atual = NULL
 */
/*
 LInt reverseL (LInt l){
 Lint anterior = NULL;
 LInt proximo;

 while (l != NULL){
 proximo = l->prox;
 l->prox = anterior;
 anterior = l
 l = proximo
 }
 }
 */
////////////////////////////////////////////////////////
void insertOrd (LInt *l, int x){
    
  LInt novo = newLInt(x,NULL);
  LInt aux = *l;
  
  if (aux == NULL || aux->valor > x){
    *l = novo;
    novo->prox = aux;
    return;
  }
  
  while (aux->prox!=NULL && (aux->prox->valor)<x){
    aux= aux->prox;
  }
  
  novo->prox = aux->prox;
  aux-> prox = novo;
}
/*
void insertOrd (LInt *l, int x){
LInt *e;

e = l;

while((*e != NULL) && (*e)->valor < x )
e = &((*e)->prox);

*e = newLInt (x,*e);

}

*/

////////////////////////////////////////////////////////
int removeOneOrd (LInt *l, int x){
LInt* aux = l;

while(*aux && (**aux).valor != x){
    aux = &(*aux)->prox;
}


if (*aux == NULL) return 1;

LInt novo = *aux;
*aux = novo->prox;
novo->prox = NULL;


return 0;
}

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

