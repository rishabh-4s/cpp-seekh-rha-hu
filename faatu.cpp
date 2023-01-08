#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

node* takeinput()
{
    int data;
    cin>>data;
    node *head=NULL;
    node *tail=NULL;
    while(data!=-1)
    {   
        node * newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
    
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
    cin>>data;
    } 
    return head;
}
node *merge(node *h1,node *h2)
{
    node *finalhead=NULL;
    node *finaltail=NULL;

    if(h1->data>h2->data)
    {
        finalhead=h2;
        finaltail=h2;
        h2=h2->next;
    }
    else
    {   
        finalhead=h1;
        finaltail=h1;
        h1=h1->next;
    }

    while(h1!=NULL&&h2!=NULL)
    {
         if(h1->data>h2->data)
         {
            finaltail->next=h2;
            finaltail=h2;
            h2=h2->next;
         }

        if(h2->data>h1->data)
         {
           finaltail->next=h1;
           finaltail=h1;
           h1=h1->next;
         }
    }

    if(h2!=NULL)
    {
        finaltail->next=h2;
        finaltail=h2;
          
    }

    else
    {
        {
        finaltail->next=h1;
        finaltail=h1; 
        }
    }
    return finalhead;
}
void print(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    } 
}
int main()
{
    node *h1=takeinput();
    node *h2=takeinput();
    node *h3=merge(h1,h2);
    print(h3);
}