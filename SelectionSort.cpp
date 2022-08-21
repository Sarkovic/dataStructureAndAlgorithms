#include <bits/stdc++.h>

using namespace std;

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
    int C[] = {54, 23, 65, 6, 21, 56, 93, 23};
    int nC = sizeof(C)/sizeof(C[0]);
    selectionSort(C, nC);
    for(int i: C){
        cout << i << endl;
    }
    
    return 0;
}