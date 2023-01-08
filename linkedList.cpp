#include <iostream>
#include "node.h"

using namespace std;

// data input jab -1 hoga tab input rok denge
node *takeInput()
{
    int data;
    cin >> data;       // element input liya
    node *head = NULL; // initialize LL in

    while (data != -1)
    {
        node *newNode = new node(data);
        // agar first element he diya hai toh usko head mein daal denge
        if (head == NULL)
        {
            head = newNode;
        }
        //
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cin >> data;
    }
    return head;
}

node *takeInput_Better()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}


node *insertNode(node *head, int i, int data)
{
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;

    if (i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}

node *deleteNode(node *head, int i)
{
    int count = 0;
    node *temp = head;

    if (i == 0)
    {
        return head = temp->next;
        delete temp;
    }
    else
    {
        while (temp != NULL && count < i - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
        {
            node *a = temp->next;
            node *b = a->next;
            temp->next = b;

            delete a;
        }
    }
    return head;
}

int lengthOfLL(node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + lengthOfLL(head = head->next);
    }
}

node *insertRecursive(node *head, int i, int data)
{

    node *newNode = new node(data);
    node *temp = head;
    if (i == 0 || temp == NULL)
    {
        newNode->next = temp;
        temp = newNode;
        return temp;
    }
    else
    {
        temp->next = (insertRecursive(temp->next, i - 1, data));
    }
}

node *deleteRecursive(node *head, int i)
{
    node *temp = head;
    if (i == 0 || temp == NULL)
    {
        return temp->next;
        delete temp;
    }
    else
    {
        temp->next = deleteRecursive(temp->next, i - 1);
    }
}

int findIndex(node *head, int data)
{
    int count = 0;
    node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return count;
        }

        temp = temp->next;
        count++;
    }
}

node *appendToFirst(node *head, int n)
{
    int len = lengthOfLL(head);
    int count = -n;
    node *temp = head;
    node *t = head;
    while (temp->next != NULL)
    {
        if (count >= 0)
        {
            t = t->next;
        }
        temp = temp->next;
        count++;
    }
    // tail to head
    temp->next = head;
    //new node
    head = t->next;
    
    t->next = NULL;
    return head;
}

node* deleteDuplicates(node*head){
    node*temp = head;
    node* nextKaNext;
    while(temp->next != NULL){
        if (temp->data == temp->next->data){
            nextKaNext = temp->next->next;
            delete temp->next;
            temp->next = nextKaNext;
        }
        else{
        temp = temp->next;
        }
    }
    return head;
}

void printReversedLL(node* head){
    node *temp = head;
    if (temp == NULL)
        return;
    printReversedLL(temp->next);

    cout << temp->data << " ";
}


void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    /*
    node n1(1);
    node *head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    
    
    node *head = takeInput_Better();

    print(head);
    int i;
    cin >> i;
    head = deleteNode(head, i);
    print(head);
    
    
    node *head = takeInput_Better();
    print(head);
    int i, data;
    cin >> i >> data;
    //head = insertNode(head, i, data);
    head = insert(head, i, data);
    print(head);
    */
    node *head = takeInput_Better();
    print(head);
    int i, data;
    //cin >> i;
    //head = deleteRecursive(head, i);
    //print(head);
    //cout << findIndex(head, 3);
    //head = appendToFirst(head, 4);
    //print(head);
    printReversedLL(head);

    return 0;
}
