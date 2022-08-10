#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node node;

node* head = NULL;
node* tail = NULL;

node* createNode(int value){
    node* temp = (node *)malloc(sizeof(node));
    temp -> data = value;
    temp -> prev = NULL;
    temp -> next = NULL;

    return temp;
}

void insertAtHead(int value){
    node* temp = createNode(value);
    if(head == NULL){
        head = temp;
        return;
    }
    head -> prev = temp;
    temp -> next = head;
    head = temp;
}

void printList(){
    node* temp = head;
    cout << "Forward:" << endl;
    while (temp!=NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void printListReverse(){
    node* temp = head;

    //going to the last node
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    cout << "Reverse:" << endl;
    //traversing backward using prev pointer
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    cout << endl;
}

int main(){
    head = NULL;
    insertAtHead(45);
    insertAtHead(23);
    insertAtHead(67);
    printList();
    printListReverse();
    
    return 0;
}