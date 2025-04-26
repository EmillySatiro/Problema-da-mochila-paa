#ifndef RECURSIVA_H
#define RECURSIVA_H


int mochilaRecursiva(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);
int mochilaRecursivaComMemo(int item, int capacidadeAtual, int pesos[], int valores[], int **tabela); 

int **resolverMochilaRecursiva(int numeroItens, int capacidadeMochila, int pesos[], int valores[], int *valorMaximo);

#endif