#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Mochila_recursiva/recursiva.h"

int max(int a, int b) {
  return (a > b) ? a : b;
}

void liberarTabela(int **tabela, int numeroItens) {
  for (int i = 0; i <= numeroItens; i++) {
      free(tabela[i]);
  }
  free(tabela);
}

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila) {
  printf("\nTabela de Itens Selecionados (começando de 1):\n");
  printf("Item | Peso | Valor\n");
  printf("---------------------\n");

  int capacidadeRestante = capacidadeMochila;
  for (int item = numeroItens; item > 0 && capacidadeRestante > 0; item--) {
      if (tabela[item][capacidadeRestante] != tabela[item - 1][capacidadeRestante]) {
          printf("%d    | %d   | %d\n", item, pesos[item - 1], valores[item - 1]);
          capacidadeRestante -= pesos[item - 1];
      }
  }
  printf("\n");
}

void imprimirItensSelecionados(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  if (numeroItens == 0 || capacidadeMochila == 0) {
      return;
  }
  
  if (pesos[numeroItens - 1] > capacidadeMochila) {
      imprimirItensSelecionados(numeroItens - 1, capacidadeMochila, pesos, valores);
  } 
  else {
      int incluirItem = valores[numeroItens - 1] + mochilaRecursiva(numeroItens - 1, capacidadeMochila - pesos[numeroItens - 1], pesos, valores);
      int excluirItem = mochilaRecursiva(numeroItens - 1, capacidadeMochila, pesos, valores);
      
      if (incluirItem > excluirItem) {
          printf("Item %d | Peso %d | Valor %d\n", numeroItens, pesos[numeroItens - 1], valores[numeroItens - 1]);
          imprimirItensSelecionados(numeroItens - 1, capacidadeMochila - pesos[numeroItens - 1], pesos, valores); // Chama recursivamente para os itens restantes
      } else {
          imprimirItensSelecionados(numeroItens - 1, capacidadeMochila, pesos, valores); // Se não incluir o item, vai para o próximo
      }
  }
}
