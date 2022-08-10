#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int value;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* head = NULL;
ListNode* tail = NULL;

ListNode* createNode(int data){
    ListNode* temp = new ListNode();
    temp -> value = data;
    temp -> next = NULL;
    return temp;
}

void add(int data)
{
    if(head == NULL)
    {
        head = createNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createNode(data);
        tail -> next = temp;
        tail = tail -> next;
    }
}

void printList(){
    for(ListNode* i = head; i != NULL; i = i -> next)
        cout << i -> value << " ";
    cout << "\n";
}

ListNode* Search(int data){
    for(ListNode* i = head; i != NULL; i = i->next)
    {
        if(i -> value == data)
            return i;
    }
}

void deleteFirst(){
    ListNode* temp = head;
    head = head -> next;
    free(temp);
}

void deleteMiddle(int position){
    ListNode* temp = Search(position);
    temp -> next = temp -> next -> next;
}

void deleteLast(){
    if(head != NULL){
        if(head -> next == NULL){
            head = NULL;
        }
        else
        {
            ListNode* temp = head;
            while(temp->next->next != NULL){
                temp = temp -> next;
            }
            ListNode* lastData = new ListNode();
            lastData = temp -> next;
            temp -> next = NULL;

            free(lastData);
        }
    }

}

void InsertMiddle(int data, int insertAfter)
{
    ListNode* prevNode = Search(insertAfter);
    ListNode* temp = createNode(data);
    temp -> next = prevNode -> next;
    prevNode -> next = temp;
    temp = NULL;
}

void InsertFirst(int data){
    ListNode* newHead = new ListNode();
    newHead -> value = data;
    newHead -> next = head;
    head = newHead;
}

void InsertLast(int data){
    ListNode* newLast = createNode(data);
    ListNode* temp = head;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newLast;
}

int main(){
    for(int i=1;i <= 10;i++)
    {
        add(i);
    }
    printList();

    InsertFirst(12);

    printList();

    InsertMiddle(67, 9);

    printList();

    InsertLast(45);

    printList();

    deleteFirst();

    printList();

    deleteMiddle(5);

    printList();

    deleteLast();

    printList();

    return 0;
}
