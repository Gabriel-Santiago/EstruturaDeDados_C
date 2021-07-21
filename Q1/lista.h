typedef struct lista Lista;

Lista* lst_cria();

int lst_vazia(Lista *l);

Lista* lst_insere(Lista *l, int info);

Lista* lst_insere_ordenado(Lista *l, int info);

void lst_imprime(Lista *l);

Lista* lst_busca(Lista *l, int info);

Lista* lst_remove(Lista *l, int info);

void lst_libera(Lista *l);

int menores(Lista *l, int n);

int soma(Lista *l);

int num_ndivp(Lista *l, int n);

Lista* lst_intersec(Lista* l1, Lista* l2);

Lista* lst_conc(Lista* l1, Lista* l2);

Lista* lst_diferenca(Lista* l1, Lista* l2);

void lst_imprime_invertida_rec(Lista* l);
