#include <stdio.h>

/*
input -> stdin ->

output :
       stdout <-
       stden

./prog in.txt out.txt

FILE* fopen(char *nome, char *modo)  
      fclose(FILE *f) 
      "r" e "r+" , "w" e "w+" e "a" e "a+"
      b se for um ficheiro binario ;


TEXTO
fprintf(FILE *f, ........)
fputc(FILE *f, ..........)

fscanf()
fgetc
fgets
....



long fwrite(void *buf, long size, long n, FILE *f)   *buf ( local da memoria onde vai escrever ), size (tamanho dos blocos que vai escrever), n (numero dos blocos a escrever), da return ao numero de blocos escritos .
long fread(void *buf, long size, long n, FILE *f) "..." (igual ao de cima)

int fseek(FILE *f, long offset, int whence)
long f tell(FILE *f)
           SEEK_SET ,SEEK_CUR , SEE_END

int fflush(file *) DA REFRESH A  UM FICHEIRO D EMODO A TER A FUNÇAO MAIS ATUAL se lermos um ficheiro fwrite e fread utilizar isto la dentro para ter o ficheiro mais atualizado 
*/
typedef struct lligada {
  int valor;
  struct lligada *prox;
} *LInt;


LInt newLInt(int n, LInt l){
  LInt new;
  new=(LInt) malloc(sizeof(LInt));
  new->valor = n;
  new->prox = l;
  return new;
}


int writeLInt(FILE *f, LInt l){
  int cont = 0;
  while (l != NULL){
    fwrite((void*) &(l->valor), sizeof(int),1,f);
    cont++;
    l = l->prox;
  }
  return cont;
}

int readLInt(FILE *f, LInt *l){
  int cont =0,temp;
  while(fread(&temp,sizeof(int), 1,f) != 0){
    *l = malloc(temp,NULL);
    cont++;
    l=&(*l)->prox;
  }
}

typedef struct contacto{
  char mon[80];
  char email[80];
  char telefone[10]
}Contacto;

typedef struct registo{
  Contaco c;
  long proximo;
}

  FILE *abreFich(char *nome){

  }

long novo(FILE *f);
long primeiro(FILE *f);

void dumpLista(FILE *f);

int lookup(Contacto *dest , FIle *f, char *nome);

int acrescenta(FILE *f; contacto c);
