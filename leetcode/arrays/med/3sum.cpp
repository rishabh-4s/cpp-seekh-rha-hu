#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums)
{
    vector<vector<int>> res;
    unordered_map<int, int> ourmap;
    for (int i = 0; i < nums.size(); i++)
    {
        ourmap[nums[i]]++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i];
        for (int j = 0; j < nums.size(); j++)
        {

            if (nums[j] != x)
            {
                int y = nums[j];
                if (ourmap[0 - x - y])
                {
                    vector<int> temp{x, y, 0 - x - y};
                    ourmap[0 - x - y]--;
                }
            }
            else
                continue;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(arr);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}