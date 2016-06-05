typedef struct slist
{
	int valor;
	struct slist *prox; 
	
} *LInt;

LInt fromArray (int v[], int N){
LInt r =NULL;
LInt* aux = &r;
int i = 0;	
	while(i<N){
		*aux = (LInt) malloc(sizeof(LInt));
		(*aux)->valor = v[i];
		(*aux)->prox = NULL; 
		aux = &(*aux)->prox;
		i++;
	}
return r;
}


#define Bsize 100

typedef struct larray
{
	int valores[BSize];
	struct larray *prox;
}*LArrrays;

typedef struct stack
{
	int sp;
	LArrrays s;	
}Stack;

void push (Stack *st, int x){
	if((*st)->sp != BSize)
		(*st)->(s.valores[(*st)->sp++]=x;
	else{
		LArray aux
		aux =(LArrrays) malloc(sizeof(LArrrays));
		aux->prox = sp->s 
		aux->valores[0] = x;
		(*st)->s = aux; 
		(*st)->sp = 1;
	}
}

int pop (Stak *st, int *t){
int a = (*st)->sp ; 
	while()
}