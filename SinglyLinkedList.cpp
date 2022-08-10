#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

node* head = NULL;
node* tail = NULL;

node* createNode(int value){
    node* temp = (node *)malloc(sizeof(node));
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

node* searchNode(int value){
    for (node* i = head; i != NULL; i = i -> next)
    {
        if(i -> data == value)
            return i;
    }
}

void append(int value){
    if(head == NULL){
        head = createNode(value);
        tail = head;
    }
    else{
        node* temp = createNode(value);
        tail -> next = temp;
        tail = tail -> next;
    }
}

void printList(){
    node* temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

void countOfNodes(){
    int count = 0;
    node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    cout << count << endl;
}

void insertFirst(int value){
    node* temp = head;
    node* newNode = createNode(value);
    newNode -> next = temp;
    head = newNode;
}

void insertLast(int value){
    node* temp = head;
    node* newNode = createNode(value);
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void insertAfterCertainData(int insertafter, int value){
    node* temp = searchNode(insertafter);
    node* newNode = createNode(value);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void insertAnyPos(int value, int n){
    node* temp1 = (node *)malloc(sizeof(node));
    temp1 -> data = value;
    temp1 -> next = NULL;
    if(n == 1){
        temp1 -> next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
    
}

void deleteFirst(){
    node* temp = head;
    head = head -> next;
    free(temp);
}

void deleteLast(){
    node* temp = head;
    while (temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    
    node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    free(temp2);
}

void deleteAnyPos(int n){
    node* temp = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp -> next;
    }
    node* temp2 = temp -> next;
    temp -> next = temp2 -> next;
    free(temp2);
}

void reverse(){
    node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int main(){
    for (int i = 0; i <= 200; i+=50)
    {
        append(i);
    }

    printList();

    cout << endl;

    countOfNodes();

    insertLast(234);

    cout << endl;
    printList();

    cout << endl;
    insertFirst(75);

    cout << endl;
    printList();

    insertAfterCertainData(100, 45);

    cout << endl;
    printList();

    insertAnyPos(30, 3);

    cout << endl;
    printList();

    deleteFirst();
    cout << endl;
    printList();

    deleteLast();
    cout << endl;
    printList();

    deleteAnyPos(4);
    cout << endl;
    printList();

    reverse();
    cout << endl;
    printList();
    
    return 0;
}