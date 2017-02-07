#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct slist *LInt;

typedef struct slist {
	int valor;
	LInt prox;
} Nodo;

typedef struct nodo *ABin;

struct nodo {
	int valor;
	ABin esq, dir;
};


LInt newLInt (int v, LInt p){
	LInt new = (LInt) malloc(sizeof(struct slist));
	new->valor = v;
	new->prox = p;
	return new;

}


ABin newABin(int valor, ABin esq, ABin dir){
	ABin new = (ABin) malloc(sizeof(struct nodo));
	new->valor = valor;
	new->esq = esq;
	new->dir = dir;
	return new;
}

//////////////////// QUESTAO 1 ////////////////////

int length (LInt z){
	LInt aux = z;
	int count = 0;
	if (z==NULL)
		return 0;
	while (aux->prox!= NULL){
		count++;
		aux = aux->prox;
	}
	count ++;
	return count;
}

//////////////////// QUESTAO 2 ////////////////////

LInt clone (LInt z){
	if (z==NULL)
		return NULL;
	LInt new = newLInt(z->valor,NULL);
	LInt head = new;
	while (z->prox!=NULL){
		z=z->prox;
		new->prox=newLInt(z->valor,NULL);
		new=new->prox;
	}
	return head;
}

//////////////////// QUESTAO 3 ////////////////////

void freeL (LInt z){
	if (z==NULL)
		return;
	LInt aux = z;
	while (z!=NULL){
		z=z->prox;
		free(aux);
		aux = z;
	}

}


//////////////////// QUESTAO 4 ////////////////////

void imprime (LInt z){
	if (z==NULL)
		return;
	while (z!=NULL){
		printf("%d\n", z->valor);
		z=z->prox;
	}
}


//////////////////// QUESTAO 5 ////////////////////

LInt reverse (LInt z){
	if (z==NULL || z->prox==NULL)
		return z;
	LInt top = z;
	while (z->prox!=NULL){
		z=z->prox;
	}
	LInt bottom = z;
	LInt low = bottom;
	z=top;
	while (low!=top){
		while (z->prox!=low){
		z=z->prox;
		}
		low->prox = z;
		low=low->prox;
		z=top;
	}
	top->prox = NULL;

	return bottom;
}

//////////////////// QUESTAO 6 ////////////////////

void insert (LInt *z, int x){
	LInt newBox = newLInt(x,NULL);
	LInt zz = *z;
	if (zz == NULL){
		zz = newBox;
		*z = zz;
		return;
	}
	else if (zz->valor > x){
		newBox->prox = zz;
		zz = newBox;
		*z = zz;
		return;
	}
	while (zz->prox!=NULL && (zz->prox->valor)<x){
		zz= zz->prox;
	}
	newBox->prox = zz->prox;
	zz-> prox = newBox;
}

//////////////////// QUESTAO 7 ////////////////////

int removez (LInt *z, int x){
	LInt zz = *z;
	LInt aux = zz;
	LInt ante = zz;

	if (zz==NULL || zz->valor > x)
		return 1;

	else if (zz->valor == x){
		zz = zz->prox;
		free(aux);
		*z = zz;
		return 0;
	}

	zz= zz->prox;
	while (zz && zz->valor < x){
		zz= zz->prox;
		ante = ante->prox;
	}

	if (zz!=NULL && zz->valor == x){
		if (zz->prox != NULL){
			ante->prox = zz->prox;
			free(zz);
			return 0;
		}
		else{
			free(zz);
			ante->prox = NULL;
			return 0;
	}

	}
	return 1;

}

//////////////////// QUESTAO 8 ////////////////////

