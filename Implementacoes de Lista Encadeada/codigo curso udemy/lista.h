typedef struct lista Lista;

// funcapo de criacao da lista
Lista* criar_lista();

// funcao que insere no inicio da lista
Lista* inserir_lista(Lista* l, int i);

// funcao para imprimir os elementos da lista
void imprimir_lista(Lista* l);

// verifica se a lista esta vazia
int vazia(Lista* l);

// busca elementos na lista
Lista* buscar(Lista* l, int v);