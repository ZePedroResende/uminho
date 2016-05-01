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

LInt remove = *aux;
*aux = remove->prox;

return 0;
}
////////////////////////////////////////////////////////

LInt merge(LInt *r, LInt a, LInt b){ 

LInt *aux = &(*r);        

while(a != NULL && b != NULL){
        if(a->valor < b->valor){
           *r = newLInt(a->valor,NULL) ;
           a=a->prox;
           r = &(*r)->prox;         
        }   
        else{
         *r = newLInt(b->valor,NULL) ;
           b=b->prox;
           r = &(*r)->prox;         
        }   
    }   
if (a !=NULL){
*r = a;
                   
}

else{
*r = b;
}
return *aux;
}
/*
LInt merge(LInt *r, LInt a, LInt b){ 

LInt *aux = &(*r);        

while(a != NULL || b != NULL){
        if(b == NULL || (a->valor < b->valor)){
           *r = newLInt(a->valor,NULL) ;
           a=a->prox;
           r = &(*r)->prox;         
        }
        
        if(a == NULL || (a->valor > b->valor)){
         *r = newLInt(b->valor,NULL);
           b=b->prox;
           r = &(*r)->prox;         
        }   
    }   

return *aux;
}

*/
//////////////////////////////////////////////////////
void splitMS (LInt l, int x, LInt *mx, LInt *Mx){
  while(l !=NULL) {
    if (l->valor < x) {
      *mx =newLInt(l->valor,NULL); // insere nó na lista dos menores
      mx = &((*mx)->prox); // endereço onde continua lista dos menores
    } else {
      *Mx = newLInt(l->valor,NULL); // insere nó na lista dos maiores
      Mx = &((*Mx)->prox); // endereço onde continua lista dos maiores
    }
    l = l->prox;
  }
}


///////////////////////////////////////////////////////
LInt parteAmeio (LInt *l){
int i=0, c=0;
LInt* head = l;
LInt res = NULL;
LInt *aux = &res;

  while(*l != NULL){  //calcula length
  c++;
  l = &(*l)->prox;
  }

l = &(*head); // volta a por o l a aopontar para a cabeça 
c = c/2;

  while(i<c){
  *aux = newLInt((*l)->valor, NULL);
  aux = &((*aux)->prox);
  l = &(*l)->prox;  
  i++;
  }

*head = *l;
return res;
}


/*

LInt parteAmeio (LInt *l){
int i=0, c=0;

LInt* head = l;

LInt res = NULL;
LInt *aux = &res;

LInt res2 = NULL;
LInt *aux2 = &res2;

  while(*l != NULL){  //calcula length
  c++;
  l = &(*l)->prox;
  }

  l = &(*head);
  c = c/2;

  while (*l != NULL){
  if(i<c){
    *aux = newLInt((*l)->valor, NULL);
      aux = &((*aux)->prox);
  }
  else{
   *aux2 = newLInt((*l)->valor,NULL); 
    aux2 = &((*aux2)->prox);
  }
  l = &(*l)->p*rox;  
  i++;
  }

*head = res2;
return res;
}

*/

////////////////////////////////////////////////////////
LInt cloneL(LInt l) {
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
LInt i;
  LInt a = newLInt(40,NULL);
	LInt b = newLInt(30,a);
	LInt c = newLInt(20,b);
	LInt d = newLInt(10,c);
	LInt e = newLInt(80,d);
	LInt f = newLInt(90,e);
	LInt g = newLInt(5,f);
	LInt h = newLInt(20,g);
  i = parteAmeio(&h);
  imprimeL(h);
  printf("ola\n");
  imprimeL(i);
  return 0;
}

