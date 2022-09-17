#include <bits/stdc++.h>

using namespace std;

int main() {
    vector < int > v;
    int n = 10;

    //Lambda expression
    /*Here, [&] indicates that all the variables are captured by reference.*/
    auto print = [&]()
    {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    };

    for (int i = 1; i < 10; i++)
    {
        int temp = rand()%100;
        v.push_back(temp);
    }

    cout << "Before sorting >> ";
    print();

    cout << "Sorting 1 >> ";
    sort(v.begin(), v.end());
    print();

    cout << "Reverse >> ";
    reverse(v.begin(), v.end());
    print();

    sort(v.begin(), v.end(), less< int >());

    cout << "After sorting >> ";
    print();
    

    return 0;
}