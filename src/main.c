#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mochila_Dinamica/dinamica.h"

void imprimirMemoriaUsada() {
  FILE* arquivo = fopen("/proc/self/status", "r");
  char linha[128];

  while (fgets(linha, sizeof(linha), arquivo)) {
      if (strncmp(linha, "VmRSS:", 6) == 0) {
          printf("%s", linha);
          break;
      }
  }
  fclose(arquivo);
}

int main() {

    printf("=-=-=-=-=-=-=-Mochila Dinamica-=-=-=-=-=-=-=\n");
    int numeroItens, capacidadeMochila;

    printf("Digite o numero de itens: ");
    scanf("%d", &numeroItens);

    int *pesos = (int *)malloc(numeroItens * sizeof(int));
    int *valores = (int *)malloc(numeroItens * sizeof(int));

    printf("Digite o peso de cada item:\n");
    for (int i = 0; i < numeroItens; i++) {
        scanf("%d", &pesos[i]);
    }

    printf("Digite o valor de cada item:\n");
    for (int i = 0; i < numeroItens; i++) {
        scanf("%d", &valores[i]);
    }

    printf("Digite a capacidade maxima da mochila: ");
    scanf("%d", &capacidadeMochila);

    resolverMochila(numeroItens, capacidadeMochila, pesos, valores);

    // printf("Memoria usada:\n");
    // imprimirMemoriaUsada();                      Só da certo no linux
    // printf("Pressione Enter para continuar...");

    free(pesos);
    free(valores);



    return 0;
}
