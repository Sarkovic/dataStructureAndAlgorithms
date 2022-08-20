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

int main(){
    int A[] = {11, 21, 32, 43, 54, 65, 76, 87, 98, 109};
    int n = sizeof(A) / sizeof(A[0]);
    int input;
    cin >> input;
    int resultIterative = binarySearchIterative(A, 10, input);
    cout << "Iterative:" << endl;
    if (resultIterative == -1)
    {
        cout << "Not Found" << endl;
    }
    else{
        cout << "Found at: " << resultIterative + 1 << endl;
    }

    int resultRecursive = binarySearchRecursive(A, 0, n-1, input);
    cout << "Recursive:" << endl;
    if (resultRecursive == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found at: " << resultRecursive + 1 << endl;
    
    return 0;
}