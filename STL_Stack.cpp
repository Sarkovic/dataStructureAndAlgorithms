#include <bits/stdc++.h>

using namespace std;

int main() {
    stack < int > st;
    st.push(10);
    st.push(12);
    st.push(15);
    st.push(20);

    while (st.empty() == false)
    {
        st.pop();
    }
    
    if(st.empty() == true)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    cout << st.size() << endl;


    return 0;
}
