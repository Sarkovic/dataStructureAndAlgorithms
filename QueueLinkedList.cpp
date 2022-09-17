#include <bits/stdc++.h>

using namespace std;

struct Queue
{
    int value;
    Queue* next;
    Queue* prev;
};

Queue* front = NULL;
Queue* rear = NULL;

typedef struct Queue Queue;

Queue* createQueue(int data) {
    Queue* newData = new Queue();
    newData -> value = data;
    newData -> next = newData -> prev = NULL;
    return newData;
}

bool isEmpty() {
    return front == NULL;
}

int length() {
    if(isEmpty())
        return 0;
    else {
        int counter = 0;
        Queue* temp = front;
        if(front -> next != NULL){
            counter++;
            temp = temp -> next;
        }
        return counter + 1;
    }
}

int Front(){
    if(front != NULL)
        return front -> value;
}

void enQueue(int data) {
    Queue* newData = createQueue(data);
    if(front == NULL && rear == NULL) {
        front = newData;
        rear = newData;
    }
    else {
        rear -> next = newData;
        rear = newData;
    }
}

void deQueue() {
    if(isEmpty())
        cout << "Queue is empty" << endl;
    else{
        Queue* dltFront = front;
        front = front -> next;
        cout << dltFront -> value << endl;
        delete(dltFront);
    }
}

int main() {
    enQueue(10);
    enQueue(12);
    enQueue(14);
    enQueue(11);
    enQueue(9);
    enQueue(14);
    deQueue();
    deQueue();
    enQueue(120);
    printf("Front element: %d\n", Front());
    deQueue();
    deQueue();
    deQueue();
    deQueue();

    if(isEmpty())
        printf("Queue is Empty.\n");
    else
        printf("Queue is not empty.\n");


    printf("Length of the Queue is: %d\n", length());
    
    return 0;
}