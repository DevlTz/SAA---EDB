#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Variáveis globais para contar métricas
long long comparacoes = 0;
long long trocas = 0;

// Função insertion sort com métricas
void insertion_sort(int arr[], int n) {
    comparacoes = 0;
    trocas = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                trocas++;
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) trocas++; // Contabiliza a inserção final
    }
}

// Função selection sort com métricas
void selection_sort(int arr[], int n) {
    comparacoes = 0;
    trocas = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
            trocas++;
        }
    }
}

// Função bubble sort com métricas
void bubble_sort(int arr[], int n) {
    comparacoes = 0;
    trocas = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool houve_troca = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                trocas++;
                houve_troca = true;
            }
        }
        if (!houve_troca) break; // Otimização: se não houve troca, está ordenado
    }
}

// Função auxiliar merge para merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        trocas++;
    }
    
    while (i < n1) {
        arr[k++] = L[i++];
        trocas++;
    }
    while (j < n2) {
        arr[k++] = R[j++];
        trocas++;
    }
}

// Função merge sort com métricas
void merge_sort_impl(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_impl(arr, left, mid);
        merge_sort_impl(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int n) {
    comparacoes = 0;
    trocas = 0;
    merge_sort_impl(arr, 0, n - 1);
}

// Função auxiliar partition para quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++) {
        comparacoes++;
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                std::swap(arr[i], arr[j]);
                trocas++;
            }
        }
    }
    if (i + 1 != high) {
        std::swap(arr[i + 1], arr[high]);
        trocas++;
    }
    return (i + 1);
}

// Função quick sort recursiva
void quick_sort_impl(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_impl(arr, low, pi - 1);
        quick_sort_impl(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int n) {
    comparacoes = 0;
    trocas = 0;
    quick_sort_impl(arr, 0, n - 1);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <algoritmo> <arquivo_entrada> <arquivo_saida>" << std::endl;
        std::cerr << "Algoritmos disponíveis: insertion, selection, bubble, merge, quick" << std::endl;
        return 1;
    }
    
    std::string algoritmo = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];
    
    // Lê o arquivo de entrada
    std::ifstream infile(input_file);
    if (!infile) {
        std::cerr << "Erro ao abrir arquivo de entrada: " << input_file << std::endl;
        return 1;
    }
    
    std::vector<int> data;
    int value;
    while (infile >> value) {
        data.push_back(value);
    }
    infile.close();
    
    if (data.empty()) {
        std::cerr << "Arquivo de entrada vazio" << std::endl;
        return 1;
    }
    
    // Converte para array
    int* arr = new int[data.size()];
    for (size_t i = 0; i < data.size(); i++) {
        arr[i] = data[i];
    }
    
    // Executa o algoritmo de ordenação escolhido
    if (algoritmo == "insertion") {
        insertion_sort(arr, data.size());
    } else if (algoritmo == "selection") {
        selection_sort(arr, data.size());
    } else if (algoritmo == "bubble") {
        bubble_sort(arr, data.size());
    } else if (algoritmo == "merge") {
        merge_sort(arr, data.size());
    } else if (algoritmo == "quick") {
        quick_sort(arr, data.size());
    } else {
        std::cerr << "Algoritmo desconhecido: " << algoritmo << std::endl;
        std::cerr << "Algoritmos disponíveis: insertion, selection, bubble, merge, quick" << std::endl;
        delete[] arr;
        return 1;
    }
    
    // Escreve as métricas no arquivo de saída
    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cerr << "Erro ao criar arquivo de saída: " << output_file << std::endl;
        delete[] arr;
        return 1;
    }
    
    outfile << comparacoes << std::endl;
    outfile << trocas << std::endl;
    outfile.close();
    
    delete[] arr;
    return 0;
}
