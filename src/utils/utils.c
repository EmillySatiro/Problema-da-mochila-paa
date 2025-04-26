#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

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
