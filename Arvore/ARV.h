typedef struct arv Arv;
typedef struct arvno ArvNo;

Arv* arv_cria();

ArvNo* arv_criano (char c, ArvNo* e, ArvNo* d);

void arv_libera (Arv* a);

void arv_imprime (Arv* a);

int arv_pertence (Arv* a, char c);

ArvNo* arv_busca (Arv* a, char c);

int arv_altura (Arv* a);
