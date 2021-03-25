typedef struct lista Lista;

Lista* lst_cria(void);

void lst_libera (Lista* l);

void lst_insert(Lista* l, int v);

void lst_insere_ordenado(Lista* l, int v);

void lst_retira(Lista* l, int v);

int lst_vazia(Lista* l);

int lst_pertence(Lista* l, int v);

void lst_imprime(Lista* l);

int lst_igual(Lista* l1, Lista* l2);
