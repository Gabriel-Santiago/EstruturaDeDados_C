#include <stdio.h>
#include<stdlib.h>
#include "fila1.h"
#include "lista.h"

#define N 9

struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void){
	
	Fila *f = (Fila*)malloc(sizeof(Fila));
	
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = 0;
	f->ini = 0;
	return f;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

void fila_insere(Fila *f, int info){
	
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l ->info = info;
	l ->prox = NULL;
	if(!fila_vazia(f))
		f->fim->prox = l;
	else
		f->ini = l;
		f->fim = l;
}

int fila_remove(Fila *f){
	
	Lista *l; 
	int a;
	
	if(fila_vazia(f)){
		printf("Fila Vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if(fila_vazia(f))
		f->fim = NULL;
	return a;
}

void fila_imprime(Fila *f){
	
	Lista *lAux = f->ini;
	
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void fila_libera(Fila *f){
	
	Lista* l = f->ini;
	Lista* lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(f);
}

Fila* inverte_fila(Fila* f){
	
	Lista* in = f->ini;
	Lista* laux = lst_cria();
	
	Fila* f2 = fila_cria();
	
	while(in!=NULL){
		laux = lst_insere(laux, in->info);
		in = in->prox;
	}
	while(laux!=NULL){
		fila_insere(f2, laux->info);
		laux = laux->prox;
	}
	return f2;
}

int qtd_primos(Fila* f, int n){
	
	int i;
	
	for(i = 2; i*i < n+1; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

Lista* lst_cria(){
	return NULL;
}

int lst_vazia(Lista *l){
	return (l==NULL);
}

Lista* lst_insere(Lista *l, int info){
	
	Lista* ln = (Lista*)malloc(sizeof(Lista));
 	ln->info = info;
 	ln->prox = l;
 	return ln;
}

Lista* lst_busca(Lista *l, int info){
	
	Lista* lAux = l;
	
 	while(lAux!=NULL){
 		if(lAux->info == info)
 		return lAux;
 		lAux = lAux->prox;
	}
	return NULL;
}

void lst_imprime(Lista *l){
	
 	Lista* lAux = l;
 	
 	while(lAux!=NULL){
 		printf("Info = %d\n",lAux->info);
 		lAux = lAux->prox;
 	}
}

Lista* lst_remove(Lista *l, int info){
	
	if(l!=NULL){
	 	Lista* lAux = l->prox;
	 	if(l->info==info){
	 		free(l);
	 return lAux;
	 }
	 else{
	 	Lista* lAnt = l;
	 	while(lAux!=NULL ){
	 		if(lAux->info == info){
				 lAnt->prox = lAux->prox;
				 free(lAux);
	 	break;
	 	}	else{
	 			lAnt = lAux;
				 lAux = lAux->prox;
				}
	 	}
	 }
	 return l;
	}
}

void lst_libera(Lista *l){
	
 	Lista* lProx;
 	
 	while(l!=NULL){
 		lProx = l->prox;
 		free(l);
 		l = lProx;
 	}
}
