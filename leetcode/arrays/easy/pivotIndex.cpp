#include <iostream>
#include <vector>
using namespace std;

int foo(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        
    }
    //cout << sum << endl;
    
    int curr_sum = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        curr_sum += arr[i];
        //cout << curr_sum << endl;
        if (curr_sum == (sum - arr[i+1] - curr_sum))
            return i + 1;
        
        //else if (curr_sum > (sum - arr[i+1] - curr_sum))
            //return -1;
        

    }
    if (sum - arr[0] == 0)
        return 0;
    if (sum - arr[arr.size() - 1] == 0)
        return arr.size() - 1;
    return -1;
    
    
}

int main()
{
    vector<int> arr = {-1,-1,0,1,1,-1};
    
    
    int j  = foo(arr);
    cout << j;
    
}