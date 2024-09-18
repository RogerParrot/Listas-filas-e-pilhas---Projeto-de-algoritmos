#include "lista.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main() {
    TipoLista* lista = cria_lista();
    int opcao, num_blocos, chave;
    TipoItem item;
    Apontador E = (Apontador) malloc(sizeof(TipoCelula));

    if(lista == NULL) {
        libera_lista(lista);

    } else {
        FLVazia(lista);

        cout << "Bem vindo a lista encadeada!" << endl;
        cout << "Digite 1 para inserir elemento no inicio" << endl;
        cout << "Digite 2 para inserir elemento no final" << endl;
        cout << "Digite 3 para remover elemento" << endl;
        cout << "Digite 4 para printar os elementos da lista" << endl;
        cout << "Digite 5 para encerrar (liberar memoria alocada!)\n" << endl;

        cout << "O que deseja fazer? ";
        cin >> opcao;

        while(opcao != 5) {
            if(opcao == 1) {
                cout << "Digite o numero de elementos (blocos) a serem inseridos: ";
                cin >> num_blocos;

                for(int i = 1; i <= num_blocos; i++) {
                    cout << "Digite o elemento: ";
                    cin >> chave;

                    item.chave = chave;

                    insere_celula(item, lista, lista->primeiro);
                }

            } else if(opcao == 2){
                cout << "Digite o numero de elementos (blocos) a serem inseridos: ";
                cin >> num_blocos;

                for(int i = 1; i <= num_blocos; i++) {
                    cout << "Digite o elemento: ";
                    cin >> chave;

                    item.chave = chave;

                    insere_celula(item, lista, lista->ultimo);
                }

            } else if(opcao == 3) {
                cout << "Digite o elemento que deseja remover: ";
                cin >> chave;

                item.chave = chave;

                remove_celula(item, lista);

            } else if(opcao == 4) {
                print_all(lista);
            }

            cout << "O que deseja fazer? ";
            cin >> opcao;
        }

        libera_lista(lista);
    }

    cout << "Lista liberada. Ate mais!" << endl;

    return 0;
}
