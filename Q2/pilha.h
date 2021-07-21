#include "lista.h"

typedef struct pilha Pilha;

Pilha* pilha_cria(void);

int pilha_vazia(Pilha *p);

void pilha_push(Pilha *p, int info);

int pilha_pop(Pilha *p);

void pilha_imprime(Pilha *p);

void pilha_libera(Pilha *p);

Pilha* inverte_pilha(Pilha* p);

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);
