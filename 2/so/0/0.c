#include <stdio.h>
#include <stdlib.h>
struct intv {
    int a;
    int b;
struct intv *next;
};


struct intv* reserva(struct intv* livres, int n, int* reservado)
{
    struct intv* novo = livres;
    while(novo->next &&  n < novo->b ){
        novo = novo->next;
    }

    if(novo){
        *reservado = novo->a;
	   	novo->a += n;
        novo->b -= n;
	}else *reservado = -1;

    return livres;
}


struct intv* liberta (struct intv* livres, int lugar, int n)
{
    struct intv* novo = livres;
    struct intv*
    while(novo->next->next &&  lugar < novo->next->a || novo->next->b < lugar ){
        novo = novo->next;
    }

    if(novo){
     novo->a += n;
     novo->b -= n;
	}

    return livres;
}
