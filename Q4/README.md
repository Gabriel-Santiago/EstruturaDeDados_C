<h1> Implemente a TAD “arvb.h” (Árvore Binária de Buscas) e acrescente as seguintes funções: </h1>

a) função que retorne a quantidade de folhas de uma árvore binária de busca que possuem o campo info com n divisores positivos. Essa função deve obedecer ao protótipo:

 int folhas_ndivp(ArvB* a, int n); 

b) função que retorne a quantidade de nós de uma árvore binária de busca que possuem os dois filhos (campos dir e esq diferentes de NULL). Essa função deve obedecer ao protótipo: 

int dois_filhos(ArvB* a); 

c) função que, dada uma árvore binária de busca, retorne a quantidade de nós cujas subárvores esquerda e direita tenham igual altura. Essa função deve obedecer ao protótipo: 

int nos_igual_altura(ArvB* a); 

d) função que compare se duas árvores binárias de busca são iguais. Essa função deve obedecer ao protótipo:

 int arv_iguais(ArvB* a, ArvB* b); 

Obs: 1 – verdadeiro; 0 – falso. 

e) função que imprima os elementos de uma árvore binária de busca por níveis. Essa função deve obedecer ao protótipo: 

void impressao_arv_niveis(ArvB* a); 

Por exemplo, na árvore da figura abaixo, a impressão deve ser: 

6 – nível 0 

5, 8 – nível 1 

7, 9 – nível 2