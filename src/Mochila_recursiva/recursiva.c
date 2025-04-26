#include "recursiva.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

// forma mais simples 
#include <stdio.h>

int mochilaRecursiva(int numeroItens, int capacidadeMochila, int pesos[], int valores[]) {
    int resultado = 0;

    if (numeroItens == 0 || capacidadeMochila == 0) {
        resultado = 0;
    } else if (pesos[numeroItens - 1] > capacidadeMochila) {
        resultado = mochilaRecursiva(numeroItens - 1, capacidadeMochila, pesos, valores);
    } else {
        int incluirItem = valores[numeroItens - 1] + mochilaRecursiva(numeroItens - 1, capacidadeMochila - pesos[numeroItens - 1], pesos, valores);
        int excluirItem = mochilaRecursiva(numeroItens - 1, capacidadeMochila, pesos, valores);
        resultado = (incluirItem > excluirItem) ? incluirItem : excluirItem;
    }

    return resultado;
}

// forma melhorada 

int mochilaRecursivaComMemo(int item, int capacidadeAtual, int pesos[], int valores[], int **tabela) {
    int resultado = 0;

    // Caso base: se não há mais itens ou a capacidade da mochila é 0
    if (item == 0 || capacidadeAtual == 0) {
        resultado = 0;
    } else if (tabela[item][capacidadeAtual] != -1) { // Verifica se já foi calculado
        resultado = tabela[item][capacidadeAtual];
    } else {
        // Caso onde o item não cabe na mochila
        if (pesos[item - 1] > capacidadeAtual) {
            resultado = mochilaRecursivaComMemo(item - 1, capacidadeAtual, pesos, valores, tabela);
        } else {
            // Caso onde decidimos pegar ou não o item
            int incluirItem = valores[item - 1] + mochilaRecursivaComMemo(item - 1, capacidadeAtual - pesos[item - 1], pesos, valores, tabela);
            int excluirItem = mochilaRecursivaComMemo(item - 1, capacidadeAtual, pesos, valores, tabela);
            resultado = max(incluirItem, excluirItem); // Armazena o valor máximo entre incluir ou não o item
        }
    }

    tabela[item][capacidadeAtual] = resultado; // Armazena o resultado calculado na tabela
    return resultado;
}


// chamada organizada a função otimizada 

int **resolverMochilaRecursiva(int numeroItens, int capacidadeMochila, int pesos[], int valores[], int *valorMaximo) {
    // Aloca a tabela de memoização
    int **tabela = malloc((numeroItens + 1) * sizeof(int *));
    if (tabela == NULL) {
        printf("Erro ao alocar memória para a tabela!\n");
        exit(EXIT_FAILURE);
    }

    // Aloca cada linha da tabela
    for (int i = 0; i <= numeroItens; i++) {
        tabela[i] = malloc((capacidadeMochila + 1) * sizeof(int));
        if (tabela[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d da tabela!\n", i);
            exit(EXIT_FAILURE);
        }
        // Inicializa cada célula da tabela com -1
        for (int j = 0; j <= capacidadeMochila; j++) {
            tabela[i][j] = -1; // -1 indica que o valor ainda não foi calculado
        }
    }

    // Chama a função recursiva para preencher a tabela
    *valorMaximo = mochilaRecursivaComMemo(numeroItens, capacidadeMochila, pesos, valores, tabela);

    // Retorna a tabela preenchida
    return tabela;
}

