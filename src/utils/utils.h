#ifndef UTILS_H
#define UTILS_H

int max(int a, int b);

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila);

void liberarTabela(int **tabela, int numeroItens);

void imprimirItensSelecionados(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);
#endif