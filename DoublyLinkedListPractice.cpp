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

node* createNode(int value) {
    node* temp = (node *)malloc(sizeof(node));
    temp -> data = value;
    temp -> prev = NULL;
    temp -> next = NULL;

    return temp;
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

node* searchNode(int value){
    for (node* i = head; i != NULL; i = i -> next)
    {
        if(i -> data == value){
            return i;
        }
    }
}

void insertFirst(int value){
    Node* temp = createNode(value);
    if(head == NULL){
        head = temp;
        return;
    }
    head -> prev = temp;
    temp -> next = head;
    head = temp;
}

void insertLast(int value){
    Node* newNode = createNode(value);
    Node* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> prev = temp;
    newNode -> next = NULL;
}

void insertAfterCertainData(int insertAfter, int value){
    node* newNode = createNode(value);
    node* temp = searchNode(insertAfter);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void deleteFirst(){
    node* temp = head;
    head = head -> next;
    free(temp);
}

void deleteLast(){
    if(head != NULL){
        if(head -> next == NULL)
            head = NULL;
        else{
            node* temp = head;
            while (temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }
            node* lastNode = temp -> next;
            temp -> next = NULL;
            free(lastNode);
        }
    }
}

void deleteAfterCertainData(int deleteAfter){
    if (head != NULL)
    {
        node* temp = searchNode(deleteAfter);
        node* deleteNode = temp -> next;
        temp -> next = deleteNode -> next;
        free(deleteNode);
    }
    
}

void printList(){
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void printListReverse(){
    node* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> prev;
    }
    cout << endl;
}

int main() {
    for (int i = 10; i <= 50; i+=10)
    {
        append(i);
    }

    printList();

    insertLast(33464);
    printList();

    printListReverse();
    
    return 0;
}