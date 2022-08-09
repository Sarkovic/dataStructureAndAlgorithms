#include <bits/stdc++.h>

using namespace std;

int stck[10], n = 10, top = -1;

void push(int val)
{
    if (top + 1 >= n)
        cout << "Stack Overflow" << endl;
    else
    {
        stck[top + 1] = val;
        top++;
    }
}

void pop()
{
    if (top == -1)
        cout << "Stack Underflow" << endl;
    else
    {
        int val = stck[top];
        cout << val << endl;
        stck[top] = NULL;
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stck[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

int main()
{
    int ch, val;
    cout << "1. Push in the stack." << endl;
    cout << "2. Pop from the stack." << endl;
    cout << "3. Display the stack." << endl;
    cout << "4. Exit." << endl;
    while (ch != 4)
    {
        cout << "Enter Choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed: " << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            break;
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    }

    return 0;
}