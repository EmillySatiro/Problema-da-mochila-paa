
# Análise Comparativa: Algoritmos de Programação Dinâmica no Problema da Mochila

Este repositório contém a implementação de uma **análise comparativa** entre dois algoritmos para resolver o **Problema da Mochila**: um utilizando a abordagem **recursiva** e outro utilizando **programação dinâmica (memorização)**. O objetivo é comparar o desempenho de ambos os métodos em termos de **tempo de execução** e **uso de memória**.

## Objetivo

O objetivo deste projeto é implementar e comparar duas abordagens para o **Problema da Mochila**:
1. **Algoritmo Recursivo**: Uma solução direta que resolve o problema de forma recursiva.
2. **Algoritmo com Programação Dinâmica**: Utiliza uma abordagem mais eficiente, armazenando soluções intermediárias para evitar recomputação de subproblemas.

A análise compara o desempenho de ambos os algoritmos em diferentes cenários de testes.

## Estrutura do Projeto

O repositório está organizado da seguinte forma:



## Como Compilar e Executar

### Compilação

1. Clone o repositório:

   ```bash
   git clone https://github.com/seu-usuario/problema-da-mochila.git
   ```

### Execução

Se for a primeira vez executando, pode ser necessário dar permissão ao script. Para isso,use o comando:

```bash
   chmod +x ./build.sh  
```

Navegue até a raiz do projeto e execute o comando:

```bash
   ./build.sh             # Executa o script para compilar e rodar o programa
```
## Cenários de Testes

Os testes foram realizados utilizando os seguintes parâmetros:

- **Pesos dos itens**: `{}`
- **Valores dos itens**: `{}`
- **Capacidade da mochila**: `0`


## Análise de Desempenho

### Critérios de Comparação

O desempenho dos dois algoritmos será comparado considerando os seguintes critérios:

- **Tempo de Execução**: O tempo total necessário para calcular a solução.
- **Memória Consumida**: A quantidade de memória utilizada durante a execução de ambos os algoritmos.

## Detalhes Adicionais

### Algoritmo Recursivo

A implementação recursiva resolve o problema de forma simples, mas com alta complexidade. Ela explora todas as possibilidades de escolha dos itens, recalculando subproblemas múltiplas vezes.

### Algoritmo com Programação Dinâmica

A versão com **programação dinâmica** armazena os resultados de subproblemas em uma tabela e os reutiliza quando necessário, aumentando a eficiência do algoritmo. Esta abordagem evita a redundância do método recursivo e garante um tempo de execução significativamente menor.
