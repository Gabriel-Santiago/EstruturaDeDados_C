#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb{
	int info;
	Arv *esq;
	Arv *dir;
};



Arv* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(Arv *a){
	return a==NULL;
}

Arv* arvb_busca(Arv *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else
	return a;
}

void arvb_imprime(Arv *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

Arv* arvb_insere(Arv *a, int c){
	if(arvb_vazia(a)){
		a = (Arv*)malloc(sizeof(Arv));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
	return a;
}

Arv* arvb_remove(Arv *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			Arv* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL)
				t = t->dir;
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
return a;
}

int arv_altura(Arv *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arv_altura(a->esq);
		int hSAD = arv_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
		else
			return 1+hSAD;
	}
}

void arvb_libera(Arv *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

///////////////////////////////////////

int folhas_ndivp(Arv* a, int n){
	
	int i, cont = 0;
	
	if(!arvb_vazia(a)){
		for(i = 1; i <=a->info; i++){
			if(a->info % i == 0){
				cont++;
			}
		}
		if(cont == n){
			return 1 + folhas_ndivp(a->esq,n) + folhas_ndivp(a->dir, n);
		}
		else{
			return 0 + folhas_ndivp(a->esq,n) + folhas_ndivp(a->dir, n);
		}
	}
	else{
		return 0;
	}
}

int dois_filhos(Arv* a){
	if(a == NULL || (a->esq == NULL && a->dir == NULL))
		return 0;
	else
		return 1 +  dois_filhos(a->esq) + dois_filhos(a->dir);
}

int nos_igual_altura(Arv* a){
	
	int x = 0;
	
	if(!arvb_vazia(a)){
		if(arv_altura(a->esq) == arv_altura(a->dir))
			x++;
		x += (nos_igual_altura(a->esq)) + (nos_igual_altura(a->dir));
	}
	return x;
}

int arv_iguais(Arv* a, Arv* b){
	if(a == NULL && b == NULL)
        return 1;
    else if((a->info == b->info) && arv_iguais(a->esq,b->esq) && arv_iguais(a->dir,b->dir)){
    	return 1;
	}else{
		return 0;
	}
}

void imprimir_nivel(Arv* a, int num){
	
	if(a != NULL && num == 0){
		printf("%d ", a->info);
	}else if(a != NULL){
		imprimir_nivel(a->esq, num - 1);
		imprimir_nivel(a->dir, num - 1);
	}
}

void impressao_arv_niveis(Arv* a){
	
	int g;
	
	int impressao = arv_altura(a) + 1;
	
	for(g = 0; g < impressao; g++){
		printf("nivel %d - ", g);
		imprimir_nivel(a, g);
		printf("\n");
	}	
}











