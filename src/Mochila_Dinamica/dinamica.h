#ifndef DINAMICA_h
#define DINAMICA_h

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila);

int **resolverMochila(int numeroItens, int capacidadeMochila, int pesos[], int valores[], int *valorMaximo);

void liberarTabela(int **tabela, int numeroItens);
#endif