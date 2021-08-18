typedef struct arvb Arv;

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
Arv* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(Arv *a);

/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
Arv* arvb_busca(Arv *a,int c);

/*Fun��o que imprime os elementos de uma �rvore.*/
void arvb_imprime(Arv *a);

/*Fun��o que insere um inteiro em uma �rvore.*/
Arv* arvb_insere(Arv *a, int c);

/*Fun��o que remove um inteiro em uma �rvore.*/
Arv* arvb_remove(Arv *a, int c);

/*Fun��o que verifica a altura da �rvore*/
int arv_altura(Arv *a);

/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(Arv *a);

///////////////////////////////////////////////////////

/*N�meros de elementos divisiveis por 'n'*/
int folhas_ndivp(Arv* a, int n);

/*Fun��o que retorne a quantidade de n�s de uma �rvore bin�ria de busca que possuem os dois filhos*/
int dois_filhos(Arv* a);

/*Fun��o que retorne a quantidade de n�s cujas sub�rvores esquerda e direita tenham igual altura*/
int nos_igual_altura(Arv* a);

/*Fun��o que compare se duas �rvores bin�rias de busca s�o iguais*/
int arv_iguais(Arv* a, Arv* b);

/*Fun��o que imprima os elementos de uma �rvore bin�ria de busca por n�veis*/
void imprimir_nivel(Arv* a, int nivel);
void impressao_arv_niveis(Arv* a);
