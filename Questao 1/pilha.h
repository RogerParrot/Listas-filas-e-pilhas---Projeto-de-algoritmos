typedef int Posicao;
#define InicioVetor 0
#define MaxTam 1000

// Estrutura do Item
typedef struct tipoitem {
  char valor;
} TipoItem;

// Estrutura da Pilha
typedef struct tipopilha {
  TipoItem Item[MaxTam];
  Posicao Topo;
} TipoPilha;

// Iniciar a pilha
TipoPilha *InicializaPilha();
// Verificar se a pilha está vazia
void FPVazia(TipoPilha *);
// Esvazia a pilha
int Vazia(TipoPilha *);
// Verifica tamanho pelo topo
int Tamanho_pilha(TipoPilha *);
// Desempilha 
char Desempilhar(char *pilha, int &topo);
// Empilha
void empilhar(char caractere, char *pilha, int &topo);
// Retorna o valor do topo
char verTopo(char *pilha, int topo);