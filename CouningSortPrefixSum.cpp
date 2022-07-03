#include <iostream>

using namespace std;

int maxElement(int arr[], int n) {
    int maxNum = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (maxNum < arr[i])
            maxNum = arr[i];
    }
    return maxNum;
}

void countingSort(int arr[], int n) {
    int maximum = maxElement(arr, n);
    int arr2[maximum + 1] = {0};
    int arr3[n + 1];
    

    for (int i = 0; i < n; i++)
    {
        arr2[arr[i]]++;
    }

    for (int i = 1; i < maximum+1; i++)
    {
        arr2[i] += arr2[i-1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        arr3[arr2[arr[i]] - 1] = arr[i];
        arr2[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = arr3[i];
    }
}

int main() {
    int arr[] = {1, 4, 6, 2, 6, 8, 9, 11, 3, 4, 1, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}