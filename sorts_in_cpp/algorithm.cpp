#include <iostream>
#include <vector>
#include <cstdlib>

// Tamanhos dos vetores testados
const int tamanhos[] = {10, 100, 1000, 10000};

// Start with the second element and compares if itself is smaller than the first.
// Then, we going to compares the third element if is smaller then the others compared before.
int insertion_sort(int arr[], int length){
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move os elementos maiores que key para frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insere o elemento na posição correta
        arr[j + 1] = key;
    }
    return 0;
}

// The element compares itself for each number minus then next
// Swap the element in first position if the number is lower then the comparision
int selection_sort(int arr[], int length){
    for (int i = 0; i < length - 1; i++) {
        int min_idx = i;
        // Procura o menor elemento no restante do vetor
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        std::swap(arr[min_idx], arr[i]);
    }
    return 0;
}

// Bubble sort start with the first two numbers on array and compares if the left element is greater than right, then swap.
// If the the number of elements is N :: Proceedes to be (n-1) comparision
void bubble_sort(int arr[], int length){
    for (int i = 0; i < length; i++) { // Para cada elemento
        bool troca = false;
        for (int j = 0; j < length - 1; j++) { // Percorre até o ultimo não ordenado
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                troca = true;
            }
        }
        // Se não houve troca, o vetor já está ordenado
        if (!troca) break;
    }
}

// Função auxiliar para o merge do merge sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    // Junta os dois subvetores ordenados
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// o(n log n) -> n : number of items on array log n is the time of divide in the array.
// omega(n log n)
// Divide and conquer -> Parallel 
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Ordena a primeira metade
        merge_sort(arr, left, mid);
        // Ordena a segunda metade
        merge_sort(arr, mid + 1, right);
        // Junta as duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função auxiliar para o partition do quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Pivot need to be on -> had to be choosed the element less or equal than pivot creating the new list
// worst o(n^2)
// best o(n log n)
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o vetor e retorna o índice do pivô
        int pi = partition(arr, low, high);
        // Ordena os elementos antes e depois do pivô
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Função para imprimir o vetor
void print_array(int arr[], int length) {
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << "\t";
    std::cout << std::endl;
}

int main() {
    // Exemplo simples com vetor fixo
    int arr[9] = {24,12,40,22,18,27,16,19,16};
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << "Unsorted array";
    std::cout << std::endl;

    bubble_sort(arr, length);

    std::cout << "Array ordenado pelo bubble sort" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    // merge_sort(arr, 0, length - 1);

    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}

