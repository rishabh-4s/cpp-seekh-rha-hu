// square the the elements of sorted array which includes negatinve integers

#include <iostream>
using namespace std;
#include <vector>

vector<int> foo(vector<int> arr)
{

    int n = arr.size();
    vector<int> ans(n, 0);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j)
    {
        if (abs(arr[i]) > abs(arr[j]))
        {
            ans[k] = arr[i] * arr[i];
            i++;
            k--;
        }
        else
        {
            ans[k] = arr[j] * arr[j];
            j--;
            k--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 7};
    arr = foo(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}