#include <iostream>

using namespace std;

int partioning(int array[], int low, int high){
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if(array[j] < pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return i+1;
}

void quickSort(int array[], int low, int high){
    if(low < high){
        int pi = partioning(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi+1, high);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    printArray(A, n);
    quickSort(A, 0, n-1);
    cout << "Sorted Array: " << endl;
    printArray(A, n);

    return 0;
}