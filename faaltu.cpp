#include <iostream>
using namespace std;
class zehrDedo
{
private:
    int *arr;
    int top1;
    int top2;
    int capacity;

public:
    zehrDedo(int size)
    {
        capacity = size;
        arr = new int[size];
        top1 = 0;
        top2 = capacity - 1;
    }

    void push1(int data)
    {
        if (top1 >= top2)
            cout << "stack overflow" << endl;

        arr[top1] = data;
        top1++;
    }
    void push2(int data)
    {
        if (top1 >= top2)
            cout << "stack overflow" << endl;
        arr[top2] = data;
        top2--;
    }
    void pop1()
    {
        if (top1 == 0)
            cout << "stack underflow" << endl;
        else
            top1--;
    }
    void pop2()
    {
        if (top2 == capacity - 1)
            cout << "stack underflow" << endl;

        else
            top2++;
    }
};