typedef int TipoChave;

typedef struct {
    TipoChave chave;
    // outros componentes
} TipoItem;

typedef struct Celula_str *Apontador;

typedef struct Celula_str{
    TipoItem item;
    Apontador prox;
} TipoCelula;

typedef struct {
    Apontador primeiro, ultimo; // "primeiro" e "ultimo" apontam para a primeira e a �ltima c�lula, respectivamente (ou seja, por eles vamos manipular os campos da primeira e da ultima c�lula)
} TipoLista;

// quando for fazer uma opera��o que envolve esse sinal: "->"; n�o usar o tipo, e sim a vari�vel, pois � ela que guarda as informa��es da struct, o tipo serve apenas para declarar a estrutura na qual a vari�vel pertence.

TipoLista* cria_lista();
void FLVazia(TipoLista*);
int Vazia(TipoLista*);
void insere_celula(TipoLista*, TipoCelula*, Apontador);
TipoCelula* busca_celula(TipoLista*, TipoChave);
void remove_celula(TipoLista*);
void libera_lista(TipoLista*);
