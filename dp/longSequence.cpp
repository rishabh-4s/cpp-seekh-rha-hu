#include <bits/stdc++.h>
using namespace std;

int longu(int arr[], int n)
{
    int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
                continue;
            int possibleAns = dp[j] + 1;
            if (possibleAns > dp[i])
                dp[i] = possibleAns;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    
    
}

int main()
{
    int arr[6] = {5, 4, 11, 1, 16, 8};
    cout << longu(arr, 6);
    return 0;
}