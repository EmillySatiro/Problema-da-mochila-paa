#ifndef UTILS_H
#define UTILS_H

int max(int a, int b);

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila);

void liberarTabela(int **tabela, int numeroItens);

#endif