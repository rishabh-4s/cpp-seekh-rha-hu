#include <iostream>
using namespace std;

class node
{   
    public:
    int data;
    node* next;
    node* prev;

    
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

node* insertAtStart(int element, node* head)
{
    
    node* newNode = new node(element);
    if (head == NULL)
        return newNode;
    newNode->next = head;
    head->prev = newNode;  
    head = newNode;
    return head;
    
}

void insertAfter(int data, node* prevNode)
{
    if (prevNode == NULL)   
        return;
    
    node* newNode = new node(data);

    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void print(node*head )
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

int main()
{
    node* head = NULL;
    head = insertAtStart(1, head);
    //print(head);
    head = insertAtStart(2, head);
    head = insertAtStart(3, head);
    head = insertAtStart(4, head);
    print(head);
}

