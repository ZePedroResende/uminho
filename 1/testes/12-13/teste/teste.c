#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int valor;
  struct lista *prox;
}Nodo, *LInt;


int take(int n, LInt *l){
  int i = 0;
  LInt tmp;
  while(*l != NULL && i<n){
    l = &(*l)->prox;
    i++;
  }
  while(*l != NULL){
    tmp = *l;
   *l = (*l)->prox;
    free(tmp);
    tmp = NULL;
  }
  return i;
}

typedef struct abin{
  int valor;
  struct abin *esq, *dir;
}Nodo, *Abin;



int maiores(Abin a, int x){ 
  if(a != NULL){
    if(a->valor > x)
      return 1 + maiores(a->esq, x);
    else return maior(a->dir,x);
  }
  return 0;
}

typedef struct bloco{
  int quantos;
  int valores;
  struct bloco *prox;
}Bloco, *LBoco;

int pertence(LBloco l, int x){
    while(l != NULL ){
      int i = 0;
      while(i < N){
        if(l->valore[i] == x) return 1;
        i++;
        }
l = l->prox;
    }
return 0;
}

int acrescenta(LBloco *l, int n){
int r = 1;
while(*l != NULL){
  if((*l)->quantos < 3){
(*l)->valores[(*l)->quantos] = n;
r = 0;
break;

  }
  else l = &(*l)->prox;

}

   if(*l == NULL){
     *l = (LBloco) malloc(sizeof(LBloco));
     (*l)->quantos = 1;
     (*l)->valores[0] = n
     (*l)->prox = NULL;
r = 0;
   }

return r;
}
