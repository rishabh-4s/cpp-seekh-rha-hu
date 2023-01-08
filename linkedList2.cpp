#include <bits/stdc++.h>
#include "node.h"
using namespace std;

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

int midpoint(node *head)
{
    node* slow = head;
    node* fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //if (fast->next->next == NULL) break;
    }
    return slow->data;
}

// node* merge(node* head1, node* head2)
// {
//     node* temp1 = head1;
//     node* temp2 = head2;
//     while (temp1 && temp2)
//     {
//         if (temp1->data <= temp2->data)
//         {
//             node* curr = temp1->next;
//             temp1->next = temp2;
//             temp2->next = curr;
//         }
//         else
//         {

//         }
//     }

// }
node* merge(node* head1, node* head2)
{
    if(!head1) return head2;
    if(!head2) return head1;

    if (head1->data < head2->data)
    {
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

node* merge2(node *head1, node* head2)
{
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data > head2->data)
    {
        node*temp = head1;
        head1 = head2;
        head2 = temp;
    }
    while (head1 && head2)
    {
        node* temp = null;
        while (l1->data < temp->data)
        {
            /* code */
        }
        
    }
    
}

int main()
{
    node* head = takeInput_Better();
    cout << midpoint(head);
    return 0;
}