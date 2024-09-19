#include "lista.h"
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

int main() {
    TipoLista* lista = cria_lista(); // criando uma instância de lista
    int opcao, num_blocos, chave;
    TipoItem item; // servirá para adicionar elementos à lista
    Apontador E = (Apontador) malloc(sizeof(TipoCelula)); // servirá para definir onde serão adicionados os novos elementos

    if(lista == NULL) { // se a alocação falhar, libera a lista
        libera_lista(lista);

    } else { // se não:
        FLVazia(lista); // faz a lista ficar vazia

        /* Opções do que o usuário irá fazer na lista */
        cout << "Bem vindo a lista encadeada!" << endl;
        cout << "Digite 1 para inserir elemento no inicio" << endl;
        cout << "Digite 2 para inserir elemento no final" << endl;
        cout << "Digite 3 para remover elemento" << endl;
        cout << "Digite 4 para printar os elementos da lista" << endl;
        cout << "Digite 5 para encerrar (liberar memoria alocada!)\n" << endl;

        cout << "O que deseja fazer? ";
        cin >> opcao; // escolha dentre as opções acima

        while(opcao != 5) { // enquanto a opção for diferente de 5
            if(opcao == 1) { // se for para inserir os elementos no início
                cout << "Digite o numero de elementos (blocos) a serem inseridos: ";
                cin >> num_blocos; // quantidade de blocos a serem inseridos

                for(int i = 1; i <= num_blocos; i++) { // função "for" que está de acordo à quantidade de blocos a serem inseridos
                    cout << "Digite o elemento: ";
                    cin >> chave; // elementos a serem inseridos

                    item.chave = chave; // elemento vai para uma instância de item que depois será inserida na lista

                    insere_celula(item, lista, lista->primeiro); // inserção de itens no início
                }

            } else if(opcao == 2){ // se for para inserir os elementos no final
                cout << "Digite o numero de elementos (blocos) a serem inseridos: ";
                cin >> num_blocos; // quantidade de blocos a serem inseridos

                for(int i = 1; i <= num_blocos; i++) { // função "for" que está de acordo à quantidade de blocos a serem inseridos
                    cout << "Digite o elemento: ";
                    cin >> chave; // elementos a serem inseridos

                    item.chave = chave; // elemento vai para uma instância de item que depois será inserida na lista

                    insere_celula(item, lista, lista->ultimo); // inserção de itens no final
                }

            } else if(opcao == 3) { // se for para remover um elemento da lista
                cout << "Digite o elemento que deseja remover: ";
                cin >> chave; // elemento que deseja remover da lista

                item.chave = chave; // elemento vai para uma instância de item que depois servirá para ser removida da lista

                remove_celula(item, lista); // remoção do item indicado

            } else if(opcao == 4) { // se for para imprimir os elementos da lista
                print_all(lista); // função de impressão dos elementos
            }

            cout << "O que deseja fazer? ";
            cin >> opcao; // retorna à escolha dos elementos, pois está num loop de manipulação da lista
        }

        // quando a opção for 5, o loop é quebrado
        libera_lista(lista); // a memória alocada da lista será liberada
    }

    cout << "Lista liberada. Ate mais!" << endl;

    return 0; // final da função main, término do código
}
