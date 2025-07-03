import subprocess
import numpy as np
import time

import matplotlib.pyplot as plt

# Função para gerar dados aleatórios
def generate_data(size):
    return np.random.randint(0, 100000, size)

# Função para executar o algoritmo C++ e medir o tempo
def run_cpp_algorithm(input_data):
    # Salva os dados em um arquivo temporário
    np.savetxt('input.txt', input_data, fmt='%d')
    start = time.time()
    # Executa o algoritmo C++ (ajuste o caminho se necessário)
    subprocess.run(['./algorithm.exe', 'input.txt', 'output.txt'])
    end = time.time()
    return end - start

# Tamanhos dos vetores para teste
sizes = [1000, 5000, 10000, 20000, 50000]
times = []

for size in sizes:
    data = generate_data(size)
    elapsed = run_cpp_algorithm(data)
    times.append(elapsed)
    print(f"Tamanho: {size}, Tempo: {elapsed:.4f} segundos")

# Gera o gráfico
plt.plot(sizes, times, marker='o')
plt.xlabel('Tamanho do vetor')
plt.ylabel('Tempo de execução (s)')
plt.title('Desempenho do Algoritmo de Ordenação')
plt.grid(True)
plt.savefig('metricas_tempo.png')
plt.show()