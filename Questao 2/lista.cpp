#include "lista.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

TipoLista* cria_lista() {
    TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));
    return lista;
}

void FLVazia(TipoLista* lista) {
    lista->primeiro = (Apontador) malloc(sizeof(TipoCelula)); // "primeiro" vira uma instância da struct TipoCelula e apontar� para a primeira c�lula
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL; // como uma instância, a variável "primeiro" pode acessar o campo "prox"
}

int Vazia(TipoLista* lista) {
    return(lista->primeiro == lista->ultimo);
}

void insere_celula(TipoItem *item, TipoLista* lista, Apontador E) { // Apontador já é ponteiro, logo E também vira um; E recebe o endereço da célula que irá receber a nova célula após ela
    TipoCelula* novo = (TipoCelula*) malloc(sizeof(TipoCelula)); // nova celula para ser adicionada
    novo->item = *item; // adicionando no campo item da nova celula
    novo->prox = E->prox; // novo aponta pra célula posterior à E
    E->prox = novo; // recebe endereço da nova celula

    if(lista->primeiro->prox == NULL) { // se a lista estiver vazia; se E for o inicio
        novo->prox = NULL; // campo prox da nova celula = null
    }

    if(lista->ultimo == E) { // se E for o final
        lista->ultimo = novo; // campo ultimo aponta pra nova célula adicionada
        novo->prox = NULL;
    }
}

TipoCelula* busca_celula(TipoLista* lista, TipoChave chave) {
    TipoCelula* busca = (Apontador) malloc(sizeof(TipoCelula));
    busca->item.chave = chave;
    for(Apontador p = lista->primeiro->prox; p != NULL; p = p->prox) {
        if(p->item.chave == busca->item.chave) {
            return busca;
        }
    }

    return NULL;
}

void remove_celula(TipoLista* lista, TipoChave chave){
    TipoCelula* lixo = (Apontador) malloc(sizeof(TipoCelula));
    lixo->item.chave = chave;
    if(busca_celula(lista, chave) == lixo) {
        cout << lixo->item.chave << endl;
        free(lixo);
    }
}

void libera_lista(TipoLista* lista) {
    free(lista);
}

/* -- CHECKPOINT DO PROGRESSO -- */