#include <iostream>

using namespace std;

int partition(int array[], int l, int h){
    int pivot = array[l];
    int i = l;
    int j = h;

    while(i < j){
        do
        {
            i++;
        } while (array[i] <= pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        if (i < j)
        {
            swap(array[i], array[j]);
        }
    }
    swap(array[l], array[j]);
    return j;
}

void QuickSort(int array[], int l, int h){
    int j;
    if (l < h)
    {
        j = partition(array, l, h);
        QuickSort(array, l, j);
        QuickSort(array, j+1, h);
    }
}

int main() {
    int A[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 4};
    int low = 0;
    int high = sizeof(A)/sizeof(A[0]);
    QuickSort(A, low, high);

    for(int x: A)
        cout << x << " ";
}