LInt merge(LInt a, LInt b){
	if (a==NULL)
		return b;
	if (b==NULL)
		return a;
	LInt head;
	if (a->valor < b->valor){
		head = a;
		a = a->prox;
	}
	else{
		head = b;
		b = b->prox;
	}

	LInt fixed_head = head;

	while (a!=NULL && b!=NULL){
		if (a->valor < b->valor){
			head->prox = a;
			head = head->prox;
			a = a->prox;
		}
		else if (a->valor > b->valor){
			head->prox = b;
			head = head->prox;
			b = b->prox;
		}
	}

	if (a == NULL)
		head->prox = b;
	else if (b==NULL)
		head->prox = a;

	return fixed_head;
}

//////////////////// QUESTAO 9 ////////////////////

void split (LInt l, int x, LInt *mx, LInt *Mx){
	if (l==NULL)
		return;

	LInt mmx = newLInt(666, NULL);
	LInt MMx = newLInt(666, NULL);
	LInt tmmx = mmx;
	LInt tMMx = MMx;

	while (l){
		if (l->valor >= x){
			tMMx->prox = l;
			tMMx = tMMx->prox;
		}
		if (l->valor <= x){
			tmmx->prox = l;
			tmmx = tmmx->prox;
		}
		l = l-> prox;
	}

	tMMx->prox = NULL;
	tmmx->prox = NULL;

	*mx = mmx->prox;
	*Mx = MMx->prox;
}


//////////////////// QUESTAO 10 ///////////////////
int remove10 (LInt *l, int x){
	LInt ll = *l;
	if (ll==NULL)
		return 0;
	int count = 0;

	LInt ante = newLInt(666,ll);
	LInt head = ante;
	LInt aux;

	while (ll){
		while (ll && ll->valor == x){
			aux = ll;
			ll = ll->prox;
			free(aux);
			count++;
		}
		ante->prox = ll;
		ante = ante->prox;
		ll = ll->prox;
	}

	ante->prox = NULL;
	*l = head->prox;
	free(head);

	return count;

}

//////////////////// QUESTAO 11 ///////////////////

int removeDups (LInt *l){
	LInt ll = *l;
	int count = 0;
	if (ll==NULL)
		return 0;

	LInt aux = newLInt(ll->valor, NULL);
	LInt head_of_aux = aux;
	LInt ante = ll;
	ll = ll->prox;

	while (ll){
		while(aux){
			if (ll->valor == aux->valor){
				aux = head_of_aux;
				count ++;
				break;
			}
			aux = aux->prox;
		}

		if (aux==NULL){
			aux = newLInt(ll->valor,head_of_aux);
			head_of_aux = aux;
			ante = ll;
			ll = ll->prox;
		}
		else{
		aux = head_of_aux;
		ante->prox = ll->prox;
		free(ll);
		ll = ante->prox;
		}
	}

	return count;

}


//////////////////// QUESTAO 12 ///////////////////

int removeMaior (LInt *l){
	LInt ll = *l;
	LInt aux = ll;
	int biggest = ll->valor;
	LInt ante = ll;
	ll = ll->prox;
	while (ll){
		if (ll->valor > biggest){
			biggest = ll->valor;
		}
		ll = ll->prox;
	}

	ll = aux ->prox;
	while (ll){
		if (ll->valor == biggest){
			ante->prox = ll->prox;
			free (ll);
			break;
		}
		else{
			ante = ll;
			ll = ll->prox;
		}
	}

	*l = aux;
	return biggest;
}

//////////////////// QUESTAO 13 ///////////////////

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

//////////////////// QUESTAO 14 ///////////////////

void snoc (LInt *l, int x){
	LInt ll = *l;
	LInt head = ll;
	while (ll->prox){
		ll = ll->prox;
	}
	ll->prox = newLInt(x,NULL);
}

//////////////////// QUESTAO 15 ///////////////////

void concat (LInt *a, LInt b){
	LInt aa = *a;
	LInt head = aa;
	while (aa->prox){
		aa = aa->prox;
	}
	aa->prox = b;

	*a = head;
}

//////////////////// QUESTAO 16 ///////////////////

				// IGUAL A QUESTAO 2 //

//////////////////// QUESTAO 17 ///////////////////

