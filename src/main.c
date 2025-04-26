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
    printf("\n");

    // programação Dinâmica Iterativa
    int valorMaximo = 0;
    clock_t inicio = clock();
    int **tabela = resolverMochila(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);
    clock_t fim = clock();
    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("==> Método 1: Programação Dinâmica (Iterativo)\n");
    printf("Valor máximo: %d\n", valorMaximo);
    imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);
    printf("Tempo de execução: %.6f segundos\n", tempoExecucao);

    liberarTabela(tabela, numeroItens);
    printf("---------------------------------------------\n");

    // programação Dinâmica Recursiva (Sem memoização)
    inicio = clock();
    valorMaximo = mochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores);
    fim = clock();
    tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("==> Método 2: Programação Dinâmica (Recursiva Simples)\n");
    printf("Valor máximo: %d\n", mochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores));
    printf("Tempo de execução: %.6f segundos\n", tempoExecucao);
    imprimirItensSelecionados(numeroItens, capacidadeMochila, pesos, valores);
    printf("---------------------------------------------\n");

    // programação Dinâmica Recursiva com memoização 
    inicio = clock();
    tabela = resolverMochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);
    fim = clock();
    tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("==> Método 3: Programação Dinâmica (Recursiva com Memoização)\n");
    printf("Valor máximo: %d\n", valorMaximo);
    imprimirTabelaItens(numeroItens, tabela, pesos, valores, capacidadeMochila);
    printf("Tempo de execução: %.6f segundos\n", tempoExecucao);

    liberarTabela(tabela, numeroItens);
    printf("---------------------------------------------\n");

    // talvez colocar essa parte em uma função - se é que ela esta certa, não sei se é isso que ele queria
    size_t memoriaTabela = (numeroItens + 1) * sizeof(int*) + (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int);
    size_t memoriaVetores = 2 * numeroItens * sizeof(int);
    size_t memoriaTotal = memoriaTabela + memoriaVetores;

    printf("Memória utilizada (estimada): %.2f KB\n", memoriaTotal / 1024.0);

    // Liberar vetores
    free(pesos);
    free(valores);

    return 0;
}
