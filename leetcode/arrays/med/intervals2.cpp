#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> foo()
{
    vector<vector<int>> intervals;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(2);
        cin >> temp[0] >> temp[1];
        intervals.push_back(temp);

    }
    
     
    vector<vector<int>> res;
    
    sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <=  res[res.size() - 1][1])
        {
            res[res.size()-1][1] = max(intervals[i][1], res[res.size() - 1][1]); 
        }
        else
        {
            res.push_back(intervals[i]);
        }

    }
    return res;

    
    
}

int main()
{
    vector<vector<int>>res = foo();
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1];
        cout << endl;
    }

}