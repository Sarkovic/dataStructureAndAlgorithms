#include <bits/stdc++.h>

using namespace std;

int main() {
    queue < int > q;
    q.push(5);
    q.push(34);
    q.push(44);
    q.push(36);
    q.push(45);

    cout << q.front() << endl;
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.back() << endl;
    


    return 0;
}