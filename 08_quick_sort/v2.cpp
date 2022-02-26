// This program implements quick-sort in C++
#include <iostream>
#include <stdlib.h>

using namespace std;

// Swaps the contents the contents of two pointers
// 交换函数
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Create a sub-array for elements "<=" and ">" the pivot(枢纽)
// Takes an array, left index, and pivot index as arguments
// partition(划分,隔开)
int partition(int *array, int left, int pivot){
    // Start with a sub-array that is empty
    int low = left - 1;

    // Compare all numbers before the pivot
    int high = pivot - 1;

    // Go over all elements in sub-array
    for(int j = left; j <= high; j++){
        // Does this element go in the "<=" sub-array?
        if(array[j] <= array[pivot]){
            // Move over marker of sub-array
            low++;
            // Swap the element into position
            swap(&array[low], &array[j]);
        }
    }
    // Move the pivot into the correct position
    swap(&array[low + 1], &array[pivot]);

    // Return the index of the element in the correct place
    return low + 1;
}

// Recursive function that partitions the array into "<="/">"
// sub-arrays, and calls quicksort on them

void quicksort(int *array, int left, int pivot){
    // Recursively called until only a single element left
    if(left < pivot){
        // Partition the array into "<="/">" sub-arrays
        int new_pivot = partition(array, left, pivot);

        // Sort the sub-arrays via recursive calls
        // Sort the "<=" sub-array
        quicksort(array, left, new_pivot - 1);
        // Sort the ">" sub-array
        quicksort(array, new_pivot + 1, pivot);
    }
}

int main(){
    // Number of elements to sort
    int n = 10;

    // Set the random number seed
    srand(1);

    // Create an array of random numbers
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        array[i] = rand() % 100;
    }

    // Print out the unsorted array
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    // Sort the array using quicksort
    // 数组，头， 尾
    quicksort(array, 0, n-1);

    // Print out the sorted array
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

