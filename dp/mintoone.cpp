#include <bits/stdc++.h>
using namespace std;

// brute force
int mintoone(int n)
{
    if (n <= 1)
        return 0;
    int x = mintoone(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = mintoone(n / 2);
    }
    if (n % 3 == 0)
    {
        z = mintoone(n / 3);
    }
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

// dp
int helper(int n, int* ans)
{
    if (n <= 1) return 0;
    
    if (ans[n] != -1) return ans[n];

    int x = helper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = helper(n / 2, ans);
    if (n % 3 == 0)
        z = helper(n / 3, ans);
    
    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return output;
    
}
int mindp(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return helper(n, ans);
}
int main()
{
    cout << mindp(7);
    return 0;
}