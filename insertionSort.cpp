#include <iostream>

using namespace std;

int main(){
    int a[] = {10, 8, 7, 5};
    int N = sizeof(a) / sizeof(int);

    for (int j = 1; j < N; j++)
    {
        int i = j - 1;
        int key = a[j];

<<<<<<< HEAD
        while (i >= 0 && a[i] > key)
=======
        while (i >= 0 && a[i] > key) //a[i] < key for descending order
>>>>>>> 4d431da8ea787b9e6fb6905abc021a88913706bf
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }

    for(int i = 0; i < N; i++)
        cout << a[i] << endl;
    

    return 0;
}
