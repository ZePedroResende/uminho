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

int pop (Stack *st, int *t){
    LArrays aux;
    int i,j,sucesso;
    sucesso = 1; // Nуo
 
    for (i=0; i <= ((*st)->sp);i++){
 
        if ((*st)->valores[i] == &(*t)){
            j=i;
 
            while(i < BSize){
                (*st)->(s.valores[i]) = (*st)->(s.valores[i+1]);
                i++;
            }
            sucesso = 0; //Sim
            break; // ciclo for
        }
    }
 
    if ((j == 0) && ((*st)->sp == 1)) {
        aux = (*st)->s->prox;
        free((*st)->s);
        (*st)->s = aux;
        if (((*st)->s) != NULL) {(*st)->sp = BSize;}
        else {sucesso = 1;} 
    }
    else {((*st)->sp)-- ;}
 
    return sucesso; 
}



typedef struct spares
{
	int x, y;
	struct spares *prox;
};

typedef struct slist
{
	int valor;
	struct slist *prox;
}Nodo, *LInt;



LPares zip(LInt a,LInt b, int *c){
LPares nova = NULL;
LPares head = nova;
 *c = 0;
	while(a != NULL && b != NULL){
		nova = (LPares) malloc(sizeof(LPares));
		
		nova->x = a->valor;
		nova->y = b->valor;
		nova->prox = NULL;
		a = a->prox;
		b = b->prox;
		nova = nova->prox;
		*c++;
	}

	return head;
}


typedef struct no
{
	int value;
	struct no *esq,*dir,*pai;
}No,*Tree;


void calculaPais(Tree t){
	if(t!= NULL){
		if(t->dir != NULL) t->dir->pai = t;
		if(t->esq != NULL) t->esq->pai = t;
		calculaPais(t->dir);
		calculaPais(t->esq);
	}
}


Tree next(Tree t){
	Tree ret = NULL; 
	if(t != NULL){
	if(t->esq != NULL) ret = t->esq
	else  ret= t ; 
	}

	return ret;
}