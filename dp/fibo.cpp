#include <bits/stdc++.h>
using namespace std;
int dp[1000];
// recursive

int fib(int n)
{
    if (n <= 2) return 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}
// dp
int fibdp(int n)
{
    // bottom up

    int fibo[n + 2]; // n+2 to handle extra case of n = 0
    fibo[0] = 1;
    fibo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    return fibo[n];
    
}
int main()
{
    cout << fibdp(5);
    return 0;
}