#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b);

void imprimirTabelaItens(int numeroItens, int **tabela, int pesos[], int valores[], int capacidadeMochila);

void liberarTabela(int **tabela, int numeroItens);

void imprimirItensSelecionados(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);

double calcularTempoExecucao(clock_t inicio, clock_t fim);

void exibirMemoria(int numeroItens, int capacidadeMochila);
  
void metodoDinamicaIterativa(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);
  
void metodoDinamicaRecursivaSimples(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);
  
void metodoDinamicaRecursivaMemo(int numeroItens, int capacidadeMochila, int pesos[], int valores[]);
#endif