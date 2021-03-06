#define MAX 100
/*typedef <type> <ident>; */
typedef struct stack{
  int sp;
  int valor[MAX];
}STACK;

typedef struct stack2{
  int size;
  int sp;
  int *valores;
}STACK2;

typedef struct queue{
  int inicio, tamaho;
  int  valores [MAX];
} QUEUE;



typedef int intptr;
typedef int intArray[MAX];
typedef int myint[MAX];


  void initStack (STACK *s){
     s->sp = 0;
  }

int isEmptys (STACK *s){
  return /*(*s).sp == 0*/ s->sp == 0; /* porque e um boleano por cusa do == logo da return a um booleano */

}

int push(STACK *s, int x){
  if (s->sp == 99) return  1;
  else{ s->valores [s->sp] = x ; // valores[s->sp++] = x;
    s ->sp++;
    return 0;
  }
}

int pop (STACK *s, int *x){
  if (s->sp == 0) return 1;
  else {
    s ->sp--;
    *x = s->valores[s->sp] ;
    return 0 ;
   }
}

int top (STACK *s, int *x){
  if(isEmptys(*s)) return 1;
  else{
    *x = s->valores[s->sp] ;
  return 0;
  }
}

void initQueue (QUEUE *q){
  q->tamanho =0;
  q->inicio =0;
}

int isEmptyQ (QUEUE *q){
  if (q->tamanho == MAX) return 1;
  q->valores[(q->inic + q->tamanho)%MAX] = x;
  q->tamanho++;
  return 0;
 }

/*Memoria Dinamica
  int a;
  int *p;
  p=(int *) malloc (sizeof(int))
void * malloc(long);
void free(void*);
void * calloc(long n, long size);
void * realloc(void *, long);
*/

// vamos precisar tambem de uma funçao freestack(stack *s);


void initstack2(STACK2 *s){
s->sp = 0
s->(valores) = (int *) malloc(100*(sizeof(int)));
s->size = 100;
}
void freestack(stack *s){
  free (s->valores);
  s->size=0;
  s->sp=0;
}


int push (STACK *s,int x){
  if(s->sp == s->size){    /*se for > 0 entao faz o dobro do tamanho se nao da 1 (para garantir que tem pelo menos um)*/ 
    s->size = 2* s->size
     s-> valores = (int*) malloc((s->size >0 ?2*s->size :1) sizeof(int));
    /*s->valores = (int*) realloc(s->valores, 2*s->size);*/
  }
  s->valores[sp] = x;
  s-> sp ++;
  return 0;
}

typedef struct queue2{
  int size;
  int inic , tam;
  int *valores ; 
}QUEUE2;





/* listas ligadas */
typedef struct slist {
int valor;
struct slist *prox;
} Nodo, *LInt;

/*a) ->*[10,5,15]*/

/*i)Lint cons (LInt l, int x); // isere à cabeça
  ii)Lint tail(LInt l) // apagar primeiro elemento
  iii)Lint init(LInt l) // ultimo elemento
  iv)Lint snoc(LInt l, int x); // insere no fim
  v)Lint concat(LInt l1, LInt l2) // l1 ++ l2
  */

LInt cons(LInt l, int x){
 LInt new;
	new =(LInt) malloc(sizeof(Nodo));
    new->valor = x;
	new->prox = l;
return new;
}



LInt tail(LInt l){
 if(l==NULL) return NULL;
 LInt aux = l->prox;
 free(l);
 return aux;
}

LInt init(LInt l){
LInt aux;
for(aux=l; (aux->prox)->prox != NULL ; aux = aux->prox);
free(aux->prox);
aux->prox=NULL;
return l;
}

LInt snoc (LInt l, int x){
	LInt aux = l , new;
	new = (Lint) malloc(sizeof(Nodo));
	new->valor = x;
	new->prox = NULL;

if(l==NULL) return NULL;

while (aux->prox != NULL)
	aux =aux->prox;

aux->prox=new;
return aux; 
}

LInt concat(LInt a, LInt b){
LInt aux;
if(a == NULL) aux = b;
	for(aux=a ; aux->prox != NULL ; aux = aux-> prox);
aux-> prox = b;
/*  return a;*/
return aux;
}


