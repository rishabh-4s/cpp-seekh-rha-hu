#include <bits/stdc++.h>
using namespace std;

vector<int> foo(vector<int> arr)
{
    // int min = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            for (int j = arr.size() - 1; j > i; j--)
            {
                if (arr[j] > arr[i])
                {
                    swap(arr[j], arr[i]);
                    reverse(arr.begin() + i + 1, arr.end());
                    return arr;
                }
            }
        }
        if (i == 0)
            reverse(arr.begin(), arr.end());
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 2, 1};
    vector<int> res = foo(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}