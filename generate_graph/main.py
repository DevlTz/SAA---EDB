import subprocess
import numpy as np
import time
import matplotlib.pyplot as plt

# Tipos de dados
def generate_data(size, data_type):
    if data_type == 'aleatorio':
        return np.random.randint(0, 100000, size)
    elif data_type == 'quase_ordenado':
        arr = np.arange(size)
        # Troca 5% dos elementos para "quase ordenado"
        num_swaps = max(1, size // 20)
        for _ in range(num_swaps):
            i, j = np.random.randint(0, size, 2)
            arr[i], arr[j] = arr[j], arr[i]
        return arr
    elif data_type == 'inversamente_ordenado':
        return np.arange(size, 0, -1)
    else:
        raise ValueError("Tipo de dado desconhecido")

# Executa o algoritmo C++ e lê métricas
def run_cpp_algorithm(input_data, algoritmo):
    np.savetxt('input.txt', input_data, fmt='%d')
    start = time.time()
    subprocess.run(['../sorts_in_cpp/output/algorithm.exe', algoritmo, 'input.txt', 'output.txt'])
    end = time.time()
    # Lê comparações e trocas do output.txt (esperado: duas linhas, uma para cada métrica)
    with open('output.txt') as f:
        lines = f.readlines()
        comparacoes = int(lines[0].strip())
        trocas = int(lines[1].strip())
    return end - start, comparacoes, trocas

sizes = [1000, 5000, 10000, 20000, 50000]
data_types = ['aleatorio', 'quase_ordenado', 'inversamente_ordenado']
algorithms = ['insertion', 'selection', 'bubble', 'merge', 'quick']

results = {}
for algo in algorithms:
    results[algo] = {dt: {'tempos': [], 'comparacoes': [], 'trocas': []} for dt in data_types}

for algo in algorithms:
    print(f"\n{'='*50}")
    print(f"ALGORITMO: {algo.upper()}")
    print(f"{'='*50}")
    
    for dt in data_types:
        print(f"\nTipo de dado: {dt}")
        for size in sizes:
            data = generate_data(size, dt)
            tempo, comparacoes, trocas = run_cpp_algorithm(data, algo)
            results[algo][dt]['tempos'].append(tempo)
            results[algo][dt]['comparacoes'].append(comparacoes)
            results[algo][dt]['trocas'].append(trocas)
            print(f"Tamanho: {size}, Tempo: {tempo:.4f}s, Comp: {comparacoes}, Trocas: {trocas}")

# Gráficos comparativos por métrica
for metric, ylabel in zip(['tempos', 'comparacoes', 'trocas'],
                          ['Tempo de execução (s)', 'Comparações', 'Trocas']):
    
    # Gráfico por tipo de dado (todos os algoritmos)
    for dt in data_types:
        plt.figure(figsize=(12, 8))
        for algo in algorithms:
            plt.plot(sizes, results[algo][dt][metric], marker='o', label=f'{algo.capitalize()}', linewidth=2)
        plt.xlabel('Tamanho do vetor')
        plt.ylabel(ylabel)
        plt.title(f'{ylabel} - Dados {dt.replace("_", " ").title()}')
        plt.legend()
        plt.grid(True, alpha=0.3)
        plt.yscale('log' if metric in ['comparacoes', 'trocas'] else 'linear')
        plt.savefig(f'{metric}_{dt}.png', dpi=300, bbox_inches='tight')
        plt.show()
    
    # Gráfico geral (todos os algoritmos, média dos tipos de dados)
    plt.figure(figsize=(12, 8))
    for algo in algorithms:
        # Calcula a média entre os tipos de dados
        media_metric = []
        for i in range(len(sizes)):
            valores = [results[algo][dt][metric][i] for dt in data_types]
            media_metric.append(np.mean(valores))
        plt.plot(sizes, media_metric, marker='o', label=f'{algo.capitalize()}', linewidth=2)
    plt.xlabel('Tamanho do vetor')
    plt.ylabel(ylabel)
    plt.title(f'{ylabel} - Comparação Geral dos Algoritmos (Média)')
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.yscale('log' if metric in ['comparacoes', 'trocas'] else 'linear')
    plt.savefig(f'{metric}_comparacao_geral.png', dpi=300, bbox_inches='tight')
    plt.show()