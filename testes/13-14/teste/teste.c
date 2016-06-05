typedef struct slist {
  int valor;
  struct slist *prox;
} *LInt;



typedef struct nodo {
  int valor;
  struct nodo *esq, *dir;
} *ABin;


char *strstr (char s1[], char s2[]){

  if(s1 [0]=='\0' && s2[0]=='\0') return s1;

  int i= 0;
  while(s1[i] != '\0'){
    int j=0;
    int a = i;
    while(s1[a]!= '\0' && s1[a] == s2[j] ){
      a++;
      j++;
    }
    if(s2[j] == \0) return &s1[i];
    i++;
  }

  return NULL;
}

int maxInd (int v[], int n){
  int i = 1;
  int maior=v[0];
  int maiorIndice = 0;
  while (i<n){
    if(v[i] > maior){
      maior = v[i];
      maiorIndice = i;
    }
    i++;
  }

  return maiorIndice;
}


void concat (LInt *a, LInt b){
  while(*a != NULL)
    a = &(*a)->prox;

  *a = b;
}

LInt nivel (ABin a, int n){
  LInt l = NULL;
  LInt p = NULL
    if(a == NULL) l= NULL;
    else {
      if(n == 1){
    l = malloc(sizeof(LInt));
    l->valor = a->valor;
    l->prox = NULL;
  }
      else{
      l = nivel(a->esq,n-1);
      p = nivel(a->dir,n-1);
      }
    }
  LInt* e = &l;
  while(*e != NULL){
    e = &(*e)->prox;
  }
  *e = p;

  return l;
}

int main() {
  int k;
  int i = 0;
  int v[100];
  int numero= 0;
  while (scanf("%d", &k) == 1 && i<100 && existe(k,v){
      v[i] = k;
      i++;
    } 
  numero = maxInd(v,100)

    printf("indice maximo %d",numero);
  printf("valor do array maximo %d",v[numero]);


  return 0;
}



