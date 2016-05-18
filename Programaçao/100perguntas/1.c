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




typedef struct nodo{
int valor;
struct nodo *esq, *dir;
}*ABin;



ABin newABin(int n, ABin e, ABin d){
  ABin new; 
  new = (ABin) malloc(sizeof(ABin));
  new->valor = n;
  new->esq = e;
  new->dir = d;
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
  int a=0;
  LInt* aux = &l;

 while(*aux != NULL ){
   a++;
   aux = &(*aux)-> prox;
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

while(*l != NULL && (*l)->valor < x){
    l = &(*l)->prox;
}

*l=newLInt(x,*l);
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

void merge(LInt *r, LInt a, LInt b){

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
LInt aux = *l;
LInt* head = l;
LInt* res = l;

if( (*l)->prox == NULL) return NULL;

while(*l != NULL ){
  l = &(*l)->prox;

  if(*l != NULL){
    l = &(*l)->prox;
    res = &(*res)->prox;
  } 
}
 
*head = (*res);
*res = NULL;
 
return aux;
}


////////////////////////////////////////////////////////
int removeAll (LInt *l, int x){
int a =0;
LInt* aux = l;
LInt remov;

while(*aux != NULL ){
    if ((*aux)->valor == x){
    remov = *aux;
    *aux = remov->prox;
    a++;
    }

    else{
     aux = &(*aux)->prox;
    }
}

return a;
}


////////////////////////////////////////////////////////
int removeDups (LInt *l){
int a = 0;
int b = 0;
LInt remov;
LInt *aux;

  while((*l) != NULL){
    b  = (*l)->valor;
    aux = &(*l)->prox;

       while(*aux != NULL ){

          if ((*aux)->valor == b){
          remov = *aux;
          *aux = remov->prox;
          a++;
          }

          else aux = &(*aux)->prox;
       }

    l = &(*l)->prox;
 }

return a;
}
////////////////////////////////////////////////////////
int removeMaiorL (LInt *l){
LInt* head = l; // tem de ser assim ou vai dar merda , believe me.... ( ou poem    LInt *head = l; head =l; e a mesma coisa)
int a = 0;
int flag = 0;
LInt rem;
LInt* aux = l;


while( *l != NULL){ // calcula o maior
if ((*l)->valor > a) a = (*l)->valor ;
l = &(*l)->prox;
}

l = head; // poem o l a apontar para a cabeça outra vez

while(*aux != NULL && flag != 1){
    if((*aux)->valor == a ){
      rem = *aux;
      *aux = rem->prox;
      flag = 1;
    }
    else aux = &(*aux)->prox;  // tem de ter o else se nao no caso de ser NULL NULL da porcaria
}

return a;

}

/////////////////////////////////////////////////////////

void init (LInt *l){
  while((*l) != NULL){
    if((*l)->prox == NULL) {
      free(*l);
      *l= NULL;
    }
    else l = &(*l)->prox;
  }
}


/*void init (LInt *l){
if(*l == NULL) return;

  while((*l)->prox != NULL)
    l = &(*l)->prox;

  free(*l);
  *l = NULL;
}
*/


/*
void init (LInt *l){
  LInt ll = *l;
  LInt ante = ll;
  LInt head = ll;
  ll = ll->prox;
  while (ll->prox){
    ante = ll;
    ll = ll->prox;
  }

  ante->prox = NULL;
  free(ll);
  *l = head;

}
*/
/////////////////////////////////////////////////////////
void appendL (LInt *l, int x){
  while((*l) != NULL)
    l = &(*l)->prox;

  *l = newLInt(x,NULL);
}

////////////////////////////////////////////////////////
void concatL (LInt *l, LInt b){
  while(*l != NULL)
    l = &(*l)->prox;

*l = b;
}

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
LInt cloneRev (LInt l){
LInt a = NULL;

while(l != NULL){
  a = newLInt(l->valor,a);
 l = l->prox;
}

return a;
}

////////////////////////////////////////////////////////
int maximo (LInt l){
  int a=0;
  LInt *aux;
  aux = &l;

  while(*aux != NULL){
    if((*aux)->valor > a) a = (*aux)->valor;
    aux = &(*aux)->prox;
  }

  return a;
}

///////////////////////////////////////////////////////////////////////////////////
//** confirmar esta porque nao tenho a certeza quanto ao free se ta bem ou nao **//
///////////////////////////////////////////////////////////////////////////////////
  int take (int n, LInt *l){
 int a =0;

 while((*l) != NULL){
    if (a < n) {
        l = &(*l)->prox;
    a++;

    }
    else {
   LInt aux = (*l)->prox;
    (*l) = NULL;
    freeL(aux);
    }
 }
 return a;
 }

 ///////////////////////////////////////////////////////////////////////////////
int drop (int n, LInt *l){
 int a =0;
LInt* head = l;
LInt* aux ;


 while(a<n && *l != NULL){
   aux = &*l;
   l= &(*l)->prox;
   free(*aux);
  a++;
  }

*head = *l;

 return a;
}
///////////////////////////////////////////////////////////////////////////////
LInt NForward (LInt l, int N){
 int a =0;
 
LInt* aux = &l;
 
 
 while(*aux != NULL && a<N){
     aux = &(*aux)->prox;
     a++;
 }
 
  return *aux;
}
///////////////////////////////////////////////////////////////////////////////
int listToArray (LInt l, int v[], int N){
  int a=0;
 LInt* aux = &l;

  while(*aux != NULL && a<N){
    v[a] = (*aux)->valor;
    aux = &(*aux)->prox;
    a++;
  }


return a;
}
//////////////////////////////////////////////////////////////////////////////
LInt arrayToList (int v[], int N){
LInt res = NULL;
N--;
while (N >=0){
  res = newLInt(v[N],res);
  N--;
}
return res;
}
///////////////////////////////////////////////////////////////////////////////
LInt somasAcL (LInt l){
int a=0;
LInt res = NULL;
LInt *aux = &res;

while(l != NULL){
  a += l->valor;
  l = l->prox;
  *aux = newLInt(a,NULL);
  aux = &(*aux)->prox;
}

return res;
}

///////////////////////////////////////////////////////////////////////////////
void remreps (LInt l){
int b = 0;
LInt remov;
LInt* res = &l;
LInt *aux;

  while((*res) != NULL){
    b  = (*res)->valor;
    aux = &(*res)->prox;

       while(*aux != NULL ){

          if ((*aux)->valor == b){
            remov = *aux;
           *aux = remov->prox;
          free(remov);
          }

          else aux = &(*aux)->prox;
       }

    res = &(*res)->prox;
 }
}
//////////////////////////////////////////////////////////////////////////////
LInt rotateL (LInt l){
LInt* aux = &l;
LInt primeiro = NULL;

if(*aux != NULL ){
  primeiro = l ;
  l = l->prox;
  primeiro->prox = NULL;
}

while( *aux != NULL){
aux = &(*aux)->prox;
}

*aux = primeiro;
return l ;
}

/////////////////////////////////////////////////////////////////////////////7/

LInt parte (LInt l){

  LInt *n, *e, r;

  n = &r;
  e = &l;

  int i = 0;

  while (*e != NULL){
    if (i%2 != 0){
      *n = *e;
      n = &((*n)->prox);
      *e = (*e)->prox;
    }
    else{
      e = &((*e)->prox);
    }
          i++;
  }

  *n = NULL;

  return r;
}



///////////////////////////////////////////////////////////////////////////////
int altura(ABin l){
int a = 0;

if(l != NULL){
if ( altura((l)->esq) > altura((l)->dir))
a = 1 + altura((l)->esq);
else a = 1 + altura((l)->dir);
}

return a;
}

/*
int altura(ABin l){
int a = 0;

if (l == NULL)
return;


if ( altura((l)->esq) > altura((l)->dir))
a = 1 + altura((l)->esq);
else a = 1 + altura((l)->dir);

return a;
}
*/
///////////////////////////////////////////////////////////////////////////////
ABin cloneAB (ABin a){
ABin new;

if(a == NULL) return NULL;

new = newABin(a->valor, cloneAB(a->esq), cloneAB(a->dir));

return new;

}

////////////////////////////////////////////////////////////////////////////////
void mirror(ABin *a){
if(*a == NULL) return;
 mirror(&(*a)->esq);
 mirror(&(*a)->dir);
 ABin temp = ((*a)->dir);
 (*a)->dir = (*a)->esq;
 (*a)->esq = temp;
}
///////////////////////////////////////////////////////////////////////////////
void inorder (ABin a, LInt *l){
if(a == NULL) return;

inorder(a->dir,l);
*l= newLInt(a->valor,*l);
inorder(a->esq,l);

/*tem de estar ao contrario porque tem de inserir a cabeça !!*/

}

//////////////////////////////////////////////////////////////////////////////
void preorder (ABin a, LInt *l){
if(a == NULL) return;

preorder(a->dir,l);
preorder(a->esq,l);
*l= newLInt(a->valor,*l);




}
//////////////////////////////////////////////////////////////////////////////
void posorder (ABin a, LInt *l){
if(a == NULL) return;



  *l= newLInt(a->valor,*l);
    posorder(a->dir,l);
      posorder(a->esq,l);
}

///////////////////////////////////////////////////////////////////////////////
int depth (ABin a, int x){
  int l = 1;

  if(a == NULL) return -1;


  if(a->valor > x){
    l = 1+depth(a->esq,x);
  }
  
  if(a->valor < x){
    l = 1+ depth(a->dir,x);
  }

  return l;
}
///////////////////////////////////////////////////////////////////////////////
int freeAB (ABin a){
int x = 0;

if(a == NULL) return x;


x = 1+ freeAB(a->dir) + freeAB(a->esq);
free(a);
return x;
}
///////////////////////////////////////////////////////////////////////////////
int pruneAB (ABin *a, int l){
  if(l=0){
    return freeAB(*a);
  }

  return pruneAB(&(*a)->dir, l-1) + pruneAB(&(*a)->esq, l-1);
}

//////////////////////////////////////////////////////////////////////////////
int iguaisAB (ABin a, ABin b){
 if ((a ==NULL && b != NULL) || (a != NULL && b!= NULL)) return 1;


 if(a->valor != b->valor) return 1;


if (iguaisAB(a->esq, b->esq) >0 || iguaisAB(a->dir, b->dir) > 0) return 1;
else return 0;
}
//////////////////////////////////////////////////////////////////////////////
LInt nivelL (ABin a, int n){
LInt l=NULL;
LInt p = NULL; 
if(n=0){
   
      l =  newLInt(a->valor,l) ;
return l;
}
l = (nivelL(a->dir,n-1));
p = nivelL(a->esq, n-1);
    concatL (&l, p);
return l;
}

/////////////////////////////////VER ESTA 39//////////////////////////////////////////////
/*nao sei esta . que preenche o vector v com os
elementos de a que se encontram no n ́ıvel n.
Considere que a ra ́ız da  ́
arvore se encontra no n ́ıvel 1.
A fun ̧c ̃
ao dever ́
a retornar o n ́
umero de posi ̧c ̃oes preenchidas do array.*/


int nivelV (ABin a, int n, int v[]){
int i =0;
    if(a!=NULL ) {
        i = nivelV(a->esq,n-1,v);
        i += nivelV(a->dir,n-1,v+i);
        
        if(n==0){
            v[i] = a->valor;
            i++;
        }
    }
    
return i;
}



/////////////////////////////////////////////////////////////////////////////

/*

int dumpAbin (ABin a, int v[], int N){
int i;

if(a == NULL || i == N) return i;

v[i]  = a->valor;
i++;
if(node->left != NULL && i<N)
  i = dumpAbin(a->esq, v[], N)
}

*/
/////////////////////////////////////////////////////////////////////////
ABin somasAcA (ABin a){
  if(a == NULL) return;

  a->dir = somasAcA(a->dir);
  a->esq = somasAcA(a->esq);
  a->valor = a->valor + (a->dir)->valor + (a->esq)->valor;


  return a;
}
///////////////////////////////////////////////////////////////////////////////
 
///////////////////////////////////////////////////////////////////////////////
void imprimeAB (ABin a){
  if (a==NULL)
    printf("NULL\n");
    //return;
  else{
   printf("%p %d head\n", a, a->valor);
  imprimeAB(a->esq);



  imprimeAB(a->dir);
}
}
///////////////////////////////////////////////////////////////////////////////
int main(){

int x;
  LInt a = newLInt(7,NULL);
	LInt b = newLInt(6,a);
	LInt c = newLInt(5,b);
	LInt d = newLInt(4,c);
	LInt e = newLInt(3,d);
	LInt f = newLInt(2,e);
	LInt g = newLInt(1,f);
	LInt h = newLInt(8,g);
  LInt p;
int v[3]; 
//v[0] = 2;
//v[1] = 3;
//v[2] = 4;
//v[3] = 5;
//LInt q;


 
//  ABin i = newABin(10,NULL,NULL);
//  ABin j = newABin(30,NULL,NULL);
//  ABin k = newABin(20, i, j);
 // ABin l = newABin(5, NULL, k);
//)  mirror(&l);
 // z = somasAcA(l);


  //z = nivelL(l,2);
 //imprimeAB(l);
  p = parteAmeio(&a);
  //printf("%d\n", i );
   imprimeL(a);
  printf("||||||||||||||||||||||||||\n");
  imprimeL(p);
  return 0;
}
