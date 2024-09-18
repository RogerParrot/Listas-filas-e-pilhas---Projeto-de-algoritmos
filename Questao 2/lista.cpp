#include "lista.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

TipoLista* cria_lista() {
    TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));

    if (lista == NULL) {
        cout << "A alocacao falhou!" << endl;
        return NULL;
    } else {
        cout << "Alocacao feita com sucesso!\n" << endl;
    }

    return lista;
}

void FLVazia(TipoLista* lista) {
    lista->primeiro = (Apontador) malloc(sizeof(TipoCelula)); // "primeiro" vira uma instância da struct TipoCelula e apontar� para a primeira c�lula
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL; // como uma instância, a variável "primeiro" pode acessar o campo "prox"
}

bool Vazia(TipoLista* lista) {
    return(lista->primeiro == lista->ultimo);
}

void insere_celula(TipoItem item, TipoLista *lista, Apontador E) {
    Apontador novo = (Apontador) malloc(sizeof(TipoCelula));

    if (novo == NULL) {
        cout << "A alocacao falhou!" << endl;
        return;
    } else {
        cout << "Alocacao feita com sucesso!" << endl;
    }

    novo->item = item;

    if (lista->primeiro->prox == NULL) {
        lista->ultimo = novo;
    }

    if (lista->primeiro == E) {
        novo->prox = E->prox;
        E->prox = novo;

    } else if (lista->ultimo == E) {
        lista->ultimo->prox = novo;
        novo->prox = NULL;
        lista->ultimo = novo;
    }
}

void remove_celula(TipoItem item, TipoLista *lista) {
    if(lista->primeiro->prox == NULL) {
        cout << "A lista esta vazia!" << endl;

    } else {
        Apontador lixo = lista->primeiro->prox;
        Apontador ant = lista->primeiro;

        while(lixo != NULL) {
            if(lixo->item.chave == item.chave) {
                break;
            }
            ant = lixo;
            lixo = lixo->prox;
        }

        if(lixo == NULL) {
            cout << "O elemento nao foi encontrado!" << endl;

        } else {
            ant->prox = lixo->prox;

            if(lista->ultimo == lixo) {
                lista->ultimo = ant;
            }

            cout << "Elemento removido: " << lixo->item.chave << endl;

            free(lixo);
        }
    }
}

void print_all(TipoLista* lista){
    if (lista->primeiro->prox == NULL) {
        cout << "Lista vazia!" << endl;

    } else {
        int i = 1;

        cout << "Valores na lista: " << endl;
        Apontador print = (Apontador) malloc(sizeof(TipoCelula));

        for (print = lista->primeiro->prox; print != NULL; print = print->prox) {
            cout << "Elemento na posicao " << i << ": " << print->item.chave << endl;
            i++;
        }
    }
}

void libera_lista(TipoLista* lista) {
    free(lista);
}
