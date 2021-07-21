<h1>Implemente o Tipo Abstrato de Dados (TAD) “lista.h” (ver slides sobre Listas Encadeadas) e acrescente as seguintes funções: </h1>



a) função para retornar o número de nós da lista que possuem o campo info com valor menor que n. Essa função deve obedecer ao protótipo: int menores(Lista* l, int n); 

b) função para somar os valores do campo info de todos os nós. Essa função deve obedecer ao protótipo:

int soma(Lista* l); 

c) função para retornar o número de nós da lista que possuem o campo info com n divisores positivos. Essa função deve obedecer ao protótipo:

int num_ndivp(Lista* l, int n); 

d) função para gerar uma nova lista que é a intersecção de duas listas. Os valores na nova lista devem estar ordenados. Essa função deve obedecer ao protótipo:

 Lista* lst_intersec(Lista* l1, Lista* l2); 

Por exemplo, se lista L1 → 5 → 7 → 2 → 4 → // e lista L2 → 7 → 9 → 2 →//, a chamada Lista* L3= lst_intersec(L1,L2) gera a nova lista L3→ 2 →7 →//.

 e) função para gerar uma nova lista que é a concatenação de uma lista l1 no final de uma lista l2. Essa função deve obedecer ao protótipo:

Lista* lst_conc(Lista* l1, Lista* l2);

 f) função que faça a diferença de duas listas l1 e l2 (ou seja, que retire de l1 os elementos que estão em l2). 

Essa função deve obedecer ao protótipo: 

Lista* lst_diferenca(Lista* l1, Lista* l2); 

Por exemplo, se lista L1 → 3 → 7 → 2 → 4 → // e lista L2 → 7 → 9 → //, a chamada Lista* L1 = lst_diferenca(L1,L2) altera a primeira lista para L1 → 3 → 2 → 4 → //.