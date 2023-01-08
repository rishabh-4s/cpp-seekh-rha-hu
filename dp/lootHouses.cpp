#include <bits/stdc++.h>
using namespace std;

int loot(int arr[], int n)
{
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1] ); // first case when element included, i -1 wala case jab include nhi kiya
    }
    return dp[n - 1];

}

int main()
{
    int *arr = new int[6]{5 ,5 ,10 ,100 ,10 ,5};
    cout << loot(arr, 6);
    return 0;
}