LInt cloneR (LInt a){

	LInt last;
	LInt HEAD = a;
	if (a == NULL)
		return NULL;

	while (a->prox){
		a = a->prox;
	}

	last = a;
	a = HEAD;
	LInt result = newLInt(last->valor, NULL);
	LInt head_of_res = result;
	while (1){
		while (a->prox != last){
			a = a->prox;
		}
		last = a;
		a = HEAD;
		result->prox = newLInt(last->valor, NULL);
		result = result->prox;
		if (a == last)
			break;
	}
	return head_of_res;
}

//////////////////// QUESTAO 18 ///////////////////

int maximo (LInt l){
	int max = l->valor;
	l = l->prox;
	while (l){
		if (l->valor > max)
			max = l->valor;
		l = l->prox;
	}
	return max;
}

//////////////////// QUESTAO 19 ///////////////////

int take (int n, LInt *l){
	int size = 1;
	LInt ante;
	LInt ll = *l;
	LInt end;
	while (ll && size < n){
		ll = ll->prox;
		size ++;
	}

	if (ll==NULL){
		size--;
		return size;
		}

	end = ll;
	ll = ll->prox;
	end->prox=NULL;
	if (ll==NULL)
		return size;


	ante = ll;
	ll =ll->prox;

	if (ll == NULL){
		free(ante);
		return size;
	}

	while (ll->prox) {
		free(ante);
		ante = ll;
		ll = ll->prox;
	}
	//free(ante);


	return size;
}

//////////////////// QUESTAO 20 ///////////////////

int drop (int n, LInt *l){
	LInt ll = *l;
	int count = 0;
	if (ll == NULL || n == 0)
		return count;

	count++;
	LInt ante = ll;
	ll=ll->prox;
	while (count!=n && ll){
		free (ante);
		ante = ll;
		ll = ll->prox;
		count++;
	}
	*l =ll;

	return count;
}

//////////////////// QUESTAO 21 ///////////////////

LInt Nforward(LInt l, int N){
	while (N){
		l=l->prox;
		N--;
	}
	return l;
}

//////////////////// QUESTAO 22 ///////////////////

int dumpL (LInt l, int v[], int N){
	int count = 0;
	while(count!=N){
		v[count] = l->valor;
		l= l->prox;
		count ++;
	}

	return count;
}

//////////////////// QUESTAO 23 ///////////////////

LInt somas (LInt l){
	if (l==NULL)
		return NULL;

	int somatorio = 0;
	LInt HEAD=l;
	while (l){
		somatorio+=l->valor;
		l->valor = somatorio;
		l=l->prox;
	}
	return HEAD;
}

//////////////////// QUESTAO 24 ///////////////////

void remreps (LInt l){
	if (l==NULL || l->prox==NULL)
		return;
	LInt head = l;
	int chosen = head->valor;
	l = l->prox;
	LInt ante = l;
	l=l->prox;
	while (l){
		if (l->valor == chosen && l->prox){
			ante->prox = l->prox;
			free(l);
			l=ante->prox;
		}
		else if (l->valor == chosen && l->prox==NULL){
			ante->prox = NULL;
			free (l);
		}
		ante = ante->prox;
		l=l->prox;
		head = head->prox;
		chosen = head->valor;
	}
}

//////////////////// QUESTAO 25 ///////////////////

LInt fromArray (int v[], int N){
	if (N==0)
		return NULL;

	int i;
	LInt result = newLInt(v[0],NULL);
	LInt head_of_res = result;

	for (i=1; i<N; i++){
		result->prox = newLInt(v[i],NULL);
		result = result->prox;
	}

	return head_of_res;

}

//////////////////// QUESTAO 26 ///////////////////

LInt rotateL (LInt l){
	if (l==NULL || l->prox == NULL)
		return l;

	LInt head = l;
	LInt aux = l->prox;

	while (l->prox){
		l=l->prox;
	}

	l->prox = head;
	head->prox = NULL;

	return aux;
}

//////////////////// QUESTAO 27 ///////////////////

