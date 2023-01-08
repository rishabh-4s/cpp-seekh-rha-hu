#include <bits/stdc++.h>
using namespace std;

int ways(int n, int arr[], int v)
{
    int *dp = new int[v + 1];
    dp[0] = 0;
    for (int i = 1; i < arr[0]; i++)
    {
        
        dp[i] = 0;
        
    }
    dp[arr[0]] = 1;
    for (int i = arr[0]; i < v + 1; i++)
    {
        /* code */
    }
    
}

int main()
{

    return 0;
}