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
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int A[size];

    cout << "Enter the values of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    int low = 0;
    int high = sizeof(A)/sizeof(A[0]);

    cout << "Before sorting: " << endl; 
    for(int x: A)
        cout << x << " ";
    cout << "" << endl;

    QuickSort(A, low, high);

    cout << "After sorting: " << endl;
    for(int x: A)
        cout << x << " ";
}