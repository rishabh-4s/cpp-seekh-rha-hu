#include <iostream>
#include "node.h"
#include <unordered_map>
using namespace std;

node* find(node* headA, node* headB)
{
    unordered_map<node*, int> map;
    node* tempA = headA->next;
    node* tempB = headB->next;

    while (tempA && tempB)
    {
        map[tempA]++;
        map[tempB]++;
        if (map[tempA] == 2)
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;

    }
    return NULL;
    
}

node* findy(node* headA, node* headB)
{
    node* tempA = headA;
    node* tempB = headB;
    int c1 = 0, c2 = 0;
    while (tempA)
    {
        c1++;
        tempA = tempA->next;
    }
    while (tempB)
    {
        c2++;
        tempB = tempB->next;
    }
    int diff;
    tempA = headA;
    tempB = headB;
    if (c2 >= c1)
    {
        diff = c2 - c1;
        for (int i = 0; i < diff; i++)
        {
            tempB = tempB->next;
        }
        
        
    }
    else
    {
        diff = c1 - c2;
        for (int i = 0; i < diff; i++)
        {
            tempA = tempA -> next;
        }
        
    }
    while (tempA && tempB)
    {
        if (tempA == tempB)
            return tempA;

        tempA = tempA->next;
        tempB = tempB->next;
    }
    
    
    
}