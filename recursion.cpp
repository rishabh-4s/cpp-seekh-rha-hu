#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int pwrn(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * pwrn(x, n - 1);
}

void print(int n)
{
    if (n == 0)
    {
        return;
    }
    print(n - 1);
    cout << n << " ";
}

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

bool checkSort(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }
    return checkSort(a + 1, n - 1);
}

int sumOfArr(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sumOfArr(a, n - 1) + a[n - 1];
}

bool checkNum(int a[], int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (a[0] == x)
    {
        return true;
    }
    else
    {
        checkNum(a + 1, n - 1, x);
    }
}

int firstIndex(int a[], int n, int x)
{

    if (n == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }
    else
    {
        return 1 + firstIndex(a + 1, n - 1, x);
    }
}

int lastIndex(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (a[n] == x)
    {
        return n;
    }
    else
    {
        return lastIndex(a, n - 1, x);
    }
}

int allIndex(int a[], int n, int x, int output[])
{

    if (n == 0)
    {
        return 0;
    }
    int ans = allIndex(a + 1, n - 1, x, output);

    if (a[0] == x)
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            output[i + 1] = output[i] + 1;
        }
        output[0] = 0;
        ans++;
    }
    else
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            output[i] = output[i] + 1;
        }
    }
    return ans;
}
void AllIndexes(int input[], int n, int x)
{
    int output[n];
    int size = allIndex(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
}