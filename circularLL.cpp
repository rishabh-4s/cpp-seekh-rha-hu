#include "node.h"
#include <iostream>
using namespace std;

void print(node* head)
{
    node* temp = head;
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}