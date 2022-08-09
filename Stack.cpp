/*Stack is LIFO (Last In, First Out) data structure.
It has two main properties, "push()" to input value in
the Stack and "pop()" to remove/output the  value in
the stack*/
#include <bits/stdc++.h>

using namespace std;

int stck[10], n = 10, top = -1; //when stack is empty top value starts from -1

void push(int val)
{
    if (top + 1 >= n)
        cout << "Stack Overflow" << endl;
    else
    {
        stck[top + 1] = val;
        top++; //increment the top value
        /* -1 + 1 = 0, stack[0] = input, top = 0
        0 + 1 = 1, stack[1] = input, top = 1
        1 + 1 = 2, stack[2] = input, top = 2 
        ....................................
        top+1 = top+1, stack[top+1] = input
        if top+1 reaches the capacity of the stack
        it prints "Stack Overflow"*/
    }
}

void pop()
{
    if (top == -1) //when stack is empty top value starts from -1
        cout << "Stack Underflow" << endl;
    else
    {
        int val = stck[top];
        cout << val << endl;
        stck[top] = NULL;
        top--; //decrement the top value
    }
}

void display()
{
    if (top >= 0) //stack starts putting value from 0 position
    {
        for (int i = top; i >= 0; i--) 
        /*As stack is a LIFO structure, 
        we start iterating from the top*/
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