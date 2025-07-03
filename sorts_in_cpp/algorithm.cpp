#include <bits/stdc++.h>

int insertion_sort(int arr[], int lenght){
// Start with the second element and compares if itself is smaller than the first.
// Then, we going to compares the third element if is smaller then the others compared before.
return 0;
}

int selection_sort(int arr[], int lenght){
// The element compares itself for each number minus then next
// Swap the element in first position if the number is lower then the comparision
// 5 2 4 20 15 30
// 5 > 2 ? V
// 2 5 4 20 15 30
// 2 > 4? X
// 2 > 20 ? X ... 30
// 2 5 > 4? V
// 2 4 5 20 15 30... 
return 0;
}

void bubble_sort(int arr[], int lenght){
// Bubble sort start with the first two numbers on array and compares if the left element is greater than right, then swap.
// If the the number of elements is N :: Proceedes to be (n-1) comparision
     for (int i =0; i < lenght; i++){ // Para cada elemento
       bool troca = true;
         for (int j =0; j < lenght - 1; j++){ // Percorre até o ultimo não ordenado, já que o ultimo é o maior
            if (arr[j] > arr[j +1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
        if(!troca) break;
     }


}

int merge_sort(int arr[], int lenght){return 0;}

int quick_sort(int arr[], int lenght){
return 0;
}

int main(){ 

int arr[9] = {24,12,40,22,18,27,16,19,16}; 
int lenght = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < lenght; i++){
    std::cout << arr[i] <<"\t";
}
    std::cout << "Unsorted array";
    std::cout << std::endl;

bubble_sort(arr,lenght);

std::cout << "Array ordenado pelo bubble sort" << std::endl;
for (int i = 0; i < lenght; i++){
    std::cout << arr[i] << "\t";
}
std::cout << std::endl;

return 0;
}
