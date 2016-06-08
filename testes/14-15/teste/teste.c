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



typedef struct strlist
{
  char *string;
  struct strlist *prox;
}*Strlist;

void unwords(Strlist s, char t[], int N){
  int i = 0;
  int a = 0;
  while(s != NULL){
    i= 0;
    while(s->string[i] != '\0'){
      t[a] = s->string[i];
      a++;
      i++;
    }

    if(s->prox == NULL){
      t[a] = '\0';
      s = s->prox;
    }
    else{
      t[a] = ' ';
      a++;
      s = s->prox
    }
  }
}

 int words(char t[], StrList *l){
   int b = 0;
   *l = NULL;
   while(t[i] != '\0'){
     while(t[i] ==' ' && t[i] != '\0') i++;

     int j = 0
     int a = i;

     while(t[a] != ' ' & t[a] != '\0'){
       a++;
       j++;
     }

     *l = (StrList) malloc(sizeof(StrList));
     int b = 0;
     *l->prox = NULL;
     l = &(*l)->prox;
   }
 }


 int maxuniqueseq(int v[], in N){
   int i = 0;
   conta
   int res = 0;
   while(i<N){
     int j = i+1;

     while(j<N && v[j] != v[i])


   }
 }
