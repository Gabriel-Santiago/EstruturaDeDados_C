#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

struct lista {
	int info;
	Lista *prox;
};

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

Lista* lst_busca(Lista *l, int info){
	
	Lista* lAux = l;
	
	while(lAux!=NULL){
		if(lAux->info == info)
		return lAux;
		lAux = lAux->prox;
	}
	return NULL;
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

void lst_imprime(Lista *l){
	
	Lista* lAux = l;
	
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
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

int menores(Lista *l, int n){
	
	int men = 0;
	Lista* min = l;
	
	while (min != NULL) {
		if(n> min->info){
			men++;
		}
		min = min->prox;
	}
	return men;
}

int soma(Lista *l){
	
	int total = 0;
	Lista* soma = l;
	
	while(soma != NULL){
		total = total + soma->info;
		soma = soma->prox;
	}
	return total;
}

Lista* lst_conc(Lista* l1, Lista* l2){
	
	Lista* l3 = lst_cria();
	
	while(l2!=NULL){
		l3 = lst_insere(l3, l2->info);
		l2 = l2->prox;
	}
	while(l1!=NULL){
		l3 = lst_insere(l3, l1->info);
		l1 = l1->prox;
	}
	return l3;
}

Lista* lst_diferenca(Lista* l1, Lista* l2){
	
	Lista* aux = lst_cria();
	int flag=0;
	
	while(l2 != NULL){
		if(lst_busca(l1, l2->info) != NULL){
			aux = lst_remove(l1, l2->info);
			flag++;
		}
		l2 = l2->prox;
	}
	if(flag!=0){
		return aux;
	}else{
		return l1;
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

Lista *lst_intersec(Lista *l1, Lista *l2)
{
    Lista *l3 = lst_cria();
    Lista *lAux1 = l1;
    Lista *lAux2 = l2;
    
    while (lAux1 != NULL)
    {
        if (lst_busca(lAux2, lAux1->info) != NULL)
        {
            l3 = lst_insere_ordenado(l3, lAux1->info);
        }
        lAux1 = lAux1->prox;
    }
    while (lAux2 != NULL)
    {
        if (lst_busca(lAux1, lAux2->info) != NULL)
        {
            l3 = lst_insere_ordenado(l3, lAux2->info);
        }
        lAux2 = lAux2->prox;
    }
    return l3;
}

int num_ndivp(Lista* l, int n){
	
	int cont=0, div,i;
	Lista* lAux = l;
	while(lAux != NULL){
		i=1;
		div=0;
		while(i<=lAux->info){
			if(lAux->info % i==0){
				div++;
			}
			i++;
		}	
		if(div==n){
			cont++;
		}
		lAux = lAux->prox;
	}
	return cont;
}