LInt parte (LInt l){
	if (l == NULL || l->prox == NULL)
		return NULL;

	int count = 1;
	LInt head = l;
	LInt pares = l->prox;
	LInt head_of_pares = pares;

	while (pares->prox){
		l->prox = pares->prox;
		l = l->prox;
		if (l->prox){
			pares->prox = l->prox;
			pares = pares->prox;
		}
		else if (l->prox ==NULL)
			break;
	}

	pares->prox = NULL;
	l->prox = NULL;

	return head_of_pares;
}


//////////////////// QUESTAO 28 ///////////////////

int max (int a, int b){
	if (a>b)
		return a;
	return b;
}


int height (ABin a){
	int count = 0;
	if (a)
		count = (1+max(height(a->esq),height(a->dir)));
	return count;
}

//////////////////// QUESTAO 29 ///////////////////

ABin cloneAB (ABin a){
	if (a==NULL)
		return NULL;
	return newABin(a->valor,cloneAB(a->esq),cloneAB(a->dir));

}


//////////////////// QUESTAO 30 ///////////////////

void mirror (ABin *a){
	ABin aa = *a;
	if (aa==NULL)
		return;
	mirror(&(aa->esq));
	mirror(&(aa->dir));
	ABin temp = aa->esq;
	aa->esq = aa->dir;
	aa->dir = temp;
}


//////////////////// QUESTAO 31 ///////////////////

void inorder (ABin a, LInt *l){
	if (a==NULL)
		return;
	inorder(a->dir,l);
	*l= newLInt(a->valor,*l);
	inorder(a->esq,l);


}

//////////////////// QUESTAO 32 ///////////////////

void preorder (ABin a, LInt *l){
	if (a==NULL)
		return;
	*l = newLInt(a->valor,*l);
	preorder(a->dir, l);
	preorder(a->esq, l);
}

//////////////////// QUESTAO 33 ///////////////////

void posorder (ABin a, LInt *l){
	if (a==NULL)
		return;
	posorder(a->esq,l);
	*l = newLInt(a->valor, *l);
	posorder(a->dir,l);
}

//////////////////// QUESTAO 34 ///////////////////

int depth (ABin a, int x){
	int level = 1;
	if (a==NULL)
		return -1;

	if (x > a->valor)
		level = 1 + depth(a->dir, x);
	else if (x < a->valor)
		level = 1 + depth(a->esq, x);


	return level;
}

//////////////////// QUESTAO 35 ///////////////////

int freeAB (ABin a){
	int count = 0;
	if (a==NULL)
		return count;
	count = 1 + freeAB(a->esq) + freeAB(a->dir);
	//a->esq = a->dir = NULL;
	free(a);
	return count;
}

//////////////////// QUESTAO 36 ///////////////////

int pruneAB (ABin *a, int l){
	int level = l;
	if (level==0){
		return freeAB(*a);
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}

	return 	pruneAB(&((*a)->esq), level -1) + pruneAB(&((*a)->dir), level -1);
}



///////////////////// AUXILIAR ////////////////////

void imprimeAB (ABin a){
	if (a==NULL)
		return;
	imprimeAB(a->esq);
	printf("%p %d\n", a, a->valor);
	imprimeAB(a->dir);
}




////////////////////// MAIN //////////////////////

int main (){

	LInt a = newLInt(40,NULL);
	LInt b = newLInt(30,a);
	LInt c = newLInt(20,b);
	LInt d = newLInt(10,c);
	LInt e = newLInt(80,d);
	LInt f = newLInt(10,e);
	LInt g = newLInt(5,f);
	LInt h = newLInt(20,g);

	ABin i = newABin(10,NULL,NULL);
	ABin j = newABin(30,NULL,NULL);
	ABin k = newABin(20, i, j);
	ABin l = newABin(5, NULL, k);
	/*
	int count =freeAB(k);

	puts("----");
	printf("%d\n", count);
	puts("----");
	imprimeAB(l);
	*/
	imprime(reverse(h));


	return 0;
}
