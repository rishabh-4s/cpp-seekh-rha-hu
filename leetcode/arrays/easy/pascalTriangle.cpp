#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> foo(int n)
{
    vector<vector<int>> res;
    vector<int> curr = {1};
    res.push_back(curr);

    for (int i = 2; i < n + 1; i++)
    {

        if (i == 2)
        {
            curr = {1, 1};
            res.push_back(curr);
            continue;
        }
        vector<int> neww;
        for (int j = 0; j < i - 2; j++)
        {
            int x = curr[j] + curr[j + 1];
            neww.push_back(x);
        }
        
        neww.insert(neww.begin(), 1);
        neww.push_back(1);
        res.push_back(neww);
        curr = neww;
    }
    return res;
}

int main()
{
    vector<vector<int>> hi = foo(4);
    for (int i = 0; i < hi.size(); i++)
    {
        for (int j = 0; j < hi[i].size(); j++)
        {
            cout<< hi[i][j] << " ";
        }
        cout << "|" << " ";
        
    }
    
}