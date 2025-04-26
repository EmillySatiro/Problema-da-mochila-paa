#include "dinamica.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

int **resolverMochila(int numeroItens, int capacidadeMochila, int pesos[], int valores[], int *valorMaximo) {
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

  *valorMaximo = tabela[numeroItens][capacidadeMochila];

  return tabela;
}
