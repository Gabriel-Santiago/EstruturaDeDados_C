typedef struct arvb Arv;

/*Função que cria uma Árvore Binária de Busca Vazia.*/
Arv* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(Arv *a);

/*Função que busca a sub-árvore que contém um inteiro.*/
Arv* arvb_busca(Arv *a,int c);

/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(Arv *a);

/*Função que insere um inteiro em uma Árvore.*/
Arv* arvb_insere(Arv *a, int c);

/*Função que remove um inteiro em uma Árvore.*/
Arv* arvb_remove(Arv *a, int c);

/*Função que verifica a altura da Árvore*/
int arv_altura(Arv *a);

/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(Arv *a);

///////////////////////////////////////////////////////

/*Números de elementos divisiveis por 'n'*/
int folhas_ndivp(Arv* a, int n);

/*Função que retorne a quantidade de nós de uma árvore binária de busca que possuem os dois filhos*/
int dois_filhos(Arv* a);

/*Função que retorne a quantidade de nós cujas subárvores esquerda e direita tenham igual altura*/
int nos_igual_altura(Arv* a);

/*Função que compare se duas árvores binárias de busca são iguais*/
int arv_iguais(Arv* a, Arv* b);

/*Função que imprima os elementos de uma árvore binária de busca por níveis*/
void imprimir_nivel(Arv* a, int nivel);
void impressao_arv_niveis(Arv* a);
