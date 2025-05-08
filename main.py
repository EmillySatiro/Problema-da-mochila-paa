import time
import csv
import tracemalloc
import random
from functools import lru_cache

def mochila_dinamica(n, capacidade, pesos, valores):
    tabela = [[0] * (capacidade + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for c in range(capacidade + 1):
            if pesos[i - 1] <= c:
                tabela[i][c] = max(valores[i - 1] + tabela[i - 1][c - pesos[i - 1]], tabela[i - 1][c])
            else:
                tabela[i][c] = tabela[i - 1][c]

    return tabela[n][capacidade]

def mochila_recursiva(n, capacidade, pesos, valores):
    @lru_cache(maxsize=None)
    def helper(i, restante):
        if i == 0 or restante == 0:
            return 0
        if pesos[i - 1] > restante:
            return helper(i - 1, restante)
        else:
            incluir = valores[i - 1] + helper(i - 1, restante - pesos[i - 1])
            excluir = helper(i - 1, restante)
            return max(incluir, excluir)
    
    return helper(n, capacidade)

def linha(char: str = "=", tam: int = 70):
    print(char * tam)

def gerar_instancia_aleatoria(nome, n_itens, capacidade_max, peso_max, valor_max):
    pesos = [random.randint(1, peso_max) for _ in range(n_itens)]
    valores = [random.randint(1, valor_max) for _ in range(n_itens)]
    return {"nome": nome, "pesos": pesos, "valores": valores, "capacidade": capacidade_max}

# Lista de instâncias
instancias = [
    gerar_instancia_aleatoria("grande", n_itens=100, capacidade_max=60, peso_max=15, valor_max=50)
]

with open("tempos_mochila_comparativo.csv", mode="w", newline="") as arquivoCSV:
    writer = csv.writer(arquivoCSV)
    writer.writerow(["instancia", "algoritmo", "iteracao", "tempo_s", "memoria_pico_b"])

    iteracoes = 30

    for instancia in instancias:
        pesos = instancia["pesos"]
        valores = instancia["valores"]
        capacidade = instancia["capacidade"]
        nome = instancia["nome"]
        n = len(pesos)

        linha()
        print(f"[MOCHILA {nome.upper()}] n={n}, capacidade={capacidade}")

        for funcao in [mochila_dinamica, mochila_recursiva]:
            nome_algoritmo = funcao.__name__
            print(f"Algoritmo: {nome_algoritmo}")
            for it in range(iteracoes):
                tracemalloc.start()
                inicio = time.perf_counter()

                funcao(n, capacidade, pesos, valores)

                fim = time.perf_counter()
                memoria_atual_b, memoria_pico_b = tracemalloc.get_traced_memory()
                tracemalloc.stop()

                tempo = fim - inicio

                print(f"[{it+1:2}ª] Tempo: {tempo:.6f}s | Pico Memória: {memoria_pico_b} B")
                writer.writerow([nome, nome_algoritmo, it+1, f"{tempo:.6f}", memoria_pico_b])
            linha(char="-", tam=60)
