#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value){
    //Node* temp = (Node *)malloc(sizeof(Node));
    Node* temp = new Node;
    temp -> data = value;
    temp -> next = NULL;
    return temp;
}

void append(int value){
    if (head == NULL)
    {
        head = createNode(value);
        tail = head;
    }
    else{
        Node* temp = createNode(value);
        tail -> next = temp;
        tail = tail -> next;
    }
}

// void display(struct Node *p){
//     while (p!=NULL)
//     {
//         printf("%d ", p->data);
//         p = p -> next;
//     }
//     printf("\n");
// }

void printList()
{
    for(Node* temp = head; temp!=NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main(){
    for (int i = 1; i <= 100; i++)
    {
        append(i);
    }
    
    printList();

    return 0;
}
