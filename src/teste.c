#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils/utils.h"
#include "Mochila_Dinamica/dinamica.h"
#include "Mochila_recursiva/recursiva.h"

int main()
{
    srand(time(NULL));

    int numeroItens = 10000;
    int pesos[numeroItens];
    int valores[numeroItens];

    for (int i = 0; i < numeroItens; i++) {
        pesos[i] = rand() % 10 + 1;   // Pesos entre 1 e 10
        valores[i] = rand() % 20 + 1; // Valores entre 1 e 20
    }

    int capacidadeMochila = 5000;
    int valorMaximo = 0;

    clock_t inicio, fim;
    double tempoGastoRecursivoTotal = 0.0;
    double tempoGastoDinamicoTotal = 0.0;
    double memoriaRecursivaTotal = 0.0;
    double memoriaDinamicaTotal = 0.0;

    double temposRecursivos[30];
    double temposDinamicos[30];

    // Realiza 30 testes
    for (int i = 0; i < 30; i++) {
        // Alocação da tabela para memoização
        int **tabela = (int **)malloc((numeroItens + 1) * sizeof(int *));
        for (int j = 0; j <= numeroItens; j++) {
            tabela[j] = (int *)malloc((capacidadeMochila + 1) * sizeof(int));
        }

        // Inicializa a tabela com -1 (indicando que os valores não foram calculados ainda)
        for (int j = 0; j <= numeroItens; j++) {
            for (int k = 0; k <= capacidadeMochila; k++) {
                tabela[j][k] = -1;
            }
        }

        // Marca o tempo de início para a função recursiva com memoização
        inicio = clock();
        int resultadoRecursivo = mochilaRecursivaComMemo(numeroItens, capacidadeMochila, pesos, valores, tabela);
        fim = clock();
        double tempoRecursivo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        temposRecursivos[i] = tempoRecursivo;
        tempoGastoRecursivoTotal += tempoRecursivo;

        // Calcula a memória usada pela função recursiva
        double memoriaRecursiva = (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int) + sizeof(pesos) + sizeof(valores) + sizeof(resultadoRecursivo);
        memoriaRecursivaTotal += memoriaRecursiva;

        // Marca o tempo de início para a função recursiva com memoização (diferente da recursiva normal)
        inicio = clock();
        int **tabelaDinamica = resolverMochilaRecursiva(numeroItens, capacidadeMochila, pesos, valores, &valorMaximo);
        fim = clock();
        double tempoDinamico = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        temposDinamicos[i] = tempoDinamico;
        tempoGastoDinamicoTotal += tempoDinamico;

        // Calcula a memória usada pela função dinâmica
        double memoriaDinamica = sizeof(pesos) + sizeof(valores) + sizeof(valorMaximo) + sizeof(tabelaDinamica) + (numeroItens + 1) * (capacidadeMochila + 1) * sizeof(int);
        memoriaDinamicaTotal += memoriaDinamica;

        // Libera a memória alocada para a tabela de memoização
        for (int j = 0; j <= numeroItens; j++) {
            free(tabela[j]);
        }
        free(tabela);
    }

    // Calculando as médias
    double mediaTempoRecursivo = tempoGastoRecursivoTotal / 30;
    double mediaTempoDinamico = tempoGastoDinamicoTotal / 30;
    double mediaMemoriaRecursiva = memoriaRecursivaTotal / 30;
    double mediaMemoriaDinamica = memoriaDinamicaTotal / 30;

    // Exibe os resultados em formato de tabela
    printf("\nResultados de Tempo:\n");
    printf("+----------------------+-------------------+-------------------+\n");
    printf("| Teste               | Recursivo (s)    | Dinâmico (s)      |\n");
    printf("+----------------------+-------------------+-------------------+\n");
    for (int i = 0; i < 30; i++) {
        printf("| Teste %2d            | %.6f         | %.6f         |\n", i + 1, temposRecursivos[i], temposDinamicos[i]);
    }
    printf("+----------------------+-------------------+-------------------+\n");
    printf("| Média               | %.6f         | %.6f         |\n", mediaTempoRecursivo, mediaTempoDinamico);
    printf("+----------------------+-------------------+-------------------+\n");

    printf("\nResultados Médios de Memória:\n");
    printf("+----------------------+-------------------+-------------------+\n");
    printf("| Método               | Memória (bytes)  |\n");
    printf("+----------------------+-------------------+\n");
    printf("| Recursivo            | %.0f            |\n", mediaMemoriaRecursiva);
    printf("| Dinâmico             | %.0f            |\n", mediaMemoriaDinamica);
    printf("+----------------------+-------------------+\n");

    return 0;
}
