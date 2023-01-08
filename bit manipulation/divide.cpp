#include <bits/stdc++.h>
using namespace std;

long long divide(long long dividend, long long divisor)
{
    // checking the sign of the divison
    // xor lga liya
    int sign  = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    
    dividend = abs(dividend);
    divisor = abs(divisor);
    
    // ans is our quotient
    // checking the max power of two ko divisor se multiply kr sake
    // voh nikal ke bache hue dividend saath firse vahi krna hai
    long long  ans = 0;
    for (int i = 32; i >= 0; i--)
    {
        if (divisor<<i <= dividend)
        {
            
            dividend -= divisor<<i;
            ans += 1<<i;
        }
    }

    // giving sign to the quotient
    if (sign == -1) ans = -ans;
    return ans;
}

int main()
{
    cout << divide(10, 3);
    return 0;
}