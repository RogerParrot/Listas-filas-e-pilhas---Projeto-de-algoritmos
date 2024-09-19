#include "pilha.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {

  // Onde guardaremos a palavra.
  string palavra;

  // Variável que guarda a opção do usuário
  int opcao;

  cout << "Digite uma palavra: ";
  cin >> palavra;

  // Criação da pilha dinamicamente
  char *pilha =
      new char[palavra.length() + 100]; // Buffer extra para novas inserções
  int topo = -1;                        // A pilha está inicialmente vazia

  // Empilhar os caracteres da palavra. Se 
  for (int i = 0; i < palavra.length(); i++) {
    // Função empilhar irá salvar caractere por caractere na pilha
    Empilhar(palavra[i], pilha, topo);
  }

  do {
    // Escolha do usuário
    cout << "\nEscolha uma opção: " << endl;
    cout << "1: Inverter a palavra" << endl;
    cout << "2: Ver elemento do topo" << endl;
    cout << "3: Verificar se a palavra é um palíndromo" << endl;
    cout << "4: Adicionar caractere" << endl;
    cout << "5: Remover caractere do topo" << endl;
    cout << "6: Sair" << endl;
    cin >> opcao;

    switch (opcao) {
    case 1: { // Inverter a palavra
      string palavraInvertida;

      // Para colocarmos limite na 'desempilhação'
      while (topo != -1) {
        palavraInvertida += Desempilhar(pilha, topo);
      }

      // Retorna a palavra invertida
      cout << "Palavra Invertida: " << palavraInvertida << endl;
      // Re-empilhar os caracteres após a inversão para permitir outras operações
      // Caso isso não seja feito, a palavra invertida permanecerá na pilha e irá embaralhar tudo.
      for (char c : palavraInvertida) {
        Empilhar(c, pilha, topo);
      }
      break;
    }

    case 2: { // Ver elemento do topo
      // Signifia que não é -1, ou seja, a pilha não está vazia.
      if (topo != -1) {
        cout << "Caractere no topo da pilha: " << verTopo(pilha, topo) << endl;
      } else {
        cout << "A pilha está vazia." << endl;
      }
      break;
    }

    case 3: { // Verificar se é palíndromo

      // Passamos a nova palavra como string 
      string palavraInvertida;

      // Fazemos a contagem do topo para que possamos desempilhar igualmente
      int count = topo;

      // Enquanto o topo não for -1, desempilhamos e salvamos na nova string. 
      // Quando o topo for -1, a pilha estará vazia e o processo para.
      while (count != -1) {
        // Chamamos a função que irá desempilhar e salvar na nova string, enquanto usa o count.
        palavraInvertida += Desempilhar(pilha, count);
      }
      // Condição para caso a palavra palavra original digitada pelo usuario
      // Seja igual a palavra invertida, então estamos vendo um palíndromo.
      if (palavra == palavraInvertida) {
        cout << "A palavra '" << palavra << "' é um palíndromo." << endl;
      } else {
        cout << "A palavra '" << palavra << "' não é um palíndromo." << endl;
      }
      // Reempilhar para restaurar o estado original, mesmo motivo que usamos no caso de desempilhar.
      for (char c : palavraInvertida) {
        // Usa a palavra invertida e poe no formato original
        Empilhar(c, pilha, topo);
      }
      break;
    }

    case 4: { // Adicionar caracteres
      // Será adicionado ao topo pela lei das pilhas, sendo do tipo char
      char novoCaractere;
      cout << "Digite UM ÚNICO caractere para adicionar ao topo: ";
      cout << "OBS: Será adicionado ao topo da palavra ORIGINAL: ";
      cin >> novoCaractere;
      // Irá empilhar no "novo topo".
      Empilhar(novoCaractere, pilha, topo);
      // A palavra do usuário é atualizada com o novo caractere.
      palavra += novoCaractere; 
      cout << "Caractere '" << novoCaractere
           << "' adicionado ao topo da palavra ORIGINAL ." << endl;
      break;
    }

    case 5: { // Remover caractere do topo
      // Pela lei, só podemos desempilhar a partir do topo
      // Para checar se a pilha não está vazia
      if (topo != -1) {
        // Desempilha 
        char removido = Desempilhar(pilha, topo);
        palavra.pop_back(); // Atualizar a string da palavra
        cout << "Caractere '" << removido << "' removido do topo." << endl;
      } else {
        cout << "A pilha está vazia. Nada para remover." << endl;
      }
      break;
    }

    case 6: {
      cout << "Saindo..." << endl;
      break;
    }

    default:
      cout << "Opção inválida. Tente novamente." << endl;
      break;
    }

  } while (opcao != 6);

  // Para liberar a memória alocada dinamicamente
  delete[] pilha;
  
  return 0;
}
