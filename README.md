
# Análise Comparativa: Algoritmos de Programação Dinâmica no Problema da Mochila

Este repositório apresenta uma análise comparativa entre duas abordagens para resolver o Problema da Mochila (Knapsack Problem): uma implementação recursiva e outra utilizando programação dinâmica com memorização. O objetivo é avaliar o desempenho de ambas em termos de tempo de execução e uso de memória.

## Objetivo

O objetivo deste projeto é implementar e comparar duas abordagens para o **Problema da Mochila**:
1. **Algoritmo Recursivo**: Uma solução direta que resolve o problema de forma recursiva.
2. **Algoritmo com Programação Dinâmica**: Utiliza uma abordagem mais eficiente, armazenando soluções intermediárias para evitar recomputação de subproblemas.

A análise compara o desempenho de ambos os algoritmos em diferentes cenários de testes.

## Estrutura do Projeto

O repositório está organizado da seguinte forma:

**main.py**: Script principal contendo as implementações dos algoritmos e a lógica para execução dos testes comparativos.

**tempos_mochila_comparativo.csv**: Arquivo CSV contendo os resultados dos testes, incluindo tempos de execução e uso de memória.

**README.md**: Este arquivo, fornecendo informações sobre o projeto.

## Como Compilar e Executar

### Compilação

1. Clone o repositório:

   ```bash
   git clone https://github.com/seu-usuario/problema-da-mochila.git
   ```
2. Certifique-se de ter o Python instalado (versão 3.6 ou superior).

3. Execute o script principal `main.py` para compilar e executar os algoritmos:

   ```bash
   python main.py
   ```
4. O script irá gerar um arquivo CSV com os resultados dos testes, incluindo tempos de execução e uso de memória.

### Resultados
A análise comparativa revelou que a abordagem com programação dinâmica apresenta desempenho superior em termos de tempo de execução e uso de memória, especialmente em instâncias maiores do problema. A memorização evita recomputações desnecessárias, tornando o algoritmo mais eficiente.

