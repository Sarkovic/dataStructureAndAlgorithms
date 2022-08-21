#include <bits/stdc++.h>

using namespace std;

int binarySearchIterative(int arr[], int size, int key){
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(int arr[], int low, int high, int key){
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            return binarySearchRecursive(arr, mid+1, high, key);
        else
            return binarySearchRecursive(arr, low, mid-1, key);
    }
    return -1;
}

int linearSearch(int arr[], int n, int key){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int maximum(int arr[], int size){
    int maxElement = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

void countingSort(int arr[], int size){
    int max = maximum(arr, size);
    int arr2[max + 1] = {0};
    int arr3[size + 1];
    for (int i = 0; i < size; i++)
    {
        arr2[arr[i]]++;
    }
    for (int i = 1; i < max+1; i++)
    {
        arr2[i] += arr2[i-1];

    }
    for (int i = size-1; i >= 0; i--)
    {
        arr3[arr2[arr[i]] - 1] = arr[i];
        arr2[arr[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr3[i];
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
           if(arr[j] > arr[j+1]){
            swap(arr[j], arr[j+1]);
           }
        }
    }
    return;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        int minin = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[minin])
                minin = j;
        }
        swap(arr[i], arr[minin]);
    }
    return;
}

int main(){
    int A[] = {5, 6, 2, 4, 11, 8, 6, 3};
    int B[] = {34, 12, 4, 67, 33, 232, 34};
    int C[] = {54, 23, 65, 6, 21, 56, 93, 23};
    int nB = sizeof(B)/sizeof(B[0]);
    int n = sizeof(A)/sizeof(A[0]);
    int nC = sizeof(C)/sizeof(C[0]);
    countingSort(A, n);

    for(int i: A){
        cout << i << endl;
    } 

    bubbleSort(B, nB);
    for(int i: B){
        cout << i << endl;
    }

    selectionSort(C, nC);
    for(int i: C){
        cout << i << endl;
    }
    
    return 0;
}