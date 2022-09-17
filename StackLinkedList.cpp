#include <bits/stdc++.h>

using namespace std;

struct Stack
{
    int value;
    Stack* next;
    Stack* prev;
};

Stack* top;
Stack* bottom;

typedef struct Stack Stack;

Stack* createStack(int data) {
    Stack* newData = new Stack();
    newData -> value = data;
    newData -> next = newData -> prev = NULL;
    return newData;
}

bool isEmpty() {
    return top == NULL;
}

int Top() {
    int topElement = 0;
    if(bottom != NULL){
        topElement = bottom -> value;
    }
    return topElement;
}

void push(int data) {
    if(top == NULL){
        top = createStack(data);
        bottom = top;
    }
    else {
        Stack* newData = createStack(data);
        bottom -> next = newData;
        newData -> prev = bottom;
        bottom = newData;
        newData = NULL;
    }
}

void pop()
{
    if(bottom == NULL) {
        cout << "Stack Underflow" << endl;
        return;
    }
    if(top == bottom){
        top = bottom = NULL;
        return;
    }
    Stack* dltData = bottom;
    bottom = bottom -> prev;
    bottom -> next = NULL;
    delete(dltData);
}


int main() {
    push(10);
    push(12);
    push(14);
    push(11);
    push(9);
    push(14);
    pop();
    pop();
    push(120);
    printf("Top element: %d\n", Top());
    pop();
    pop();
    pop();
    pop();
    pop();

    if(isEmpty())
        printf("Stack is Empty.\n");
    else
        printf("Stack is not empty.\n");
    
    return 0;
}
