#include <bits/stdc++.h>
using namespace std;

int foo(vector<int> arr, int k)
{
    int count = 0;
    unordered_map<int, int> OurMap;
    int sum = 0;
    OurMap[sum]++;
    
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (OurMap.count(sum - k))
            count += OurMap[sum - k];
        OurMap[sum]++;
    }
    
    return count;
}


int main()
{
    vector<int> arr = {1, 2, 3};
    int k = 3;
    cout << foo(arr, k);
    return 0;
}