typedef struct arv Arv;
typedef struct arvno ArvNo;

// Arvore binaria de busca
void abb_imprime (Arv* a);

ArvNo* abb_busca (Arv* a, int v);

Arv* abb_cria(void);

void abb_insere (Arv* a, int v);

void abb_retira (Arv* a, int v);