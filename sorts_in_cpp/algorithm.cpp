#include <bits/stdc++.h>



int insertion_sort(int arr[], int lenght){
// Start with the second element and compares if itself is smaller than the first.
// Then, we going to compares the third element if is smaller then the others compared before.
return 0;
}

// Big datas is not the best, but the smaller numbers or datas.


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





//
//
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

// Worst algorithm in the perfomance ?? Just to teach :) KKKKKKKKKKKKKK incrivel isso
//
// worst case o(n^2)
// best case o(n)
}

void merge_sort(int arr[], int left, int right,){

// o(n log n) -> n : number of items on array log n is the time of divide in the array.
// omega(n log n)




// Divide and conquer -> Parallel 

}

int quick_sort(int arr[], int lenght){
return 0;

// Pivot need to be on -> had to be choosed the element less or equal than pivot creating the new list
//
// worst o(n^2)
// best o(n log n)
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

 // merge_sort(arr, lenght);

for (int i = 0; i < lenght; i++){
    std::cout << arr[i] << "\t";    
}
std::cout << std::endl;

return 0;
}
