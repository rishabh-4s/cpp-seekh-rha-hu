#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = INT_MAX;
        for (int j = 1; (i - (j*j)) >= 0; j++)
        {
            arr[i] = min(arr[i], arr[i - (j*j)]);
        }
        arr[i]++;
    }
    return arr[n];
    
}

int main()
{
    cout << minCount(3);
    return 0;
}