#include "lista.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

/* Função que aloca um espaço na memória pra lista */
TipoLista* cria_lista() {
    TipoLista* lista = (TipoLista*) malloc(sizeof(TipoLista));

    // comparação que verifica se a alocação de memótia foi bem sucedida:
    if (lista == NULL) { 
        cout << "A alocacao falhou!" << endl;
        return NULL;
    } else {
        cout << "Alocacao feita com sucesso!\n" << endl;
    }

    return lista; // retorna o valor da lista
}

/* Função que faz a lista ser vazia */
void FLVazia(TipoLista* lista) {
    lista->primeiro = (Apontador) malloc(sizeof(TipoCelula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}

/* Função que verifica se a lista está ou não vazia */
bool Vazia(TipoLista* lista) {
    return(lista->primeiro == lista->ultimo); // retorna se a lista está vazia, ou seja, se a primeira célula da lista é igual a última
}

/* Função que insere uma célula na lista */
void insere_celula(TipoItem item, TipoLista *lista, Apontador E) {
    Apontador novo = (Apontador) malloc(sizeof(TipoCelula)); // criando uma nova célula

    // comparação que verifica se a alocação anterior de memória foi bem sucedida:
    if (novo == NULL) {
        cout << "A alocacao falhou!" << endl;
        return;
    } else {
        cout << "Alocacao feita com sucesso!" << endl;
    }

    novo->item = item; // campo item da nova célula recebe o argumento "item" da função

    if (lista->primeiro->prox == NULL) { // se a lista estiver vazia
        lista->ultimo = novo; // adiciona uma nova célula no final e o campo "ultimo" da lista passa a ser essa célula
    }

    if (lista->primeiro == E) { // se os elementos forem adicionados no início:
        novo->prox = E->prox; // campo "proximo" da nova célula recebe o valor do campo "prox" da cabeça
        E->prox = novo; // campo "proximo" da cabeça passa a ser essa nova célula

    } else if (lista->ultimo == E) { // se os elementos forem adicionados no final:
        lista->ultimo->prox = novo; // campo próximo da ultima célula receberá o endereço da nova
        novo->prox = NULL; // campo próximo da nova será NULL
        lista->ultimo = novo; // última célula da lista será a nova
    }
}

/* Função que remove células da lista */
void remove_celula(TipoItem item, TipoLista *lista) {
    if(lista->primeiro->prox == NULL) { // primeiro verifica se a lista está vazia
        cout << "A lista esta vazia!" << endl; // se sim, não há como remover elementos e printa que a lista está vazia

    } else { // se não:
        Apontador lixo = lista->primeiro->prox; // cria um novo apontador pra receber o endereço da célula que iremos remover
        Apontador ant = lista->primeiro; // novo apontador que será o anterior de "lixo"

        while(lixo != NULL) { // enquanto lixo for diferente de NULL
            if(lixo->item.chave == item.chave) {
                break; // se o elemento de lixo for igual ao argumento elemento, então quebre o loop
            }
            ant = lixo;
            lixo = lixo->prox;
            // ant e lixo percorrem a lista igualmente
        } // lixo terá o valor passado como argumento e ant será o anterior disso

        if(lixo == NULL) { // se lixo for igual a NULL, então o elemento não foi encontrado, encerre a função
            cout << "O elemento nao foi encontrado!" << endl;

        } else { // se não:
            ant->prox = lixo->prox; // anterior de lixo terá o endereço do próximo de lixo

            if(lista->ultimo == lixo) { // se lixo for a ultima célula
                lista->ultimo = ant; // última célula passa a ser a anterior
            }

            cout << "Elemento removido: " << lixo->item.chave << endl;

            free(lixo); // libera lixo;
        }
    }
}

/* Função que imprime todos os elementos da lista */
void print_all(TipoLista* lista){
    if (lista->primeiro->prox == NULL) { // se a lista estiver vazia, então imprima a mensagem e encerre
        cout << "Lista vazia!" << endl;

    } else { // se não:
        int i = 1;

        cout << "Valores na lista: " << endl;
        Apontador print = (Apontador) malloc(sizeof(TipoCelula)); // aloca um espaço para a variável que percorrerá a lista que imprimirá os elementos

        for (print = lista->primeiro->prox; print != NULL; print = print->prox) { // print começa na primeira célula, vai até a última, percorrendo de prox em prox
            cout << "Elemento na posicao " << i << ": " << print->item.chave << endl; // printa os elementos
            i++; // incrementa i
        }
    }
}

/* Função que libera a memória alocada da lista */
void libera_lista(TipoLista* lista) {
    free(lista); // libera a memória alocada à lista
}
