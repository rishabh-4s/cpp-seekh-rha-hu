#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> overlap(vector<vector<int>> intervals)
{
    sort(intervals.begin(), intervals.end());
    if (intervals.size() == 1)
        return intervals;
    vector<vector<int>> res;
    int i = 0;
    stack<int> hello;
    hello.push(intervals[i][0]);
    hello.push(intervals[i][1]);
    //hello.push(intervals[0][0]);
    while (i < intervals.size() - 1)
    {
        /*
        if (intervals[i][0] > intervals[i+1][0])
        {
            continue;
            i++;
        }
        */
        if (intervals[i][0] < intervals[i+1][0] && intervals[i][1] > intervals[i+1][1])
        {
            i++;
        }
        if (intervals[i][1] < intervals[i+1][0])
        {
            
            hello.push(intervals[i+1][0]);
            hello.push(intervals[i+1][1]);
        }
        else if (intervals[i][1] >= intervals[i+1][0])
        {
            hello.pop();
            hello.push(intervals[i+1][1]);
        }
        else if (intervals[i][0] < intervals[i+1][0] && intervals[i][1] > intervals[i+1][1])
        {
            while(!(intervals[i][0] < intervals[i+1][0] && intervals[i][1] > intervals[i+1][1]))
            {hello.pop();
            hello.pop();
            hello.push(intervals[i+1][0]);
            hello.push(intervals[i+1][1]);
            }

        }
        i++;
    }
    while (!hello.empty())
    {
        int y = hello.top();
        hello.pop();
        vector<int> curr = {hello.top(), y};
        res.insert(res.begin(), curr);
        hello.pop();

    }
    
    return res;
}

int main()
{
    vector<vector<int>> arr {{1,4}, {0,4}};
    vector<vector<int>> res = overlap(arr);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " " << res[i][1];
        cout << endl;
    }
    
}