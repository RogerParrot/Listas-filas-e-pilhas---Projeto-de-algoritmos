typedef int Posicao;
#define InicioVetor 0
#define MaxTam 1000

typedef struct tipoitem {
  char valor;
} TipoItem;

typedef struct tipopilha {
  TipoItem Item[MaxTam];
  Posicao Topo;
} TipoPilha;

TipoPilha *InicializaPilha();
void FPVazia(TipoPilha *);
int Vazia(TipoPilha *);
int Tamanho_pilha(TipoPilha *);
char Desempilhar(char *pilha, int &topo);
void empilhar(char caractere, char *pilha, int &topo);
char verTopo(char *pilha, int topo);