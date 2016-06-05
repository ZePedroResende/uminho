#include <stdio.h> 

typedef struct slist{
int valor;
struct slist *prox;
}*LInt 

typedef struct nodo{
int valor;
struct nodo *esq, *dir;
}*ABin;

int bitsUm (unsigned int){
int i = 0;
while(n!=0){
i = n%2;
n = n/2;
}
return i;

}

int limpaEspacos (char t[]){
int i = 0;
int j = 0;
    while(s[i] != \0 ){
	if(s[i] == ' ' && s[j] == ' ' ){
	i++;
	j++;
	}
    }
s[j] = '\0';
return j;
}

int dumpL (LInt l, int v[], int N){
  int i = 0; 

	while(i != N && l != NULL){
	  v[i] = l->valor;
	  l = l->valor;
	  i++;
	}
  return i;
}

LInt parte(LInt l){
LInt r;
LInt* d = &r;
LInt* u = &l;

int i = 0;

while(*u != NULL){
	if(i%2 == 1){
 	 *d = *u;
	 *u = (*u)->prox;
	 d = &(*d)->prox; 
	} 
	
	else{
	 u = &(*u)->prox;
	}
  i++;
}

*d = NULL;

return r;
}

typedef struct nodo {
  char nome[50];
  int numero;
  int nota;
  struct nodo *esq, *dir;
}*Alunos;

int fnotasAux(Alunos a, int notas[]){
  int r = 0;
  if(a != NULL){
    notas[a->nota]++;
    r = 1 + fnotasAux(a->dir,notas);
    r += fnotasAux(a->esq,notas);
  }
  return r ;
}

int fnotas(Alunos a, int notas[]){
  for(i=0;i<21;i++){
    notas[i] = 0;
  }
  int i = 0;
  i = fnotasAux(a,notas)
return i;
}

//fiz de maneira contraria porque nao li o enunciado :/
int rankAluno(Alunos a, int numero, int fnotas[]){
  int n = daNota(a,numero);
  int i = 0;
  n++;
  while(n<21){
    i +=fnotas[n];
  }
  return i;
}


int daNota(Alunos a, int numero){
  while(a->numero != numero && a->prox != NULL){
    if(a->numero < numero) a = a->dir;
    else a->esq;
  }

  return a->nota;
}

typedef struct strlist{
  char *string;
  struct strlist *prox;
}*StrList

int comNota(Alunos a, int nota, StrList *l){
  int i = 0;
  if(a!= NULL){
     if(a->nota == nota){
       *l = malloc(sizeof(StrList))
       (*l)->(*string) = (a->nome);
       (*l)->prox = NULL;
       l = &(*l)->prox;
       i++;
     }
    i += comNota(a->dir,nota,l);
    i += comNota(a->esq,nota,l);
  }
  return i;
 }

/// ta a ideia nao me apetece terminar a preencheNota tem de retornar o int para calcular o apontador do array e esso isso

void preencheNota (ABin a, int n, int v[],int quantidade,int teste){
  int i =0;
  int numero = 0
  if(a!=NULL && quantidade != 0 ) {
    if(n== a->nota){
      v[i] = a;
      i++;
    }
    else{
      preencheNota(a->esq,n,v+1,quantidade-1,teste);
      preencheNota(a->dir,n,v+(teste-quantidade),quantidade,teste);
    }
    
  }
    
}


void preenche(Alunos a, Alunos t[], int freq[21]){
  int i = 20;
  int a = fnotas(a,freq[21]);
  while(a>=0){
    t[a]=0;
    a--;
  }

  while(i>=0){
    if(freq[i] != 0){
      preencheNota(a,i,t,freq[i],freq[i]);
      t = t+freq[i];
    }
    i++;
  }
  
}
