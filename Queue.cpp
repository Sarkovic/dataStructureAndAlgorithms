#include <bits/stdc++.h>
#define SIZE 10

using namespace std;

int Queue[SIZE], f = 0, r = 0;

void insrt(int val) {
    if(r == SIZE)
        cout << "Queue Overflow" << endl;
    else{
        Queue[r] = val;
        r = s;
    }
}

void dlt() {
    if(f == r){
        cout << "Queue Underflow" << endl;
    }
    else{
        f = (f + 1) % (m + 1);
        Queue[f] = NULL;
    }
}

int main(){
    for (int i = 0; i < 11; i++)
    {
        int input;
        cout << "Enter value:" << endl;
        cin >> input;
        insrt(input);
    }

    for(int i: Queue){
        cout << Queue[i] << " ";
    }
    
    

    return 0;
}