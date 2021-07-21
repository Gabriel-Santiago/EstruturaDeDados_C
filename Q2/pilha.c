#include<stdio.h>
#include<stdlib.h>

#include "pilha.h"
#include "lista.h"


struct lista{
	int info;
	Lista *prox;
};

struct pilha{
	int info;
	Lista *prim;
	Lista *prox;
}; 

Pilha* pilha_cria(void){
	
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

void pilha_push(Pilha *p, int info){
	
	Lista *l = (Lista*)malloc(sizeof(Lista));
	
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(0);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

int pilha_pop(Pilha *p){
	
	int a;
	Lista *l;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

void pilha_imprime(Pilha *p){
	
	Lista *l = p->prim;
	
	while(l!=NULL){
		printf("%d\n",l->info);
		l = l->prox;
 	}
}

void pilha_libera(Pilha *p){
	
	Lista* l = p->prim;
	Lista* lAux;
	
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
	
	Pilha* pilhadef = pilha_cria();
	Lista* aux = lst_cria();
	
	while(l2 != NULL){
		if(lst_busca(l1, l2->info) != NULL){
			aux = lst_insere_ordenado(aux,l2->info);
		}
		l2 = l2->prox;
	}
	while(aux != NULL){
		pilha_push(pilhadef,aux->info);
		aux = aux->prox;
	}
	return pilhadef;
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

Lista* lst_insere_ordenado(Lista *l, int info){
	
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	
	if(l==NULL){
		lNew->prox = NULL;
		return lNew;
	}else if(l->info>=info){
		lNew->prox = l;
		return lNew;
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->prox;
	while(lProx!=NULL&&lProx->info<info){
		lAnt = lProx;
		lProx = lProx->prox;
	}
		lAnt->prox = lNew;
		lNew->prox = lProx;
		return l;
	}
}

void lst_imprime_invertida_rec(Lista* l){
	
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("Info: %d\n",l->info);
	}
}

Pilha* inverte_pilha(Pilha* p){
	
	Lista* l = p->prim;
	
	if(lst_vazia(l))
		return;
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("Info: %d\n",l->info);
	}
}
