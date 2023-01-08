#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // size function
    int size()
    {
        return nextIndex;
    }

    // empty function
    bool isEmpty()
    {
        return nextIndex == 0;
    }

    // insert function
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "stack overflow" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // delete function
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // returns the top element
    int top()
    {
        if (isEmpty())
        {
            cout << "stack underflow" << endl;
            return INT_MIN;
        }
        
        return data[nextIndex - 1];
        
    }

    //prints all the elements of the stack
    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<< endl;
        
    }

};



int main()
{

    StackUsingArray s(4);
    
    cout << s.isEmpty();

    return 0;
}