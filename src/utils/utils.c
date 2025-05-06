#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Mochila_recursiva/recursiva.h"
#include "../Mochila_Dinamica/dinamica.h"



void liberarTabela(int **tabela, int numeroItens) {
  for (int i = 0; i <= numeroItens; i++) {
      free(tabela[i]);
  }
  free(tabela);
}

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila) {
  printf("\n===== Tabela de Itens Selecionados =====\n");
  printf("  Item  |  Peso  |  Valor  \n");
  printf("----------------------------------------\n");

  int capacidadeRestante = capacidadeMochila;
  for (int item = numeroItens; item > 0 && capacidadeRestante > 0; item--) {
      if (tabela[item][capacidadeRestante] != tabela[item - 1][capacidadeRestante]) {
          printf("  %-4d  |  %-5d  |  %-5d\n", item, pesos[item - 1], valores[item - 1]);
          capacidadeRestante -= pesos[item - 1];
      }
  }
  printf("\n");
}

void imprimirItensSelecionados(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  if (numeroItens > 0 && capacidadeMochila > 0) {
      if (pesos[numeroItens - 1] > capacidadeMochila) {
          imprimirItensSelecionados(numeroItens - 1, capacidadeMochila, pesos, valores);
      } else {
          int incluirItem = valores[numeroItens - 1] + mochilaRecursiva(numeroItens - 1, capacidadeMochila - pesos[numeroItens - 1], pesos, valores);
          int excluirItem = mochilaRecursiva(numeroItens - 1, capacidadeMochila, pesos, valores);

          if (incluirItem > excluirItem) {
              printf("Item %-2d | Peso %-3d | Valor %-3d\n", numeroItens, pesos[numeroItens - 1], valores[numeroItens - 1]);
              imprimirItensSelecionados(numeroItens - 1, capacidadeMochila - pesos[numeroItens - 1], pesos, valores);
          } else {
              imprimirItensSelecionados(numeroItens - 1, capacidadeMochila, pesos, valores);
          }
      }
  }
  return;
}

double calcularTempoExecucao(clock_t inicio, clock_t fim) {
  return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void exibirMemoria(int numeroItens, int capacidadeMochila) {
  size_t memoriaTabela = (numeroItens + 1) * sizeof(int*) + (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int);
  size_t memoriaVetores = 2 * numeroItens * sizeof(int);
  size_t memoriaTotal = memoriaTabela + memoriaVetores;

  printf("\nMemória utilizada (estimada): %.2f KB\n", memoriaTotal / 1024.0);
}

void metodoDinamicaIterativa(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  int valorMaximo = 0;
  clock_t inicio = clock();
  int **tabela = resolverMochila(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);
  clock_t fim = clock();
  double tempoExecucao = calcularTempoExecucao(inicio, fim);

  printf("\n==== Método 1: Programação Dinâmica (Iterativo) ====\n");
  printf("Valor máximo: %d\n", valorMaximo);
  imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);
  printf("Tempo de execução: %.6f segundos\n", tempoExecucao);
  liberarTabela(tabela, numeroItens);
  printf("====================================================\n");
}

void metodoDinamicaRecursivaSimples(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  clock_t inicio = clock();
  int valorMaximo = mochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores);
  clock_t fim = clock();
  double tempoExecucao = calcularTempoExecucao(inicio, fim);

  printf("\n==== Método 2: Programação Dinâmica (Recursiva Simples) ====\n");
  printf("Valor máximo: %d\n", valorMaximo);
  imprimirItensSelecionados(numeroItens, capacidadeMochila, pesos, valores);
  printf("Tempo de execução: %.6f segundos\n", tempoExecucao);
  printf("====================================================\n");
}

void metodoDinamicaRecursivaMemo(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
  int valorMaximo = 0;
  clock_t inicio = clock();
  int **tabela = resolverMochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);
  clock_t fim = clock();
  double tempoExecucao = calcularTempoExecucao(inicio, fim);

  printf("\n==== Método 3: Programação Dinâmica (Recursiva com Memoização) ====\n");
  printf("Valor máximo: %d\n", valorMaximo);
  imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);
  printf("Tempo de execução: %.6f segundos\n", tempoExecucao);
  liberarTabela(tabela, numeroItens);
  printf("====================================================\n");
}



int max(int a, int b) {
    return (a > b) ? a : b;
}

