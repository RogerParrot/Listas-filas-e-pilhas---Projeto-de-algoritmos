#include "pilha.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Para criar uma pilha
TipoPilha *InicializaPilha() {
  // Aloca memória para a pilha
  TipoPilha *Pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
  return Pilha;
}

// transforma topo em 0
void FPVazia(TipoPilha *Pilha) { Pilha->Topo = 0; }

// se topo = 0, então a pilha está vazia
int Vazia(TipoPilha *Pilha) { return (Pilha->Topo == 0); }

// retorna a posição do topo
int Tamanho_pilha(TipoPilha *Pilha) { return (Pilha->Topo); }

// Função para empilhar (adicionar) um caractere
void Empilhar(char caractere, char *pilha, int &topo) {
  // Incrementa o topo
  topo++;
  // Adiciona o caractere no topo da pilha
  pilha[topo] = caractere;
}

// Retorna o caractere do topo, ou seja, o último a ser adicionado
char verTopo(char *pilha, int topo) { return pilha[topo]; }

// Função para desempilhar (remover) o caractere do topo e retorná-lo
char Desempilhar(char *pilha, int &topo) {
  // Retorna o caractere do topo
  char valor = pilha[topo];
  // Decrementa o topo
  topo--;
  return valor;
}
