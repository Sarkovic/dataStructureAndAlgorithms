#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    int temp;

    while (i < j)
    {
       while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main(){
    int A[] = { 9, 14, 6, 1, 7, 11, 3, 5 };
    quickSort(A, 0, 7);
    for (size_t i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}