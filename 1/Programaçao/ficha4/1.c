
//arvores binarias

typeded struct abin{
    int val;
    struct abin *left, *right;
}Node, *ABin;

ABin newABin(int x, ABin l, ABin a){
    ABin res = (ABin) malloc(Sizeof(Node));
    res ->val = x;
    res->left = l;
    res->right = r;

    return res;
}
//recursiva 
int conta (ABin a)
{
   if(a==NULL) return 0;
return 1+conta(a->left) + conta(a->right);
}


int procuraAB(ABin a, int x)
{

    while(a != NULL && a->valor != x){
        if(x<a->valor) a = a->left;
        else a = a->right;
    }

    return a != NULL
}

ABin insereABin(ABin a, intx)
{

}


void printPreOrder(ABin A){
    if(a!=NULL){
        printf("%d",a->valor);
        printPreOrder(a->esq);
        printPreOrder(a->dir);
    }
}

int posOrder(ABin a, int v[]){
int i =0;
    if(a!=NULL) {
        i = posOrder(a->esq,v);
        i += posOrder(a->dir,v+i);
        v[i] = a->valor;
        i++;
    }
return i;
}

/*
int posOrder(ABin a, int v[]){
int i =0;
if(a!=NULL) 
    void auxiliar(a,i,v);
return i;
}

void auxiliar(ABin a,int i, int v[]){

  if(a->esq != NULL && a->dir !=NULL){
    auxiliar(a->esq,i,v);
    auxiliar(a->dir,i,v);
    v[i] = a->valor;
  } 
  else{
     v[i] = a->valor;
     i++;
  }
}
*/

/*
LInt  inorder(ABin a){
    LInt a, aux;

    if(a==NULL) r = NULL;
    else{
        aux = inorder(a->esq);
        r = newNOde(a->val, indorder(a->dir));
        r = concat(aux,r);
    }
    return r;
}
*/
LInt inorder(ABin a, LInt l){
    LInt r;
    if(a==NULL) r= l;
    else {
        r = inorder(a->dir,l);
        r = newLInt(a->valor,r);
        r = inorder(a->esq,r);
    }
    return r;
}

LInt preOrder(ABin a, LInt l){
    LInt r;
    if(a==NULL) r= l;
    else{
        r = preOrder(a->dir,l);
        r = preOrder(a->esq,l);
        r = newLInt(a->valor,r);
    }
    return r;
}



