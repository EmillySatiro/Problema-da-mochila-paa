#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Mochila_Dinamica/dinamica.h"
#include "Mochila_recursiva/recursiva.h"
#include "utils/utils.h"

int main() {
  printf("=-=-=-=-=-=-=-Mochila Dinâmica-=-=-=-=-=-=-=\n");

  int numeroItens, capacidadeMochila;

  // Entrada de dados
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

  // Capacidade da mochila
  printf("Digite a capacidade máxima da mochila: ");
  scanf("%d", &capacidadeMochila);
  printf("\n");

  // Rodando os métodos
  metodoDinamicaIterativa(numeroItens, capacidadeMochila, pesos, valores);
  metodoDinamicaRecursivaSimples(numeroItens, capacidadeMochila, pesos, valores);
  metodoDinamicaRecursivaMemo(numeroItens, capacidadeMochila, pesos, valores);

  // Exibindo a memória utilizada
  exibirMemoria(numeroItens, capacidadeMochila);

  // Liberando memória
  free(pesos);
  free(valores);

  return 0;
}