#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Mochila_Dinamica/dinamica.h"


int main() {
  printf("=-=-=-=-=-=-=-Mochila Dinâmica-=-=-=-=-=-=-=\n");

  int numeroItens, capacidadeMochila;

  printf("Digite o número de itens: ");
  scanf("%d", &numeroItens);

  int *pesos = (int *)malloc(numeroItens * sizeof(int));
  int *valores = (int *)malloc(numeroItens * sizeof(int));

  printf("Digite os dados de cada item:\n");
  for (int i = 0; i < numeroItens; i++) {
      printf("\nItem %d:\n", i + 1);
      printf("Digite o peso do item %d: ", i + 1);
      scanf("%d", &pesos[i]);
      printf("Digite o valor do item %d: ", i + 1);
      scanf("%d", &valores[i]);
  }
  
  printf("Digite a capacidade máxima da mochila: ");
  scanf("%d", &capacidadeMochila);

  // substituir por uma função que calcula o tempo para os dois algoritimos
  clock_t inicio = clock();

  int valorMaximo;
  int **tabela = resolverMochila(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);

  // Parar de medir o tempo
  clock_t fim = clock();
  double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

  printf("\nValor máximo que pode ser colocado na mochila: %d\n", valorMaximo);

  imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);

  printf("Tempo de execução: %.6f segundos\n", tempoExecucao);

  // talvez colocar essa parte em uma função - se é que ela esta certa, não sei se é isso que ele quiria
  size_t memoriaTabela = (numeroItens + 1) * sizeof(int*) + (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int);
  size_t memoriaVetores = 2 * numeroItens * sizeof(int);
  size_t memoriaTotal = memoriaTabela + memoriaVetores;

  printf("Memória utilizada: %.2f KB\n", memoriaTotal / 1024.0);

  liberarTabela(tabela, numeroItens);
  free(pesos);
  free(valores);

  return 0;
}