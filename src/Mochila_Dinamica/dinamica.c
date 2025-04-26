#include "dinamica.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

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

void resolverMochila(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  int **tabela = (int **)malloc((numeroItens + 1) * sizeof(int *));
  for (int i = 0; i <= numeroItens; i++) {
      tabela[i] = (int *)malloc((capacidadeMochila + 1) * sizeof(int));
  }

  for (int item = 0; item <= numeroItens; item++) {
      for (int capacidadeAtual = 0; capacidadeAtual <= capacidadeMochila; capacidadeAtual++) {
          if (item == 0 || capacidadeAtual == 0)
              tabela[item][capacidadeAtual] = 0;
          else if (pesos[item - 1] <= capacidadeAtual)
              tabela[item][capacidadeAtual] = max(valores[item - 1] + tabela[item - 1][capacidadeAtual - pesos[item - 1]], tabela[item - 1][capacidadeAtual]);
          else
              tabela[item][capacidadeAtual] = tabela[item - 1][capacidadeAtual];
      }
  }

  printf("\nValor máximo que pode ser colocado na mochila: %d\n", tabela[numeroItens][capacidadeMochila]);

  imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);

  size_t memoriaTabela = (numeroItens + 1) * sizeof(int*) + (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int);
  size_t memoriaVetores = 2 * numeroItens * sizeof(int);
  size_t memoriaTotal = memoriaTabela + memoriaVetores;

  printf("Memória utilizada: %.2f KB\n", memoriaTotal / 1024.0);

  for (int i = 0; i <= numeroItens; i++) {
      free(tabela[i]);
  }
  free(tabela);
}