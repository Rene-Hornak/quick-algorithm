#include <stdio.h>

void swap(int* a, int* b) {
    int temporary = *a;
    *a = *b;
    *b = temporary;
}

int partition(int array[], int low, int high) {
     int pivot = array[high];
     int i = low - 1;

     for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
     }
     swap(&array[i + 1], &array[high]);
     return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(array, low, high);
        
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

int main() {
    int array[] = {12, 50, 45, 84, 97, 150, 166, 0, -51, -84, 5};
    int arrayLength = sizeof(array) / sizeof(array[0]);

    printf("Array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%i ",array[i]);
    }
    printf("\n");

    quickSort(array, 0, arrayLength - 1);
    
    printf("Sorted array: ");
    for (int i = 0; i < arrayLength; i++) {
        printf("%i ",array[i]);
    }
    printf("\n");

    return 0;
}