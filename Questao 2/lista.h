// TipoChave tem valor int (detalhe apenas semântico):
typedef int TipoChave;

// declarando a struct que guarda o conjunto de dados/elementos:
typedef struct {
    TipoChave chave; // elemento chave
} TipoItem;

typedef struct Celula_str *Apontador; // declarando a variável que irá receber o endereço das células

// declarando a struct que define as células:
typedef struct Celula_str{
    TipoItem item; // campo que guarda o conjunto de dados/elementos
    Apontador prox; // campo que encadeia a próxima célula
} TipoCelula;

// declarando a struct que define a lista:
typedef struct {
    Apontador primeiro, ultimo; // "primeiro" e "ultimo" apontam para a primeira e a �ltima c�lula, respectivamente (ou seja, por eles vamos manipular os campos da primeira e da ultima célula)
} TipoLista;

// quando for fazer uma operação que envolve esse sinal: "->"; não usar o tipo, e sim a variável, pois é ela que guarda as informações da struct, o tipo serve apenas para declarar a estrutura na qual a variável pertence.

TipoLista* cria_lista(); // aloca um espaço na memória pra lista
void FLVazia(TipoLista*); // faz a lista ser vazia
bool Vazia(TipoLista*); // retorna se a lista é vazia
void insere_celula(TipoItem, TipoLista*, Apontador);
void remove_celula(TipoItem, TipoLista*);
void print_all(TipoLista*); // imprime todos os elementos da lista
void libera_lista(TipoLista*); // libera a memória alocada da lista
