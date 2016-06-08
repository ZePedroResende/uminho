int palindroma (char v[]){
  int i = 0;
  while(v[i] != '\0'){
    i++;
  }
  int a = i/2;
  i--;
  int b = 0;

  while(b<i &&v[b]==v[i]){
    b++;
    i--;
  }

  if(b == a) return 1;
  else return 0;

}


char *strlchr(char *s, char c){
  int r = -1;
  char *res = NULL;
  int i = 0;
  while(s[i] != '\0'){
    if(s[i]==c) r = i;
    i++;
  }
  if (res != NULL) 
  *res = *s + (r*sizeof(char));

  return *res;
}

void ordena(int num[], int notas[], int n){
  int i=0;
  int j
  int tmp;
 for(i=0; i<n; i++){
    for(j=0;j<n;j++){
      if(num[j]> num[j+1]){
        tmp = num[j];
        num[j]= num[j+1];
        num[j+1] = tmp;

        tmp = notas[j];
        notas[j] = notas[j+1];
        notas[j+1] = tmp;
      }
    }
  }
}

typedef struct slist{
  int valor;
  struct slist *prox;
}*LInt;

int dumpL (LInt l, int v[], int N){
  int i = 0;
  while(l != NULL && i<N){
    v[i] = l->valor;
    l = l->prox
    i++;
  }
  return i;
}

LInt somas(LInt l){
  LInt res = NULL;
  int r  =0 ;
  LInt* aux = &res;
  while(l != NULL){
    r += l->valor;
    *aux =newLInt(r,NULL)
      aux = &(*aux)->prox;
    l = l->prox;
  }
  return res;
}
