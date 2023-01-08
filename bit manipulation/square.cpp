#include <bits/stdc++.h>
using namespace std;

long long square(long long n)
{
    // long long ans = 0;
    // long long temp = n;
    // //cout << temp << endl;
    // for (int i = 31; i >= 0; i--)
    // {   
    //     cout << (1<<i) << " " << temp << endl;
    //     if (1<<i <= temp)
    //     {
    //         cout << i << endl;
    //         ans += n<<i;
    //         temp -= 1<<i;
    //     }
    //     return ans;

    // }
    int ans = 0;
    int x = n;
    int i = 0;
    while (x)
    {
        if (x & 1)
        {
            ans += n<<i;
            x >>= 1;
            i++;
        }
        return ans;
    }
    
    
}

int main()
{
    cout << square(10);
    //cout << endl;
    //cout << (1<<32);
    return 0;
}